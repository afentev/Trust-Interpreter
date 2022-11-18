#include "ModExpression.h"

void ModExpression::accept(Visitor* visitor) {
    visitor->visit(shared_from_this());
}

ModExpression::ModExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right):
        left(std::move(left)), right(std::move(right)) {}

std::shared_ptr<Expression> ModExpression::get_left_exp() {
    return left;
}

std::shared_ptr<Expression> ModExpression::get_right_exp() {
    return right;
}

ModExpression::~ModExpression() = default;