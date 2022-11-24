#include "VectorEnumerationExpression.h"

VectorEnumerationExpression::VectorEnumerationExpression (std::shared_ptr<ExpressionList> values) : values(
    std::move(values)) {}

std::shared_ptr<ExpressionList> VectorEnumerationExpression::get_values () {
  return values;
}

void VectorEnumerationExpression::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

VectorEnumerationExpression::~VectorEnumerationExpression () = default;
