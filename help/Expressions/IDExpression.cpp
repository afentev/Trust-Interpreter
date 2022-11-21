#include "IDExpression.h"

void IDExpression::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

IDExpression::IDExpression (std::string id) : identifier(std::move(id)) {}

std::string IDExpression::get_id () {
  return identifier;
}

