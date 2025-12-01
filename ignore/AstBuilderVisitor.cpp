#include "AstBuilderVisitor.h"

#include <cstdlib>  // std::strtod, std::strtol

using namespace antlr4;

// =======================
// Helpers estáticos
// =======================
std::string AstBuilderVisitor::stripQuotes(const std::string &s) {
    if (s.size() >= 2 && s.front() == '"' && s.back() == '"') {
        return s.substr(1, s.size() - 2);
    }
    return s;
}

double AstBuilderVisitor::parseNumber(const std::string &s) {
    // Maneja INT o FLOAT como double
    return std::strtod(s.c_str(), nullptr);
}

// =======================
// programa
// =======================
antlrcpp::Any AstBuilderVisitor::visitProgram(RecipeLangParser::ProgramaContext *ctx) {
    for (auto *r : ctx->recetaDef()) {
        visit(r);
    }
    return nullptr;
}

// =======================
// recetaDef
// =======================
antlrcpp::Any AstBuilderVisitor::visitRecetaDef(RecipeLangParser::RecetaDefContext *ctx) {
    Recipe recipe;
    recipe.name = stripQuotes(ctx->nombre->getText());

    program.recipes.push_back(std::move(recipe));
    currentRecipe = &program.recipes.back();

    auto *body = ctx->cuerpoReceta();

    // Propiedades de la receta
    for (auto *p : body->propiedadReceta()) {
        visit(p);
    }

    // Secciones
    visit(body->seccionIngredientes());
    visit(body->seccionPasos());
    if (body->seccionNutricion()) {
        visit(body->seccionNutricion());
    }

    currentRecipe = nullptr;
    return nullptr;
}

// =======================
// propiedadReceta
// =======================
antlrcpp::Any AstBuilderVisitor::visitPropiedadReceta(RecipeLangParser::PropiedadRecetaContext *ctx) {
    if (!currentRecipe) return nullptr;

    if (ctx->porciones) {
        currentRecipe->serves = std::strtol(ctx->porciones->getText().c_str(), nullptr, 10);
    } else if (ctx->prep) {
        currentRecipe->prepTimeMin = std::strtol(ctx->prep->getText().c_str(), nullptr, 10);
    } else if (ctx->coccion) {
        currentRecipe->cookTimeMin = std::strtol(ctx->coccion->getText().c_str(), nullptr, 10);
    } else if (!ctx->tags.empty()) {
        for (auto *t : ctx->tags) {
            currentRecipe->tags.push_back(t->getText());
        }
    }

    return nullptr;
}

// =======================
// seccionIngredientes
// =======================
antlrcpp::Any AstBuilderVisitor::visitSeccionIngredientes(RecipeLangParser::SeccionIngredientesContext *ctx) {
    for (auto *decl : ctx->declIngrediente()) {
        visit(decl);
    }
    return nullptr;
}

// declIngrediente
antlrcpp::Any AstBuilderVisitor::visitDeclIngrediente(RecipeLangParser::DeclIngredienteContext *ctx) {
    if (!currentRecipe) return nullptr;

    Ingredient ing;
    ing.name = ctx->nombre->getText();

    auto *qCtx = ctx->cant;
    if (qCtx) {
        ing.quantity.amount = parseNumber(qCtx->numero->getText());
        ing.quantity.unit = qCtx->unidad->getText();
    }

    if (ctx->costo) {
        ing.hasCost = true;
        ing.cost = parseNumber(ctx->costo->getText());
    }

    if (ctx->calorias) {
        ing.hasCalories = true;
        ing.calories = std::strtol(ctx->calorias->getText().c_str(), nullptr, 10);
    }

    currentRecipe->ingredients.push_back(std::move(ing));
    return nullptr;
}

// =======================
// seccionPasos
// =======================
antlrcpp::Any AstBuilderVisitor::visitSeccionPasos(RecipeLangParser::SeccionPasosContext *ctx) {
    for (auto *sd : ctx->declPaso()) {
        visit(sd);
    }
    return nullptr;
}

// declPaso
antlrcpp::Any AstBuilderVisitor::visitDeclPaso(RecipeLangParser::DeclPasoContext *ctx) {
    if (!currentRecipe) return nullptr;

    Step step;
    step.name = ctx->nombre->getText();

    currentRecipe->steps.push_back(std::move(step));
    currentStep = &currentRecipe->steps.back();

    for (auto *st : ctx->sentenciaPaso()) {
        visit(st);  // esto bajará a usaSentencia / notaSentencia / esperaSentencia
    }

    currentStep = nullptr;
    return nullptr;
}

// usaSentencia
antlrcpp::Any AstBuilderVisitor::visitUsaSentencia(RecipeLangParser::UsaSentenciaContext *ctx) {
    if (!currentStep) return nullptr;

    StepAction action;
    action.kind = StepAction::Kind::Use;
    action.use.ingredientName = ctx->nombre->getText();

    if (ctx->cant) {
        action.use.hasQuantity = true;
        action.use.quantity.amount = parseNumber(ctx->cant->numero->getText());
        action.use.quantity.unit = ctx->cant->unidad->getText();
    }

    currentStep->actions.push_back(std::move(action));
    return nullptr;
}

// notaSentencia
antlrcpp::Any AstBuilderVisitor::visitNotaSentencia(RecipeLangParser::NotaSentenciaContext *ctx) {
    if (!currentStep) return nullptr;

    StepAction action;
    action.kind = StepAction::Kind::Note;
    action.note.text = stripQuotes(ctx->texto->getText());

    currentStep->actions.push_back(std::move(action));
    return nullptr;
}

// esperaSentencia
antlrcpp::Any AstBuilderVisitor::visitEsperaSentencia(RecipeLangParser::EsperaSentenciaContext *ctx) {
    if (!currentStep) return nullptr;

    StepAction action;
    action.kind = StepAction::Kind::Wait;
    action.wait.minutes = std::strtol(ctx->minutos->getText().c_str(), nullptr, 10);

    currentStep->actions.push_back(std::move(action));
    return nullptr;
}

// =======================
// seccionNutricion
// =======================
antlrcpp::Any AstBuilderVisitor::visitSeccionNutricion(RecipeLangParser::SeccionNutricionContext *ctx) {
    for (auto *n : ctx->sentenciaNutricion()) {
        visit(n);
    }
    return nullptr;
}

// costo_total
antlrcpp::Any AstBuilderVisitor::visitTotalCostoStmt(RecipeLangParser::TotalCostoStmtContext *ctx) {
    if (currentRecipe) {
        currentRecipe->requestTotalCost = true;
    }
    return nullptr;
}

// calorias_totales
antlrcpp::Any AstBuilderVisitor::visitTotalCaloriasStmt(RecipeLangParser::TotalCaloriasStmtContext *ctx) {
    if (currentRecipe) {
        currentRecipe->requestTotalCalories = true;
    }
    return nullptr;
}
