
// Generated from Recipes.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "RecipesListener.h"


/**
 * This class provides an empty implementation of RecipesListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  RecipesBaseListener : public RecipesListener {
public:

  virtual void enterProgram(RecipesParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(RecipesParser::ProgramContext * /*ctx*/) override { }

  virtual void enterRecipeStmt(RecipesParser::RecipeStmtContext * /*ctx*/) override { }
  virtual void exitRecipeStmt(RecipesParser::RecipeStmtContext * /*ctx*/) override { }

  virtual void enterStatement(RecipesParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(RecipesParser::StatementContext * /*ctx*/) override { }

  virtual void enterIngredientStmt(RecipesParser::IngredientStmtContext * /*ctx*/) override { }
  virtual void exitIngredientStmt(RecipesParser::IngredientStmtContext * /*ctx*/) override { }

  virtual void enterStepStmt(RecipesParser::StepStmtContext * /*ctx*/) override { }
  virtual void exitStepStmt(RecipesParser::StepStmtContext * /*ctx*/) override { }

  virtual void enterTotalCaloriesStmt(RecipesParser::TotalCaloriesStmtContext * /*ctx*/) override { }
  virtual void exitTotalCaloriesStmt(RecipesParser::TotalCaloriesStmtContext * /*ctx*/) override { }

  virtual void enterStepParams(RecipesParser::StepParamsContext * /*ctx*/) override { }
  virtual void exitStepParams(RecipesParser::StepParamsContext * /*ctx*/) override { }

  virtual void enterStepModifiers(RecipesParser::StepModifiersContext * /*ctx*/) override { }
  virtual void exitStepModifiers(RecipesParser::StepModifiersContext * /*ctx*/) override { }

  virtual void enterParallel(RecipesParser::ParallelContext * /*ctx*/) override { }
  virtual void exitParallel(RecipesParser::ParallelContext * /*ctx*/) override { }

  virtual void enterDependsOn(RecipesParser::DependsOnContext * /*ctx*/) override { }
  virtual void exitDependsOn(RecipesParser::DependsOnContext * /*ctx*/) override { }

  virtual void enterTotalCostStmt(RecipesParser::TotalCostStmtContext * /*ctx*/) override { }
  virtual void exitTotalCostStmt(RecipesParser::TotalCostStmtContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

