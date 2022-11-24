#ifndef PARSEREXAMPLE_VISITOR_H
#define PARSEREXAMPLE_VISITOR_H

#include <iostream>
#include <memory>
#include <unordered_set>
#include "help/Statements/Interruptions/Interruptions.h"
#include "help/Identifiers/IDTable.h"
#include "help/Functions/FunctionsTable.h"
#include "help/ForwardDeclarations.h"


class Visitor {
 public:
  void visit (std::shared_ptr<Program> program);

  void visit (std::shared_ptr<FunctionDeclarationList> function_declaration_list);
  void visit (std::shared_ptr<FunctionDeclaration> function);

  void visit (std::shared_ptr<Expression> expression);

  void visit (std::shared_ptr<Boolean> expression);
  void visit (std::shared_ptr<Integer> expression);
  void visit (std::shared_ptr<Float> expression);
  void visit (std::shared_ptr<String> expression);
  void visit (std::shared_ptr<Usize> expression);
  void visit (std::shared_ptr<Char> expression);
  void visit (std::shared_ptr<Vector> expression);

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
  void visit (std::shared_ptr<SubscriptionExpression> expression);
  void visit (std::shared_ptr<FunctionCall> expression);
  void visit (std::shared_ptr<VectorEnumerationExpression> expression);
  void visit (std::shared_ptr<VectorValueExpression> expression);
  void visit (std::shared_ptr<SizeExpression> expression);

  void visit (std::shared_ptr<Statements> statement);
  void visit (std::shared_ptr<VariableDeclaration> statement);
  void visit (std::shared_ptr<VariableDeclInit> statement);
  void visit (std::shared_ptr<TypelessVariableDecl> statement);
  void visit (std::shared_ptr<WhileStatement> statement);
  void visit (std::shared_ptr<IfStatement> statement);
  void visit (std::shared_ptr<IfElseStatement> statement);
  void visit (std::shared_ptr<ForStatement> statement);
  void visit (std::shared_ptr<AssignmentStatement> statement);
  void visit (std::shared_ptr<SubscriptionAssignment> statement);
  void visit (std::shared_ptr<ExpressionList> statement);
  void visit (std::shared_ptr<PrintStatement> statement);
  void visit (std::shared_ptr<BreakStatement> statement);
  void visit (std::shared_ptr<ContinueStatement> statement);
  void visit (std::shared_ptr<ReturnStatement> statement);
  void visit (std::shared_ptr<PushStatement> statement);
  void visit (std::shared_ptr<PopStatement> statement);

  std::shared_ptr<Object> evaluate (std::shared_ptr<Expression> expression);

  void prepare_for_call (Visitor& consumer, std::shared_ptr<FunctionCall> callee);

  ~Visitor ();

 private:
  std::shared_ptr<Object> object;
  std::string function_name = "main";
  IDTable variables;
  FunctionsTable functions;
};


#endif //PARSEREXAMPLE_VISITOR_H
