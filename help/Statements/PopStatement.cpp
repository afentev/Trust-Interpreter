#include "PopStatement.h"

PopStatement::PopStatement (std::string id) : lhs(std::move(id)) {}

std::string PopStatement::get_lhs () {
  return lhs;
}

void PopStatement::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

PopStatement::~PopStatement () = default;
