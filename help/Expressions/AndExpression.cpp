#include "AndExpression.h"

void AndExpression::accept(Visitor& visitor) {

}

AndExpression::AndExpression(std::shared_ptr<BaseExpression> left, std::shared_ptr<BaseExpression> right):
    left(std::move(left)), right(std::move(right)) {}

std::shared_ptr<BaseExpression> AndExpression::get_left_exp() {
    return left;
}

std::shared_ptr<BaseExpression> AndExpression::get_right_exp() {
    return right;
}

AndExpression::~AndExpression() = default;