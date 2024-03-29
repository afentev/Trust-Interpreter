#include "GreaterExpression.h"

GreaterExpression::GreaterExpression (std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) :
    left(std::move(left)), right(std::move(right)) {}

std::shared_ptr<Expression> GreaterExpression::get_left_exp () {
  return left;
}

std::shared_ptr<Expression> GreaterExpression::get_right_exp () {
  return right;
}

void GreaterExpression::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

GreaterExpression::~GreaterExpression () = default;
