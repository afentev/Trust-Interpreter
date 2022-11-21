#include "AssignmentStatement.h"

AssignmentStatement::AssignmentStatement (std::string id, std::shared_ptr<Expression> expression) :
    identifier(std::move(id)), expression(std::move(expression)) {

}

void AssignmentStatement::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

std::string AssignmentStatement::get_identifier () {
  return identifier;
}

std::shared_ptr<Expression> AssignmentStatement::get_expression () {
  return expression;
}

AssignmentStatement::~AssignmentStatement () = default;