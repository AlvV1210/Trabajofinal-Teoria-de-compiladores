#include "RecipeCodegenVisitor.h"
#include <sstream>

using namespace llvm;

// Quita comillas de STRING
static std::string stripQuotes(const std::string &s) {
    if (s.size() >= 2 && s.front() == '"' && s.back() == '"')
        return s.substr(1, s.size() - 2);
    return s;
}

RecipeCodegenVisitor::RecipeCodegenVisitor()
    : builder(context) {
    module = std::make_unique<Module>("recipe_module", context);
}

// =====================================================
// Helper: crear string global y devolver i8* (char*)
// usando CreateGlobalString + GEP (compatible con LLVM 22)
// =====================================================
Value *RecipeCodegenVisitor::makeString(const std::string &s, const std::string &name) {
    // crea GlobalVariable de tipo [N x i8]
    GlobalVariable *g = builder.CreateGlobalString(s, name, 0, module.get());
    // índices 0,0 para apuntar al primer char
    Value *zero = builder.getInt32(0);
    Value *indices[] = { zero, zero };
    return builder.CreateInBoundsGEP(g->getValueType(), g, indices, name + "_ptr");
}

// =====================================================
// Helper: wrapper para printf
// Usa la firma: CreateCall(FunctionType*, Value*, ArrayRef<Value*>)
// =====================================================
void RecipeCodegenVisitor::callPrintf(std::initializer_list<Value*> argsInit) {
    std::vector<Value*> args(argsInit);
    builder.CreateCall(printfFunc->getFunctionType(), printfFunc, args);
}

// =====================================================
// Imprimir línea literal (en una sola llamada a printf)
// =====================================================
void RecipeCodegenVisitor::emitLine(const std::string &text) {
    Value *ptr = makeString(text, "line");
    callPrintf({ ptr });
}

// =====================================================
// Crear main()
// =====================================================
void RecipeCodegenVisitor::createMainFunction() {
    if (mainFunc) return;

    FunctionType *mainTy = FunctionType::get(builder.getInt32Ty(), false);
    mainFunc = Function::Create(
        mainTy,
        Function::ExternalLinkage,
        "main",
        module.get()
    );

    BasicBlock *entry = BasicBlock::Create(context, "entry", mainFunc);
    builder.SetInsertPoint(entry);
}

// =====================================================
// Configurar printf y cadenas de formato
// =====================================================
void RecipeCodegenVisitor::setupPrintfAndFormats() {
    if (printfFunc) return;

    // int printf(...)
    FunctionType *printfTy = FunctionType::get(builder.getInt32Ty(), true);
    printfFunc = Function::Create(
        printfTy,
        Function::ExternalLinkage,
        "printf",
        module.get()
    );

    fmtHeaderReceta = makeString("===== RECETA COMPILADA =====\n", "fmtHeader");
    fmtNombre       = makeString("Nombre: %s\n", "fmtNombre");
    fmtRinde        = makeString("Rinde: %d porciones\n", "fmtRinde");
    fmtTiempoPrep   = makeString("Tiempo preparación: %d minutos\n", "fmtTiempoPrep");
    fmtTiempoCocc   = makeString("Tiempo cocción: %d minutos\n\n", "fmtTiempoCocc");

    fmtIngrediente = makeString(
        " - %s: %s | costo %f | calorías %d\n",
        "fmtIngrediente"
    );

    fmtNutricionHeader = makeString("Nutrición:\n", "fmtNutricionHeader");
    fmtTotalCost       = makeString(" - total costo: %f\n", "fmtTotalCost");
    fmtTotalCalories   = makeString(" - total calorías: %d\n\n", "fmtTotalCalories");

    // Formatos para pasos (opción A)
    fmtStep       = makeString("%d. %s", "fmtStep");
    fmtStartUses  = makeString(" (usa: %s", "fmtStartUses");
    fmtComma      = makeString(", %s", "fmtComma");
    fmtCloseParen = makeString(")", "fmtCloseParen");
    fmtStartDep   = makeString(" | depende de: %d", "fmtStartDep");
    fmtCommaDep   = makeString(", %d", "fmtCommaDep");
}

// =====================================================
// visitProgram
// =====================================================
antlrcpp::Any RecipeCodegenVisitor::visitProgram(RecipeLangParser::ProgramContext *ctx) {
    createMainFunction();
    setupPrintfAndFormats();

    visitChildren(ctx);

    builder.CreateRet(builder.getInt32(0));
    return nullptr;
}

