
// Generated from Recipes.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "RecipesVisitor.h"


/**
 * This class provides an empty implementation of RecipesVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  RecipesBaseVisitor : public RecipesVisitor {
public:

  virtual antlrcpp::Any visitProgram(RecipesParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRecipeStmt(RecipesParser::RecipeStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(RecipesParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIngredientStmt(RecipesParser::IngredientStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepStmt(RecipesParser::StepStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTotalCaloriesStmt(RecipesParser::TotalCaloriesStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepParams(RecipesParser::StepParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepModifiers(RecipesParser::StepModifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParallel(RecipesParser::ParallelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDependsOn(RecipesParser::DependsOnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTotalCostStmt(RecipesParser::TotalCostStmtContext *ctx) override {
    return visitChildren(ctx);
  }


};

