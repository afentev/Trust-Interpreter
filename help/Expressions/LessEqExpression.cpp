#include "LessEqExpression.h"

void LessEqExpression::accept(Visitor* visitor) {
    visitor->visit(shared_from_this());
}

LessEqExpression::LessEqExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right):
        left(std::move(left)), right(std::move(right)) {}

std::shared_ptr<Expression> LessEqExpression::get_left_exp() {
    return left;
}

std::shared_ptr<Expression> LessEqExpression::get_right_exp() {
    return right;
}

LessEqExpression::~LessEqExpression() = default;