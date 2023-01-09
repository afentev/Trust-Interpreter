#include "AssignmentStatement.h"

AssignmentStatement::AssignmentStatement (std::string id, std::shared_ptr<Expression> expression) :
    identifier(std::move(id)), expression(std::move(expression)) {}

std::string AssignmentStatement::get_identifier () {
  return identifier;
}

std::shared_ptr<Expression> AssignmentStatement::get_expression () {
  return expression;
}

void AssignmentStatement::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

AssignmentStatement::~AssignmentStatement () = default;
