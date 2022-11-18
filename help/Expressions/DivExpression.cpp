#include "DivExpression.h"

void DivExpression::accept(Visitor* visitor) {
    visitor->visit(shared_from_this());
}

DivExpression::DivExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right):
        left(std::move(left)), right(std::move(right)) {}

std::shared_ptr<Expression> DivExpression::get_left_exp() {
    return left;
}

std::shared_ptr<Expression> DivExpression::get_right_exp() {
    return right;
}

DivExpression::~DivExpression() = default;