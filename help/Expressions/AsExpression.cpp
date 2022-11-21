#include "AsExpression.h"

AsExpression::AsExpression (std::shared_ptr<Expression> expression, std::string type) : expression(
    std::move(expression)), type(std::move(type)) {}

void AsExpression::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

std::string AsExpression::get_type () {
  return type;
}

std::shared_ptr<Expression> AsExpression::get_expression () {
  return expression;
}

AsExpression::~AsExpression () = default;
