#include "Statements.h"

Statements::Statements () = default;

void Statements::add_statement (std::shared_ptr<Statement> statement) {
  statements.push_back(std::move(statement));
}

const std::vector<std::shared_ptr<Statement>>& Statements::get_statements () {
  return statements;
}

void Statements::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

Statements::~Statements () = default;
