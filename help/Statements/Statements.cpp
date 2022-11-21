#include "Statements.h"

void Statements::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

const std::vector<std::shared_ptr<Statement>>& Statements::get_statements () {
  return statements;
}

void Statements::add_statement (std::shared_ptr<Statement> statement) {
  statements.push_back(statement);
}

Statements::~Statements () = default;