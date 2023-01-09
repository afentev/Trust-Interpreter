#include "UnaryMinusExpression.h"

UnaryMinusExpression::UnaryMinusExpression (std::shared_ptr<Expression> expression) : expression(
    std::move(expression)) {}

std::shared_ptr<Expression> UnaryMinusExpression::get_expression () {
  return expression;
}

void UnaryMinusExpression::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

UnaryMinusExpression::~UnaryMinusExpression () = default;
