#pragma once

#include "../frontend/generated/RecipeLangBaseVisitor.h"
#include "AST.h"

#include <string>

class AstBuilderVisitor : public RecipeLangBaseVisitor {
public:
    Program program;

    AstBuilderVisitor() = default;

    // Reglas principales
    antlrcpp::Any visitProgram(RecipeLangParser::ProgramaContext *ctx) override;
    antlrcpp::Any visitRecetaDef(RecipeLangParser::RecetaDefContext *ctx) override;
    antlrcpp::Any visitPropiedadReceta(RecipeLangParser::PropiedadRecetaContext *ctx) override;

    // Secciones
    antlrcpp::Any visitSeccionIngredientes(RecipeLangParser::SeccionIngredientesContext *ctx) override;
    antlrcpp::Any visitDeclIngrediente(RecipeLangParser::DeclIngredienteContext *ctx) override;

    antlrcpp::Any visitSeccionPasos(RecipeLangParser::SeccionPasosContext *ctx) override;
    antlrcpp::Any visitDeclPaso(RecipeLangParser::DeclPasoContext *ctx) override;

    antlrcpp::Any visitUsaSentencia(RecipeLangParser::UsaSentenciaContext *ctx) override;
    antlrcpp::Any visitNotaSentencia(RecipeLangParser::NotaSentenciaContext *ctx) override;
    antlrcpp::Any visitEsperaSentencia(RecipeLangParser::EsperaSentenciaContext *ctx) override;

    antlrcpp::Any visitSeccionNutricion(RecipeLangParser::SeccionNutricionContext *ctx) override;
    antlrcpp::Any visitTotalCostoStmt(RecipeLangParser::TotalCostoStmtContext *ctx) override;
    antlrcpp::Any visitTotalCaloriasStmt(RecipeLangParser::TotalCaloriasStmtContext *ctx) override;

private:
    Recipe *currentRecipe = nullptr;
    Step *currentStep = nullptr;

    static std::string stripQuotes(const std::string &s);
    static double parseNumber(const std::string &s);
};
