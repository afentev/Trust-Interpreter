#include "SizeExpression.h"

SizeExpression::SizeExpression (std::string id) : lhs(std::move(id)) {}

std::string SizeExpression::get_lhs () {
  return lhs;
}

void SizeExpression::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

SizeExpression::~SizeExpression () = default;