// =====================================================
// visitRecipeStmt
// =====================================================
antlrcpp::Any RecipeCodegenVisitor::visitRecipeStmt(RecipeLangParser::RecipeStmtContext *ctx) {
    current = CGRecipe();

    if (ctx->STRING())
        current.name = stripQuotes(ctx->STRING()->getText());

    // llenar current (rinde, tiempos, tags, ingredientes, pasos)
    visitChildren(ctx);

    // 1) Header con variables
    callPrintf({ fmtHeaderReceta });

    {
        Value *namePtr = makeString(current.name, "recipeName");
        callPrintf({ fmtNombre, namePtr });
    }

    {
        Value *slot = builder.CreateAlloca(builder.getInt32Ty(), nullptr, "rinde");
        builder.CreateStore(builder.getInt32(current.rinde), slot);
        Value *val = builder.CreateLoad(builder.getInt32Ty(), slot, "rindeVal");
        callPrintf({ fmtRinde, val });
    }

    {
        Value *slot = builder.CreateAlloca(builder.getInt32Ty(), nullptr, "tiempoPrep");
        builder.CreateStore(builder.getInt32(current.tiempo_preparacion), slot);
        Value *val = builder.CreateLoad(builder.getInt32Ty(), slot, "tiempoPrepVal");
        callPrintf({ fmtTiempoPrep, val });
    }

    {
        Value *slot = builder.CreateAlloca(builder.getInt32Ty(), nullptr, "tiempoCocc");
        builder.CreateStore(builder.getInt32(current.tiempo_coccion), slot);
        Value *val = builder.CreateLoad(builder.getInt32Ty(), slot, "tiempoCoccVal");
        callPrintf({ fmtTiempoCocc, val });
    }

    // 2) Tags
    emitLine("Tags:\n");
    for (const auto &t : current.tags) {
        emitLine(" - " + t + "\n");
    }
    emitLine("\n");

    // 3) Ingredientes dinámicos en LLVM
    emitLine("Ingredientes:\n");
    for (const auto &ing : current.ingredients) {
        Value *namePtr   = makeString(ing.name,   "ingName");
        Value *amountPtr = makeString(ing.amount, "ingAmount");
        Value *costVal   = ConstantFP::get(builder.getDoubleTy(), ing.cost);
        Value *calVal    = builder.getInt32(ing.calories);

        callPrintf({ fmtIngrediente, namePtr, amountPtr, costVal, calVal });
    }
    emitLine("\n");

    // 4) Pasos dinámicos (opción A)
    emitLine("Pasos:\n");

    for (const auto &s : current.steps) {
        // número + descripción
        Value *num  = builder.getInt32(s.number);
        Value *desc = makeString(s.description, "stepDesc");

        callPrintf({ fmtStep, num, desc });

        // (usa: ...)
        if (!s.uses.empty()) {
            Value *firstUse = makeString(s.uses[0], "firstUse");
            callPrintf({ fmtStartUses, firstUse });

            for (size_t i = 1; i < s.uses.size(); ++i) {
                Value *u = makeString(s.uses[i], "useStr");
                callPrintf({ fmtComma, u });
            }

            callPrintf({ fmtCloseParen });
        }

        // | depende de: ...
        if (!s.depends.empty()) {
            Value *firstDep = builder.getInt32(s.depends[0]);
            callPrintf({ fmtStartDep, firstDep });

            for (size_t i = 1; i < s.depends.size(); ++i) {
                Value *d = builder.getInt32(s.depends[i]);
                callPrintf({ fmtCommaDep, d });
            }
        }

        emitLine("\n");
    }

    emitLine("\n");

    // 5) Nutrición en LLVM
    emitNutritionUsingLLVM();

    return nullptr;
}

// =====================================================
// Metadatos básicos
// =====================================================
antlrcpp::Any RecipeCodegenVisitor::visitRindeDecl(RecipeLangParser::RindeDeclContext *ctx) {
    current.rinde = std::stoi(ctx->INT()->getText());
    return nullptr;
}

antlrcpp::Any RecipeCodegenVisitor::visitTiempoPrepDecl(RecipeLangParser::TiempoPrepDeclContext *ctx) {
    current.tiempo_preparacion = std::stoi(ctx->INT()->getText());
    return nullptr;
}

antlrcpp::Any RecipeCodegenVisitor::visitTiempoCoccDecl(RecipeLangParser::TiempoCoccDeclContext *ctx) {
    current.tiempo_coccion = std::stoi(ctx->INT()->getText());
    return nullptr;
}

