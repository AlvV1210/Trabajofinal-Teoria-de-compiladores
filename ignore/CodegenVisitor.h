#pragma once

#include "../frontend/generated/RecipeLangBaseVisitor.h"

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include <string>
#include <unordered_map>

class CodegenVisitor : public RecipeLangBaseVisitor {
public:
    CodegenVisitor(
        llvm::LLVMContext &context,
        llvm::Module *module,
        llvm::IRBuilder<> &builder
    );

    // Regla raíz
    antlrcpp::Any visitProgram(RecipeLangParser::ProgramContext *ctx) override;

    // Ingredientes
    antlrcpp::Any visitIngredientStmt(RecipeLangParser::IngredientStmtContext *ctx) override;

    // Nutrición
    antlrcpp::Any visitTotalCostStmt(RecipeLangParser::TotalCostStmtContext *ctx) override;
    antlrcpp::Any visitTotalCaloriesStmt(RecipeLangParser::TotalCaloriesStmtContext *ctx) override;

    void generateIR();

private:
    struct NutrInfo {
        double costo = 0.0;
        int calorias = 0;
    };

    llvm::LLVMContext &context;
    llvm::Module *module;
    llvm::IRBuilder<> &builder;

    llvm::Function *mainFn = nullptr;

    std::unordered_map<std::string, NutrInfo> ingredientes;

    double totalCosto = 0.0;
    int totalCalorias = 0;

    bool pideCostoTotal = false;
    bool pideCaloriasTotales = false;

    void calcularTotales();

    llvm::Value *emitPrintDouble(const std::string &label, llvm::Value *value);
    llvm::Value *emitPrintInt(const std::string &label, llvm::Value *value);
};
