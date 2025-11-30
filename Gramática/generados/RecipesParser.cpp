
// Generated from Recipes.g4 by ANTLR 4.9.3


#include "RecipesListener.h"
#include "RecipesVisitor.h"

#include "RecipesParser.h"


using namespace antlrcpp;
using namespace antlr4;

RecipesParser::RecipesParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

RecipesParser::~RecipesParser() {
  delete _interpreter;
}

std::string RecipesParser::getGrammarFileName() const {
  return "Recipes.g4";
}

const std::vector<std::string>& RecipesParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& RecipesParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

RecipesParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RecipesParser::RecipeStmtContext* RecipesParser::ProgramContext::recipeStmt() {
  return getRuleContext<RecipesParser::RecipeStmtContext>(0);
}

tree::TerminalNode* RecipesParser::ProgramContext::EOF() {
  return getToken(RecipesParser::EOF, 0);
}

std::vector<RecipesParser::StatementContext *> RecipesParser::ProgramContext::statement() {
  return getRuleContexts<RecipesParser::StatementContext>();
}

RecipesParser::StatementContext* RecipesParser::ProgramContext::statement(size_t i) {
  return getRuleContext<RecipesParser::StatementContext>(i);
}


size_t RecipesParser::ProgramContext::getRuleIndex() const {
  return RecipesParser::RuleProgram;
}

void RecipesParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void RecipesParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any RecipesParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RecipesVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

RecipesParser::ProgramContext* RecipesParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, RecipesParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(22);
    recipeStmt();
    setState(24); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(23);
      statement();
      setState(26); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << RecipesParser::T__2)
      | (1ULL << RecipesParser::T__5)
      | (1ULL << RecipesParser::T__7)
      | (1ULL << RecipesParser::T__10))) != 0));
    setState(28);
    match(RecipesParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RecipeStmtContext ------------------------------------------------------------------

RecipesParser::RecipeStmtContext::RecipeStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RecipesParser::RecipeStmtContext::STRING() {
  return getToken(RecipesParser::STRING, 0);
}


size_t RecipesParser::RecipeStmtContext::getRuleIndex() const {
  return RecipesParser::RuleRecipeStmt;
}

void RecipesParser::RecipeStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRecipeStmt(this);
}

void RecipesParser::RecipeStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRecipeStmt(this);
}


antlrcpp::Any RecipesParser::RecipeStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RecipesVisitor*>(visitor))
    return parserVisitor->visitRecipeStmt(this);
  else
    return visitor->visitChildren(this);
}

