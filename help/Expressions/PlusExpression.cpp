#include "PlusExpression.h"

void PlusExpression::accept(Visitor* visitor) {
    visitor->visit(shared_from_this());
}

PlusExpression::PlusExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right):
        left(std::move(left)), right(std::move(right)) {}

std::shared_ptr<Expression> PlusExpression::get_left_exp() {
    return left;
}

std::shared_ptr<Expression> PlusExpression::get_right_exp() {
    return right;
}

PlusExpression::~PlusExpression() = default;