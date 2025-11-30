
// Generated from Recipes.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  RecipesParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, ID = 12, AMOUNT = 13, STRING = 14, 
    INT = 15, FLOAT = 16, WS = 17
  };

  enum {
    RuleProgram = 0, RuleRecipeStmt = 1, RuleStatement = 2, RuleIngredientStmt = 3, 
    RuleStepStmt = 4, RuleTotalCaloriesStmt = 5, RuleStepParams = 6, RuleStepModifiers = 7, 
    RuleParallel = 8, RuleDependsOn = 9, RuleTotalCostStmt = 10
  };

  explicit RecipesParser(antlr4::TokenStream *input);
  ~RecipesParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class RecipeStmtContext;
  class StatementContext;
  class IngredientStmtContext;
  class StepStmtContext;
  class TotalCaloriesStmtContext;
  class StepParamsContext;
  class StepModifiersContext;
  class ParallelContext;
  class DependsOnContext;
  class TotalCostStmtContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RecipeStmtContext *recipeStmt();
    antlr4::tree::TerminalNode *EOF();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  RecipeStmtContext : public antlr4::ParserRuleContext {
  public:
    RecipeStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RecipeStmtContext* recipeStmt();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IngredientStmtContext *ingredientStmt();
    StepStmtContext *stepStmt();
    TotalCostStmtContext *totalCostStmt();
    TotalCaloriesStmtContext *totalCaloriesStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  IngredientStmtContext : public antlr4::ParserRuleContext {
  public:
    IngredientStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *AMOUNT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *INT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IngredientStmtContext* ingredientStmt();

  class  StepStmtContext : public antlr4::ParserRuleContext {
  public:
    StepStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    StepParamsContext *stepParams();
    std::vector<StepModifiersContext *> stepModifiers();
    StepModifiersContext* stepModifiers(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AMOUNT();
    antlr4::tree::TerminalNode* AMOUNT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StepStmtContext* stepStmt();

  class  TotalCaloriesStmtContext : public antlr4::ParserRuleContext {
  public:
    TotalCaloriesStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TotalCaloriesStmtContext* totalCaloriesStmt();

  class  StepParamsContext : public antlr4::ParserRuleContext {
  public:
    StepParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AMOUNT();
    antlr4::tree::TerminalNode* AMOUNT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> FLOAT();
    antlr4::tree::TerminalNode* FLOAT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StepParamsContext* stepParams();

  class  StepModifiersContext : public antlr4::ParserRuleContext {
  public:
    StepModifiersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParallelContext *> parallel();
    ParallelContext* parallel(size_t i);
    std::vector<DependsOnContext *> dependsOn();
    DependsOnContext* dependsOn(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StepModifiersContext* stepModifiers();

  class  ParallelContext : public antlr4::ParserRuleContext {
  public:
    ParallelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParallelContext* parallel();

  class  DependsOnContext : public antlr4::ParserRuleContext {
  public:
    DependsOnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DependsOnContext* dependsOn();

  class  TotalCostStmtContext : public antlr4::ParserRuleContext {
  public:
    TotalCostStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TotalCostStmtContext* totalCostStmt();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

