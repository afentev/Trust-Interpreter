#include "MulExpression.h"

void MulExpression::accept(Visitor* visitor) {

}

MulExpression::MulExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right):
        left(std::move(left)), right(std::move(right)) {}

std::shared_ptr<Expression> MulExpression::get_left_exp() {
    return left;
}

std::shared_ptr<Expression> MulExpression::get_right_exp() {
    return right;
}

MulExpression::~MulExpression() = default;