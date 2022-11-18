#include "NotExpression.h"

void NotExpression::accept(Visitor* visitor) {

}

NotExpression::NotExpression(std::shared_ptr<Expression> expression): expression(std::move(expression)) {}

std::shared_ptr<Expression> NotExpression::get_expression() {
    return expression;
}

NotExpression::~NotExpression() = default;
