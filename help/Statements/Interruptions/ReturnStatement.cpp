#include "ReturnStatement.h"

ReturnStatement::ReturnStatement (std::shared_ptr<Expression> value) : value(std::move(value)) {}

std::shared_ptr<Expression> ReturnStatement::get_value () {
  return value;
}

void ReturnStatement::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

ReturnStatement::~ReturnStatement () = default;
