#include "OrExpression.h"

void OrExpression::accept(Visitor* visitor) {
    visitor->visit(shared_from_this());
}

OrExpression::OrExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right):
        left(std::move(left)), right(std::move(right)) {}

std::shared_ptr<Expression> OrExpression::get_left_exp() {
    return left;
}

std::shared_ptr<Expression> OrExpression::get_right_exp() {
    return right;
}

OrExpression::~OrExpression() = default;