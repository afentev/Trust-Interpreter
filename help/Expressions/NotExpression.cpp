#include "NotExpression.h"

NotExpression::NotExpression (std::shared_ptr<Expression> expression) : expression(std::move(expression)) {}

std::shared_ptr<Expression> NotExpression::get_expression () {
  return expression;
}

void NotExpression::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

NotExpression::~NotExpression () = default;
