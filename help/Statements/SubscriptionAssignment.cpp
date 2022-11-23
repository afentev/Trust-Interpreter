#include "SubscriptionAssignment.h"

SubscriptionAssignment::SubscriptionAssignment (std::string lhs, std::shared_ptr<Expression> index,
                                                std::shared_ptr<Expression> rhs) : lhs(std::move(lhs)),
                                                                                   index(std::move(index)),
                                                                                   rhs(std::move(rhs)) {}

std::string SubscriptionAssignment::get_lhs () {
  return lhs;
}

std::shared_ptr<Expression> SubscriptionAssignment::get_index () {
  return index;
}

std::shared_ptr<Expression> SubscriptionAssignment::get_rhs () {
  return rhs;
}

void SubscriptionAssignment::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

SubscriptionAssignment::~SubscriptionAssignment () = default;
