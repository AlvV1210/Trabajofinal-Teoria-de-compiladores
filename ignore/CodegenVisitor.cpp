#include "CodegenVisitor.h"
#include "../frontend/generated/RecipeLangParser.h"

using namespace llvm;
using antlrcpp::Any;

CodegenVisitor::CodegenVisitor(LLVMContext &ctx, Module *m, IRBuilder<> &b)
    : context(ctx), module(m), builder(b) {}

Any CodegenVisitor::visitProgram(RecipeLangParser::ProgramContext *ctx) {
    visitChildren(ctx);
    calcularTotales();
    return Any();
}

Any CodegenVisitor::visitIngredientStmt(RecipeLangParser::IngredientStmtContext *ctx) {
    std::string nombre = ctx->ID()->getText();

    NutrInfo info;
    info.costo = std::stod(ctx->FLOAT()->getText());
    info.calorias = std::stoi(ctx->INT()->getText());

    ingredientes[nombre] = info;

    return Any();
}

Any CodegenVisitor::visitTotalCostStmt(RecipeLangParser::TotalCostStmtContext *ctx) {
    pideCostoTotal = true;
    return Any();
}

Any CodegenVisitor::visitTotalCaloriesStmt(RecipeLangParser::TotalCaloriesStmtContext *ctx) {
    pideCaloriasTotales = true;
    return Any();
}

void CodegenVisitor::calcularTotales() {
    totalCosto = 0.0;
    totalCalorias = 0;

    for (auto &p : ingredientes) {
        totalCosto += p.second.costo;
        totalCalorias += p.second.calorias;
    }
}

Value *CodegenVisitor::emitPrintDouble(const std::string &label, Value *value) {
    FunctionCallee printfFn = module->getOrInsertFunction(
        "printf",
        FunctionType::get(
            IntegerType::getInt32Ty(context),
            PointerType::get(Type::getInt8Ty(context), 0),
            true));

    Value *fmtStr = builder.CreateGlobalStringPtr(label + ": %f\n");
    return builder.CreateCall(printfFn, {fmtStr, value});
}

Value *CodegenVisitor::emitPrintInt(const std::string &label, Value *value) {
    FunctionCallee printfFn = module->getOrInsertFunction(
        "printf",
        FunctionType::get(
            IntegerType::getInt32Ty(context),
            PointerType::get(Type::getInt8Ty(context), 0),
            true));

    Value *fmtStr = builder.CreateGlobalStringPtr(label + ": %d\n");
    return builder.CreateCall(printfFn, {fmtStr, value});
}

void CodegenVisitor::generateIR() {
    FunctionType *mainType =
        FunctionType::get(Type::getInt32Ty(context), false);

    mainFn = Function::Create(
        mainType,
        Function::ExternalLinkage,
        "main",
        module
    );

    BasicBlock *entry = BasicBlock::Create(context, "entry", mainFn);
    builder.SetInsertPoint(entry);

    if (pideCostoTotal) {
        Value *cost = ConstantFP::get(Type::getDoubleTy(context), totalCosto);
        emitPrintDouble("Costo total", cost);
    }

    if (pideCaloriasTotales) {
        Value *cal = ConstantInt::get(Type::getInt32Ty(context), totalCalorias);
        emitPrintInt("Calorías totales", cal);
    }

    builder.CreateRet(ConstantInt::get(Type::getInt32Ty(context), 0));
}
