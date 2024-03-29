#include "AndExpression.h"

AndExpression::AndExpression (std::shared_ptr<Expression> left, std::shared_ptr<Expression> right) :
    left(std::move(left)), right(std::move(right)) {}

std::shared_ptr<Expression> AndExpression::get_left_exp () {
  return left;
}

std::shared_ptr<Expression> AndExpression::get_right_exp () {
  return right;
}

void AndExpression::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

AndExpression::~AndExpression () = default;
