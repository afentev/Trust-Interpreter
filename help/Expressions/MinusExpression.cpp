#include "MinusExpression.h"

void MinusExpression::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

MinusExpression::MinusExpression (std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) :
    left(std::move(left)), right(std::move(right)) {}

std::shared_ptr<Expression> MinusExpression::get_left_exp () {
  return left;
}

std::shared_ptr<Expression> MinusExpression::get_right_exp () {
  return right;
}

MinusExpression::~MinusExpression () = default;