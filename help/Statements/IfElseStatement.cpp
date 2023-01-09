#include "IfElseStatement.h"

IfElseStatement::IfElseStatement (std::shared_ptr<Expression> cond, std::shared_ptr<Statement> true_statement,
                                  std::shared_ptr<Statement> false_statement) :
    condition(std::move(cond)), true_statement(std::move(true_statement)),
    false_statement(std::move(false_statement)) {}

std::shared_ptr<Expression> IfElseStatement::get_condition () {
  return condition;
}

std::shared_ptr<Statement> IfElseStatement::get_true_statement () {
  return true_statement;
}

std::shared_ptr<Statement> IfElseStatement::get_false_statement () {
  return false_statement;
}

void IfElseStatement::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

IfElseStatement::~IfElseStatement () = default;
