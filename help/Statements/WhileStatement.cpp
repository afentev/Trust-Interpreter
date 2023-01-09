#include "WhileStatement.h"

WhileStatement::WhileStatement (std::shared_ptr<Expression> cond, std::shared_ptr<Statement> state) :
    condition(std::move(cond)), statement(std::move(state)) {}

std::shared_ptr<Expression> WhileStatement::get_condition () {
  return condition;
}

std::shared_ptr<Statement> WhileStatement::get_statement () {
  return statement;
}

void WhileStatement::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

WhileStatement::~WhileStatement () = default;
