#include "NotEqualExpression.h"

void NotEqualExpression::accept(Visitor* visitor) {

}

NotEqualExpression::NotEqualExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right):
        left(std::move(left)), right(std::move(right)) {}

std::shared_ptr<Expression> NotEqualExpression::get_left_exp() {
    return left;
}

std::shared_ptr<Expression> NotEqualExpression::get_right_exp() {
    return right;
}

NotEqualExpression::~NotEqualExpression() = default;