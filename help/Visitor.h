#ifndef PARSEREXAMPLE_VISITOR_H
#define PARSEREXAMPLE_VISITOR_H

#include <iostream>
#include <memory>
#include "help/Statements/Interruptions/Interruptions.h"
#include "help/Identifiers/IDTable.h"

class Object;

class Visitor;

class Expression;

class Program;

class Statement;

class Statements;

class VariableDeclaration;

class VariableDeclInit;

class TypelessVariableDecl;

class Boolean;

class String;

class Integer;

class Float;

class NotExpression;

class AndExpression;

class OrExpression;

class EqualExpression;

class NotEqualExpression;

class LessEqExpression;

class LessExpression;

class GreaterEqExpression;

class GreaterExpression;

class PlusExpression;

class MinusExpression;

class UnaryMinusExpression;

class MulExpression;

class DivExpression;

class ModExpression;

class IDExpression;

class AsExpression;

class WhileStatement;

class IfStatement;

class IfElseStatement;

class ForStatement;

class AssignmentStatement;

class ExpressionList;

class PrintStatement;

class BreakStatement;

class ContinueStatement;

class ReturnStatement;

class InterpretationException;

class Visitor {
 public:
  void visit (std::shared_ptr<Program> expression);

  void visit (std::shared_ptr<Expression> expression);

  void visit (std::shared_ptr<Boolean> expression);

  void visit (std::shared_ptr<Integer> expression);

  void visit (std::shared_ptr<Float> expression);

  void visit (std::shared_ptr<String> expression);

  void visit (std::shared_ptr<NotExpression> expression);

  void visit (std::shared_ptr<AndExpression> expression);

  void visit (std::shared_ptr<OrExpression> expression);

  void visit (std::shared_ptr<DivExpression> expression);

  void visit (std::shared_ptr<MulExpression> expression);

  void visit (std::shared_ptr<ModExpression> expression);

  void visit (std::shared_ptr<PlusExpression> expression);

  void visit (std::shared_ptr<MinusExpression> expression);

  void visit (std::shared_ptr<UnaryMinusExpression> expression);

  void visit (std::shared_ptr<GreaterExpression> expression);

  void visit (std::shared_ptr<GreaterEqExpression> expression);

  void visit (std::shared_ptr<EqualExpression> expression);

  void visit (std::shared_ptr<NotEqualExpression> expression);

  void visit (std::shared_ptr<LessEqExpression> expression);

  void visit (std::shared_ptr<LessExpression> expression);

  void visit (std::shared_ptr<IDExpression> expression);

  void visit (std::shared_ptr<AsExpression> expression);

  void visit (std::shared_ptr<Statements> expression);

  void visit (std::shared_ptr<VariableDeclaration> expression);

  void visit (std::shared_ptr<VariableDeclInit> expression);

  void visit (std::shared_ptr<TypelessVariableDecl> expression);

  void visit (std::shared_ptr<WhileStatement> expression);

  void visit (std::shared_ptr<IfStatement> expression);

  void visit (std::shared_ptr<IfElseStatement> expression);

  void visit (std::shared_ptr<ForStatement> expression);

  void visit (std::shared_ptr<AssignmentStatement> expression);

  void visit (std::shared_ptr<ExpressionList> expression);

  void visit (std::shared_ptr<PrintStatement> expression);

  void visit (std::shared_ptr<BreakStatement> expression);

  void visit (std::shared_ptr<ContinueStatement> expression);

  void visit (std::shared_ptr<ReturnStatement> expression);

  ~Visitor ();

  std::shared_ptr<Object> get_object ();

 private:
  std::shared_ptr<Object> object;
  IDTable variables;
};


#endif //PARSEREXAMPLE_VISITOR_H
