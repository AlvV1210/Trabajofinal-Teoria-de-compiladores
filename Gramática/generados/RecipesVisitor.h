
// Generated from Recipes.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "RecipesParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by RecipesParser.
 */
class  RecipesVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by RecipesParser.
   */
    virtual antlrcpp::Any visitProgram(RecipesParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitRecipeStmt(RecipesParser::RecipeStmtContext *context) = 0;

    virtual antlrcpp::Any visitStatement(RecipesParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitIngredientStmt(RecipesParser::IngredientStmtContext *context) = 0;

    virtual antlrcpp::Any visitStepStmt(RecipesParser::StepStmtContext *context) = 0;

    virtual antlrcpp::Any visitTotalCaloriesStmt(RecipesParser::TotalCaloriesStmtContext *context) = 0;

    virtual antlrcpp::Any visitStepParams(RecipesParser::StepParamsContext *context) = 0;

    virtual antlrcpp::Any visitStepModifiers(RecipesParser::StepModifiersContext *context) = 0;

    virtual antlrcpp::Any visitParallel(RecipesParser::ParallelContext *context) = 0;

    virtual antlrcpp::Any visitDependsOn(RecipesParser::DependsOnContext *context) = 0;

    virtual antlrcpp::Any visitTotalCostStmt(RecipesParser::TotalCostStmtContext *context) = 0;


};

