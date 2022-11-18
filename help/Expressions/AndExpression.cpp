#include "AndExpression.h"

void AndExpression::accept(Visitor* visitor) {

}

AndExpression::AndExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right):
    left(std::move(left)), right(std::move(right)) {}

std::shared_ptr<Expression> AndExpression::get_left_exp() {
    return left;
}

std::shared_ptr<Expression> AndExpression::get_right_exp() {
    return right;
}

AndExpression::~AndExpression() = default;