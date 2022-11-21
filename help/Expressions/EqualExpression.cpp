#include "EqualExpression.h"

EqualExpression::EqualExpression (std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) :
    left(std::move(left)), right(std::move(right)) {}

std::shared_ptr<Expression> EqualExpression::get_left_exp () {
  return left;
}

std::shared_ptr<Expression> EqualExpression::get_right_exp () {
  return right;
}

void EqualExpression::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

EqualExpression::~EqualExpression () = default;