RecipesParser::RecipeStmtContext* RecipesParser::recipeStmt() {
  RecipeStmtContext *_localctx = _tracker.createInstance<RecipeStmtContext>(_ctx, getState());
  enterRule(_localctx, 2, RecipesParser::RuleRecipeStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(30);
    match(RecipesParser::T__0);
    setState(31);
    match(RecipesParser::STRING);
    setState(32);
    match(RecipesParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

RecipesParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RecipesParser::IngredientStmtContext* RecipesParser::StatementContext::ingredientStmt() {
  return getRuleContext<RecipesParser::IngredientStmtContext>(0);
}

RecipesParser::StepStmtContext* RecipesParser::StatementContext::stepStmt() {
  return getRuleContext<RecipesParser::StepStmtContext>(0);
}

RecipesParser::TotalCostStmtContext* RecipesParser::StatementContext::totalCostStmt() {
  return getRuleContext<RecipesParser::TotalCostStmtContext>(0);
}

RecipesParser::TotalCaloriesStmtContext* RecipesParser::StatementContext::totalCaloriesStmt() {
  return getRuleContext<RecipesParser::TotalCaloriesStmtContext>(0);
}


size_t RecipesParser::StatementContext::getRuleIndex() const {
  return RecipesParser::RuleStatement;
}

void RecipesParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void RecipesParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any RecipesParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RecipesVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

RecipesParser::StatementContext* RecipesParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, RecipesParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(38);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RecipesParser::T__2: {
        enterOuterAlt(_localctx, 1);
        setState(34);
        ingredientStmt();
        break;
      }

      case RecipesParser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(35);
        stepStmt();
        break;
      }

      case RecipesParser::T__10: {
        enterOuterAlt(_localctx, 3);
        setState(36);
        totalCostStmt();
        break;
      }

      case RecipesParser::T__7: {
        enterOuterAlt(_localctx, 4);
        setState(37);
        totalCaloriesStmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IngredientStmtContext ------------------------------------------------------------------

RecipesParser::IngredientStmtContext::IngredientStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RecipesParser::IngredientStmtContext::ID() {
  return getToken(RecipesParser::ID, 0);
}

tree::TerminalNode* RecipesParser::IngredientStmtContext::AMOUNT() {
  return getToken(RecipesParser::AMOUNT, 0);
}

tree::TerminalNode* RecipesParser::IngredientStmtContext::FLOAT() {
  return getToken(RecipesParser::FLOAT, 0);
}

tree::TerminalNode* RecipesParser::IngredientStmtContext::INT() {
  return getToken(RecipesParser::INT, 0);
}


size_t RecipesParser::IngredientStmtContext::getRuleIndex() const {
  return RecipesParser::RuleIngredientStmt;
}

void RecipesParser::IngredientStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIngredientStmt(this);
}

void RecipesParser::IngredientStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIngredientStmt(this);
}


antlrcpp::Any RecipesParser::IngredientStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RecipesVisitor*>(visitor))
    return parserVisitor->visitIngredientStmt(this);
  else
    return visitor->visitChildren(this);
}

RecipesParser::IngredientStmtContext* RecipesParser::ingredientStmt() {
  IngredientStmtContext *_localctx = _tracker.createInstance<IngredientStmtContext>(_ctx, getState());
  enterRule(_localctx, 6, RecipesParser::RuleIngredientStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(40);
    match(RecipesParser::T__2);
    setState(41);
    match(RecipesParser::ID);
    setState(42);
    match(RecipesParser::AMOUNT);
    setState(45);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RecipesParser::T__3) {
      setState(43);
      match(RecipesParser::T__3);
      setState(44);
      match(RecipesParser::FLOAT);
    }
    setState(49);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RecipesParser::T__4) {
      setState(47);
      match(RecipesParser::T__4);
      setState(48);
      match(RecipesParser::INT);
    }
    setState(51);
    match(RecipesParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StepStmtContext ------------------------------------------------------------------

RecipesParser::StepStmtContext::StepStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RecipesParser::StepStmtContext::ID() {
  return getToken(RecipesParser::ID, 0);
}

RecipesParser::StepParamsContext* RecipesParser::StepStmtContext::stepParams() {
  return getRuleContext<RecipesParser::StepParamsContext>(0);
}

std::vector<RecipesParser::StepModifiersContext *> RecipesParser::StepStmtContext::stepModifiers() {
  return getRuleContexts<RecipesParser::StepModifiersContext>();
}

RecipesParser::StepModifiersContext* RecipesParser::StepStmtContext::stepModifiers(size_t i) {
  return getRuleContext<RecipesParser::StepModifiersContext>(i);
}

std::vector<tree::TerminalNode *> RecipesParser::StepStmtContext::AMOUNT() {
  return getTokens(RecipesParser::AMOUNT);
}

tree::TerminalNode* RecipesParser::StepStmtContext::AMOUNT(size_t i) {
  return getToken(RecipesParser::AMOUNT, i);
}


size_t RecipesParser::StepStmtContext::getRuleIndex() const {
  return RecipesParser::RuleStepStmt;
}

void RecipesParser::StepStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepStmt(this);
}

void RecipesParser::StepStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepStmt(this);
}


antlrcpp::Any RecipesParser::StepStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RecipesVisitor*>(visitor))
    return parserVisitor->visitStepStmt(this);
  else
    return visitor->visitChildren(this);
}

