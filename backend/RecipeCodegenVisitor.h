#pragma once

#include "antlr4-runtime.h"
#include "../frontend/generated/RecipeLangBaseVisitor.h"
#include "../frontend/generated/RecipeLangParser.h"

// LLVM
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/raw_ostream.h"

#include <memory>
#include <string>
#include <vector>

// =============================
// Estructuras de datos
// =============================

struct CGIngredient {
    std::string name;
    std::string amount;
    double cost = 0.0;
    int calories = 0;
};

struct CGStep {
    int number = 0;
    std::string description;
    std::vector<std::string> uses;
    std::vector<int> depends;
};

struct CGRecipe {
    std::string name;
    int rinde = 0;
    int tiempo_preparacion = 0;
    int tiempo_coccion = 0;
    std::vector<std::string> tags;
    std::vector<CGIngredient> ingredients;
    std::vector<CGStep> steps;
};

class RecipeCodegenVisitor : public RecipeLangBaseVisitor {
public:
    RecipeCodegenVisitor();

    // Entradas principales
    antlrcpp::Any visitProgram(RecipeLangParser::ProgramContext *ctx) override;
    antlrcpp::Any visitRecipeStmt(RecipeLangParser::RecipeStmtContext *ctx) override;

    antlrcpp::Any visitRindeDecl(RecipeLangParser::RindeDeclContext *ctx) override;
    antlrcpp::Any visitTiempoPrepDecl(RecipeLangParser::TiempoPrepDeclContext *ctx) override;
    antlrcpp::Any visitTiempoCoccDecl(RecipeLangParser::TiempoCoccDeclContext *ctx) override;

    antlrcpp::Any visitTagsDecl(RecipeLangParser::TagsDeclContext *ctx) override;
    antlrcpp::Any visitIngredientStmt(RecipeLangParser::IngredientStmtContext *ctx) override;
    antlrcpp::Any visitStepStmt(RecipeLangParser::StepStmtContext *ctx) override;

    antlrcpp::Any visitIngredientesBlock(RecipeLangParser::IngredientesBlockContext *ctx) override;
    antlrcpp::Any visitPasosBlock(RecipeLangParser::PasosBlockContext *ctx) override;
    antlrcpp::Any visitNutricionBlock(RecipeLangParser::NutricionBlockContext *ctx) override;

    antlrcpp::Any visitTotalCostStmt(RecipeLangParser::TotalCostStmtContext *ctx) override;
    antlrcpp::Any visitTotalCaloriesStmt(RecipeLangParser::TotalCaloriesStmtContext *ctx) override;

    void printIR();

private:
    // LLVM core
    llvm::LLVMContext context;
    llvm::IRBuilder<> builder;
    std::unique_ptr<llvm::Module> module;
    llvm::Function *mainFunc = nullptr;
    llvm::Function *printfFunc = nullptr;

    // Cadenas de formato
    llvm::Value *fmtHeaderReceta   = nullptr;
    llvm::Value *fmtNombre         = nullptr;
    llvm::Value *fmtRinde          = nullptr;
    llvm::Value *fmtTiempoPrep     = nullptr;
    llvm::Value *fmtTiempoCocc     = nullptr;

    llvm::Value *fmtIngrediente    = nullptr;

    llvm::Value *fmtNutricionHeader = nullptr;
    llvm::Value *fmtTotalCost       = nullptr;
    llvm::Value *fmtTotalCalories   = nullptr;

    // Formatos para pasos
    llvm::Value *fmtStep       = nullptr;
    llvm::Value *fmtStartUses  = nullptr;
    llvm::Value *fmtComma      = nullptr;
    llvm::Value *fmtCloseParen = nullptr;
    llvm::Value *fmtStartDep   = nullptr;
    llvm::Value *fmtCommaDep   = nullptr;

    // Receta actual
    CGRecipe current;

    // Helpers LLVM
    void createMainFunction();
    void setupPrintfAndFormats();

    // Crea string global y devuelve i8* (char*)
    llvm::Value *makeString(const std::string &s, const std::string &name);

    // Wrapper para llamar a printf con cualquier número de args
    void callPrintf(std::initializer_list<llvm::Value*> args);

    // Imprimir línea literal (con salto)
    void emitLine(const std::string &text);

    // Nutrición calculada en LLVM
    void emitNutritionUsingLLVM();
};
