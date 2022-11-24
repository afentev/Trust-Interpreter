#include "VectorValueExpression.h"

VectorValueExpression::VectorValueExpression (std::shared_ptr<Expression> value, std::shared_ptr<Expression> count)
    : value(std::move(value)), count(std::move(count)) {}

std::shared_ptr<Expression> VectorValueExpression::get_value () {
  return value;
}

std::shared_ptr<Expression> VectorValueExpression::get_count () {
  return count;
}

void VectorValueExpression::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

VectorValueExpression::~VectorValueExpression () = default;