RecipesParser::StepStmtContext* RecipesParser::stepStmt() {
  StepStmtContext *_localctx = _tracker.createInstance<StepStmtContext>(_ctx, getState());
  enterRule(_localctx, 8, RecipesParser::RuleStepStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    match(RecipesParser::T__5);
    setState(54);
    match(RecipesParser::ID);
    setState(56);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << RecipesParser::ID)
      | (1ULL << RecipesParser::AMOUNT)
      | (1ULL << RecipesParser::FLOAT))) != 0)) {
      setState(55);
      stepParams();
    }
    setState(63);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << RecipesParser::T__6)
      | (1ULL << RecipesParser::T__8)
      | (1ULL << RecipesParser::T__9))) != 0)) {
      setState(61);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case RecipesParser::T__8:
        case RecipesParser::T__9: {
          setState(58);
          stepModifiers();
          break;
        }

        case RecipesParser::T__6: {
          setState(59);
          match(RecipesParser::T__6);
          setState(60);
          match(RecipesParser::AMOUNT);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(65);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(66);
    match(RecipesParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TotalCaloriesStmtContext ------------------------------------------------------------------

RecipesParser::TotalCaloriesStmtContext::TotalCaloriesStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RecipesParser::TotalCaloriesStmtContext::getRuleIndex() const {
  return RecipesParser::RuleTotalCaloriesStmt;
}

void RecipesParser::TotalCaloriesStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTotalCaloriesStmt(this);
}

void RecipesParser::TotalCaloriesStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTotalCaloriesStmt(this);
}


antlrcpp::Any RecipesParser::TotalCaloriesStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RecipesVisitor*>(visitor))
    return parserVisitor->visitTotalCaloriesStmt(this);
  else
    return visitor->visitChildren(this);
}

RecipesParser::TotalCaloriesStmtContext* RecipesParser::totalCaloriesStmt() {
  TotalCaloriesStmtContext *_localctx = _tracker.createInstance<TotalCaloriesStmtContext>(_ctx, getState());
  enterRule(_localctx, 10, RecipesParser::RuleTotalCaloriesStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    match(RecipesParser::T__7);
    setState(69);
    match(RecipesParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StepParamsContext ------------------------------------------------------------------

RecipesParser::StepParamsContext::StepParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> RecipesParser::StepParamsContext::ID() {
  return getTokens(RecipesParser::ID);
}

tree::TerminalNode* RecipesParser::StepParamsContext::ID(size_t i) {
  return getToken(RecipesParser::ID, i);
}

std::vector<tree::TerminalNode *> RecipesParser::StepParamsContext::AMOUNT() {
  return getTokens(RecipesParser::AMOUNT);
}

tree::TerminalNode* RecipesParser::StepParamsContext::AMOUNT(size_t i) {
  return getToken(RecipesParser::AMOUNT, i);
}

std::vector<tree::TerminalNode *> RecipesParser::StepParamsContext::FLOAT() {
  return getTokens(RecipesParser::FLOAT);
}

tree::TerminalNode* RecipesParser::StepParamsContext::FLOAT(size_t i) {
  return getToken(RecipesParser::FLOAT, i);
}


size_t RecipesParser::StepParamsContext::getRuleIndex() const {
  return RecipesParser::RuleStepParams;
}

void RecipesParser::StepParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepParams(this);
}

void RecipesParser::StepParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepParams(this);
}


antlrcpp::Any RecipesParser::StepParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RecipesVisitor*>(visitor))
    return parserVisitor->visitStepParams(this);
  else
    return visitor->visitChildren(this);
}

RecipesParser::StepParamsContext* RecipesParser::stepParams() {
  StepParamsContext *_localctx = _tracker.createInstance<StepParamsContext>(_ctx, getState());
  enterRule(_localctx, 12, RecipesParser::RuleStepParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(72); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(71);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << RecipesParser::ID)
        | (1ULL << RecipesParser::AMOUNT)
        | (1ULL << RecipesParser::FLOAT))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(74); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << RecipesParser::ID)
      | (1ULL << RecipesParser::AMOUNT)
      | (1ULL << RecipesParser::FLOAT))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StepModifiersContext ------------------------------------------------------------------

