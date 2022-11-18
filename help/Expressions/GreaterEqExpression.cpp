#include "GreaterEqExpression.h"

void GreaterEqExpression::accept(Visitor* visitor) {

}

GreaterEqExpression::GreaterEqExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right):
        left(std::move(left)), right(std::move(right)) {}

std::shared_ptr<Expression> GreaterEqExpression::get_left_exp() {
    return left;
}

std::shared_ptr<Expression> GreaterEqExpression::get_right_exp() {
    return right;
}

GreaterEqExpression::~GreaterEqExpression() = default;