// =====================================================
// Tags
// =====================================================
antlrcpp::Any RecipeCodegenVisitor::visitTagsDecl(RecipeLangParser::TagsDeclContext *ctx) {
    for (auto *tCtx : ctx->tag()) {
        current.tags.push_back(stripQuotes(tCtx->getText()));
    }
    return nullptr;
}

// =====================================================
// Ingredientes
// =====================================================
antlrcpp::Any RecipeCodegenVisitor::visitIngredientStmt(RecipeLangParser::IngredientStmtContext *ctx) {
    CGIngredient ing;

    ing.name   = ctx->ID()->getText();
    ing.amount = ctx->AMOUNT()->getText();

    if (ctx->FLOAT())
        ing.cost = std::stod(ctx->FLOAT()->getText());
    if (ctx->INT())
        ing.calories = std::stoi(ctx->INT()->getText());

    current.ingredients.push_back(ing);
    return nullptr;
}

antlrcpp::Any RecipeCodegenVisitor::visitIngredientesBlock(RecipeLangParser::IngredientesBlockContext *ctx) {
    return visitChildren(ctx);
}

// =====================================================
// Pasos
// =====================================================
antlrcpp::Any RecipeCodegenVisitor::visitStepStmt(RecipeLangParser::StepStmtContext *ctx) {
    CGStep s;

    if (!ctx->INT().empty())
        s.number = std::stoi(ctx->INT(0)->getText());

    if (ctx->STRING())
        s.description = stripQuotes(ctx->STRING()->getText());

    for (auto *idCtx : ctx->ID())
        s.uses.push_back(idCtx->getText());

    for (size_t i = 1; i < ctx->INT().size(); ++i)
        s.depends.push_back(std::stoi(ctx->INT(i)->getText()));

    current.steps.push_back(s);
    return nullptr;
}

antlrcpp::Any RecipeCodegenVisitor::visitPasosBlock(RecipeLangParser::PasosBlockContext *ctx) {
    return visitChildren(ctx);
}

// =====================================================
// Nutrición
// =====================================================
antlrcpp::Any RecipeCodegenVisitor::visitNutricionBlock(RecipeLangParser::NutricionBlockContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any RecipeCodegenVisitor::visitTotalCostStmt(RecipeLangParser::TotalCostStmtContext *ctx) {
    return nullptr;
}

antlrcpp::Any RecipeCodegenVisitor::visitTotalCaloriesStmt(RecipeLangParser::TotalCaloriesStmtContext *ctx) {
    return nullptr;
}

// =====================================================
// Nutrición en LLVM (suma costo y calorías)
// =====================================================
void RecipeCodegenVisitor::emitNutritionUsingLLVM() {
    callPrintf({ fmtNutricionHeader });

    Value *costSlot = builder.CreateAlloca(builder.getDoubleTy(), nullptr, "totalCost");
    Value *calSlot  = builder.CreateAlloca(builder.getInt32Ty(),   nullptr, "totalCalories");

    builder.CreateStore(ConstantFP::get(builder.getDoubleTy(), 0.0), costSlot);
    builder.CreateStore(builder.getInt32(0), calSlot);

    for (const auto &ing : current.ingredients) {
        // costo
        Value *oldCost = builder.CreateLoad(builder.getDoubleTy(), costSlot, "oldCost");
        Value *addCost = ConstantFP::get(builder.getDoubleTy(), ing.cost);
        Value *newCost = builder.CreateFAdd(oldCost, addCost, "newCost");
        builder.CreateStore(newCost, costSlot);

        // calorías
        Value *oldCal = builder.CreateLoad(builder.getInt32Ty(), calSlot, "oldCal");
        Value *addCal = builder.getInt32(ing.calories);
        Value *newCal = builder.CreateAdd(oldCal, addCal, "newCal");
        builder.CreateStore(newCal, calSlot);
    }

    Value *finalCost = builder.CreateLoad(builder.getDoubleTy(), costSlot, "finalCost");
    Value *finalCal  = builder.CreateLoad(builder.getInt32Ty(),  calSlot,  "finalCal");

    callPrintf({ fmtTotalCost, finalCost });
    callPrintf({ fmtTotalCalories, finalCal });
}

// =====================================================
// Imprimir IR
// =====================================================
void RecipeCodegenVisitor::printIR() {
    if (verifyModule(*module, &errs()))
        errs() << "ERROR: módulo LLVM inválido\n";

    module->print(outs(), nullptr);
}