RecipesParser::StepModifiersContext::StepModifiersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RecipesParser::ParallelContext *> RecipesParser::StepModifiersContext::parallel() {
  return getRuleContexts<RecipesParser::ParallelContext>();
}

RecipesParser::ParallelContext* RecipesParser::StepModifiersContext::parallel(size_t i) {
  return getRuleContext<RecipesParser::ParallelContext>(i);
}

std::vector<RecipesParser::DependsOnContext *> RecipesParser::StepModifiersContext::dependsOn() {
  return getRuleContexts<RecipesParser::DependsOnContext>();
}

RecipesParser::DependsOnContext* RecipesParser::StepModifiersContext::dependsOn(size_t i) {
  return getRuleContext<RecipesParser::DependsOnContext>(i);
}


size_t RecipesParser::StepModifiersContext::getRuleIndex() const {
  return RecipesParser::RuleStepModifiers;
}

void RecipesParser::StepModifiersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepModifiers(this);
}

void RecipesParser::StepModifiersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepModifiers(this);
}


antlrcpp::Any RecipesParser::StepModifiersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RecipesVisitor*>(visitor))
    return parserVisitor->visitStepModifiers(this);
  else
    return visitor->visitChildren(this);
}

RecipesParser::StepModifiersContext* RecipesParser::stepModifiers() {
  StepModifiersContext *_localctx = _tracker.createInstance<StepModifiersContext>(_ctx, getState());
  enterRule(_localctx, 14, RecipesParser::RuleStepModifiers);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(78); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(78);
              _errHandler->sync(this);
              switch (_input->LA(1)) {
                case RecipesParser::T__8: {
                  setState(76);
                  parallel();
                  break;
                }

                case RecipesParser::T__9: {
                  setState(77);
                  dependsOn();
                  break;
                }

              default:
                throw NoViableAltException(this);
              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(80); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParallelContext ------------------------------------------------------------------

RecipesParser::ParallelContext::ParallelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RecipesParser::ParallelContext::getRuleIndex() const {
  return RecipesParser::RuleParallel;
}

void RecipesParser::ParallelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParallel(this);
}

void RecipesParser::ParallelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParallel(this);
}


antlrcpp::Any RecipesParser::ParallelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RecipesVisitor*>(visitor))
    return parserVisitor->visitParallel(this);
  else
    return visitor->visitChildren(this);
}

RecipesParser::ParallelContext* RecipesParser::parallel() {
  ParallelContext *_localctx = _tracker.createInstance<ParallelContext>(_ctx, getState());
  enterRule(_localctx, 16, RecipesParser::RuleParallel);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    match(RecipesParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DependsOnContext ------------------------------------------------------------------

RecipesParser::DependsOnContext::DependsOnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RecipesParser::DependsOnContext::ID() {
  return getToken(RecipesParser::ID, 0);
}


size_t RecipesParser::DependsOnContext::getRuleIndex() const {
  return RecipesParser::RuleDependsOn;
}

void RecipesParser::DependsOnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDependsOn(this);
}

void RecipesParser::DependsOnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDependsOn(this);
}


antlrcpp::Any RecipesParser::DependsOnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RecipesVisitor*>(visitor))
    return parserVisitor->visitDependsOn(this);
  else
    return visitor->visitChildren(this);
}

RecipesParser::DependsOnContext* RecipesParser::dependsOn() {
  DependsOnContext *_localctx = _tracker.createInstance<DependsOnContext>(_ctx, getState());
  enterRule(_localctx, 18, RecipesParser::RuleDependsOn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);
    match(RecipesParser::T__9);
    setState(85);
    match(RecipesParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TotalCostStmtContext ------------------------------------------------------------------

RecipesParser::TotalCostStmtContext::TotalCostStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RecipesParser::TotalCostStmtContext::getRuleIndex() const {
  return RecipesParser::RuleTotalCostStmt;
}

void RecipesParser::TotalCostStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTotalCostStmt(this);
}

void RecipesParser::TotalCostStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RecipesListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTotalCostStmt(this);
}


