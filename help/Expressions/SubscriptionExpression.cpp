#include "SubscriptionExpression.h"

SubscriptionExpression::SubscriptionExpression (std::shared_ptr<IDExpression> lhs, std::shared_ptr<Expression> index)
    : lhs(std::move(lhs)), index(std::move(index)) {}

std::shared_ptr<IDExpression> SubscriptionExpression::get_lhs () {
  return lhs;
}

std::shared_ptr<Expression> SubscriptionExpression::get_index () {
  return index;
}

void SubscriptionExpression::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

SubscriptionExpression::~SubscriptionExpression () = default;
