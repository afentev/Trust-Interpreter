#include "PushStatement.h"

PushStatement::PushStatement (std::string id, std::shared_ptr<Expression> expression) : lhs(std::move(id)), expression(
    std::move(expression)) {}

std::string PushStatement::get_lhs () {
  return lhs;
}

std::shared_ptr<Expression> PushStatement::get_expression () {
  return expression;
}

void PushStatement::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

PushStatement::~PushStatement () = default;
