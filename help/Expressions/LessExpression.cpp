#include "LessExpression.h"

void LessExpression::accept(Visitor* visitor) {

}

LessExpression::LessExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right):
        left(std::move(left)), right(std::move(right)) {}

std::shared_ptr<Expression> LessExpression::get_left_exp() {
    return left;
}

std::shared_ptr<Expression> LessExpression::get_right_exp() {
    return right;
}

LessExpression::~LessExpression() = default;