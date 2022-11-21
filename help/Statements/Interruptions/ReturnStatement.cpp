#include "ReturnStatement.h"

ReturnStatement::ReturnStatement () = default;

void ReturnStatement::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

ReturnStatement::~ReturnStatement () = default;