antlrcpp::Any RecipesParser::TotalCostStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RecipesVisitor*>(visitor))
    return parserVisitor->visitTotalCostStmt(this);
  else
    return visitor->visitChildren(this);
}

RecipesParser::TotalCostStmtContext* RecipesParser::totalCostStmt() {
  TotalCostStmtContext *_localctx = _tracker.createInstance<TotalCostStmtContext>(_ctx, getState());
  enterRule(_localctx, 20, RecipesParser::RuleTotalCostStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    match(RecipesParser::T__10);
    setState(88);
    match(RecipesParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> RecipesParser::_decisionToDFA;
atn::PredictionContextCache RecipesParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN RecipesParser::_atn;
std::vector<uint16_t> RecipesParser::_serializedATN;

std::vector<std::string> RecipesParser::_ruleNames = {
  "program", "recipeStmt", "statement", "ingredientStmt", "stepStmt", "totalCaloriesStmt", 
  "stepParams", "stepModifiers", "parallel", "dependsOn", "totalCostStmt"
};

std::vector<std::string> RecipesParser::_literalNames = {
  "", "'recipe'", "';'", "'ingredient'", "'costPerUnit'", "'calories'", 
  "'step'", "'time'", "'totalCalories'", "'parallel'", "'dependsOn'", "'totalCost'"
};

std::vector<std::string> RecipesParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "ID", "AMOUNT", "STRING", 
  "INT", "FLOAT", "WS"
};

dfa::Vocabulary RecipesParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> RecipesParser::_tokenNames;

RecipesParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x13, 0x5d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x3, 0x2, 0x3, 0x2, 0x6, 
       0x2, 0x1b, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x1c, 0x3, 0x2, 0x3, 0x2, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x5, 0x4, 0x29, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x30, 0xa, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x5, 0x5, 0x34, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
       0x6, 0x3, 0x6, 0x5, 0x6, 0x3b, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
       0x6, 0x7, 0x6, 0x40, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x43, 0xb, 0x6, 
       0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x6, 
       0x8, 0x4b, 0xa, 0x8, 0xd, 0x8, 0xe, 0x8, 0x4c, 0x3, 0x9, 0x3, 0x9, 
       0x6, 0x9, 0x51, 0xa, 0x9, 0xd, 0x9, 0xe, 0x9, 0x52, 0x3, 0xa, 0x3, 
       0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
       0x3, 0xc, 0x2, 0x2, 0xd, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
       0x12, 0x14, 0x16, 0x2, 0x3, 0x4, 0x2, 0xe, 0xf, 0x12, 0x12, 0x2, 
       0x5d, 0x2, 0x18, 0x3, 0x2, 0x2, 0x2, 0x4, 0x20, 0x3, 0x2, 0x2, 0x2, 
       0x6, 0x28, 0x3, 0x2, 0x2, 0x2, 0x8, 0x2a, 0x3, 0x2, 0x2, 0x2, 0xa, 
       0x37, 0x3, 0x2, 0x2, 0x2, 0xc, 0x46, 0x3, 0x2, 0x2, 0x2, 0xe, 0x4a, 
       0x3, 0x2, 0x2, 0x2, 0x10, 0x50, 0x3, 0x2, 0x2, 0x2, 0x12, 0x54, 0x3, 
       0x2, 0x2, 0x2, 0x14, 0x56, 0x3, 0x2, 0x2, 0x2, 0x16, 0x59, 0x3, 0x2, 
       0x2, 0x2, 0x18, 0x1a, 0x5, 0x4, 0x3, 0x2, 0x19, 0x1b, 0x5, 0x6, 0x4, 
       0x2, 0x1a, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1c, 0x3, 0x2, 0x2, 0x2, 
       0x1c, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1d, 
       0x1e, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x7, 0x2, 0x2, 0x3, 0x1f, 0x3, 
       0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x7, 0x3, 0x2, 0x2, 0x21, 0x22, 0x7, 
       0x10, 0x2, 0x2, 0x22, 0x23, 0x7, 0x4, 0x2, 0x2, 0x23, 0x5, 0x3, 0x2, 
       0x2, 0x2, 0x24, 0x29, 0x5, 0x8, 0x5, 0x2, 0x25, 0x29, 0x5, 0xa, 0x6, 
       0x2, 0x26, 0x29, 0x5, 0x16, 0xc, 0x2, 0x27, 0x29, 0x5, 0xc, 0x7, 
       0x2, 0x28, 0x24, 0x3, 0x2, 0x2, 0x2, 0x28, 0x25, 0x3, 0x2, 0x2, 0x2, 
       0x28, 0x26, 0x3, 0x2, 0x2, 0x2, 0x28, 0x27, 0x3, 0x2, 0x2, 0x2, 0x29, 
       0x7, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x7, 0x5, 0x2, 0x2, 0x2b, 0x2c, 
       0x7, 0xe, 0x2, 0x2, 0x2c, 0x2f, 0x7, 0xf, 0x2, 0x2, 0x2d, 0x2e, 0x7, 
       0x6, 0x2, 0x2, 0x2e, 0x30, 0x7, 0x12, 0x2, 0x2, 0x2f, 0x2d, 0x3, 
       0x2, 0x2, 0x2, 0x2f, 0x30, 0x3, 0x2, 0x2, 0x2, 0x30, 0x33, 0x3, 0x2, 
       0x2, 0x2, 0x31, 0x32, 0x7, 0x7, 0x2, 0x2, 0x32, 0x34, 0x7, 0x11, 
       0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 0x2, 
       0x2, 0x34, 0x35, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x7, 0x4, 0x2, 0x2, 
       0x36, 0x9, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x7, 0x8, 0x2, 0x2, 0x38, 
       0x3a, 0x7, 0xe, 0x2, 0x2, 0x39, 0x3b, 0x5, 0xe, 0x8, 0x2, 0x3a, 0x39, 
       0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x41, 0x3, 
       0x2, 0x2, 0x2, 0x3c, 0x40, 0x5, 0x10, 0x9, 0x2, 0x3d, 0x3e, 0x7, 
       0x9, 0x2, 0x2, 0x3e, 0x40, 0x7, 0xf, 0x2, 0x2, 0x3f, 0x3c, 0x3, 0x2, 
       0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x40, 0x43, 0x3, 0x2, 0x2, 
       0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 0x2, 0x2, 
       0x42, 0x44, 0x3, 0x2, 0x2, 0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x44, 
       0x45, 0x7, 0x4, 0x2, 0x2, 0x45, 0xb, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 
       0x7, 0xa, 0x2, 0x2, 0x47, 0x48, 0x7, 0x4, 0x2, 0x2, 0x48, 0xd, 0x3, 
       0x2, 0x2, 0x2, 0x49, 0x4b, 0x9, 0x2, 0x2, 0x2, 0x4a, 0x49, 0x3, 0x2, 
       0x2, 0x2, 0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 
       0x2, 0x4c, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4d, 0xf, 0x3, 0x2, 0x2, 0x2, 
       0x4e, 0x51, 0x5, 0x12, 0xa, 0x2, 0x4f, 0x51, 0x5, 0x14, 0xb, 0x2, 
       0x50, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 
       0x52, 0x3, 0x2, 0x2, 0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 
       0x3, 0x2, 0x2, 0x2, 0x53, 0x11, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x7, 
       0xb, 0x2, 0x2, 0x55, 0x13, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x7, 0xc, 
       0x2, 0x2, 0x57, 0x58, 0x7, 0xe, 0x2, 0x2, 0x58, 0x15, 0x3, 0x2, 0x2, 
       0x2, 0x59, 0x5a, 0x7, 0xd, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x4, 0x2, 0x2, 
       0x5b, 0x17, 0x3, 0x2, 0x2, 0x2, 0xc, 0x1c, 0x28, 0x2f, 0x33, 0x3a, 
       0x3f, 0x41, 0x4c, 0x50, 0x52, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

RecipesParser::Initializer RecipesParser::_init;
