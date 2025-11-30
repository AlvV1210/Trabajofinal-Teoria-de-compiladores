
// Generated from Recipes.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "RecipesParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by RecipesParser.
 */
class  RecipesListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(RecipesParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(RecipesParser::ProgramContext *ctx) = 0;

  virtual void enterRecipeStmt(RecipesParser::RecipeStmtContext *ctx) = 0;
  virtual void exitRecipeStmt(RecipesParser::RecipeStmtContext *ctx) = 0;

  virtual void enterStatement(RecipesParser::StatementContext *ctx) = 0;
  virtual void exitStatement(RecipesParser::StatementContext *ctx) = 0;

  virtual void enterIngredientStmt(RecipesParser::IngredientStmtContext *ctx) = 0;
  virtual void exitIngredientStmt(RecipesParser::IngredientStmtContext *ctx) = 0;

  virtual void enterStepStmt(RecipesParser::StepStmtContext *ctx) = 0;
  virtual void exitStepStmt(RecipesParser::StepStmtContext *ctx) = 0;

  virtual void enterTotalCaloriesStmt(RecipesParser::TotalCaloriesStmtContext *ctx) = 0;
  virtual void exitTotalCaloriesStmt(RecipesParser::TotalCaloriesStmtContext *ctx) = 0;

  virtual void enterStepParams(RecipesParser::StepParamsContext *ctx) = 0;
  virtual void exitStepParams(RecipesParser::StepParamsContext *ctx) = 0;

  virtual void enterStepModifiers(RecipesParser::StepModifiersContext *ctx) = 0;
  virtual void exitStepModifiers(RecipesParser::StepModifiersContext *ctx) = 0;

  virtual void enterParallel(RecipesParser::ParallelContext *ctx) = 0;
  virtual void exitParallel(RecipesParser::ParallelContext *ctx) = 0;

  virtual void enterDependsOn(RecipesParser::DependsOnContext *ctx) = 0;
  virtual void exitDependsOn(RecipesParser::DependsOnContext *ctx) = 0;

  virtual void enterTotalCostStmt(RecipesParser::TotalCostStmtContext *ctx) = 0;
  virtual void exitTotalCostStmt(RecipesParser::TotalCostStmtContext *ctx) = 0;


};

