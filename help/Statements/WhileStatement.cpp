#include "WhileStatement.h"

WhileStatement::WhileStatement (std::shared_ptr<Expression> cond, std::shared_ptr<Statement> state) :
    condition(std::move(cond)), statement(std::move(state)) {

}

void WhileStatement::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

std::shared_ptr<Expression> WhileStatement::get_condition () {
  return condition;
}

std::shared_ptr<Statement> WhileStatement::get_statement () {
  return statement;
}

WhileStatement::~WhileStatement () = default;
