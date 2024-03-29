#include "VariableDeclaration.h"

VariableDeclaration::VariableDeclaration (std::string var_name, std::string var_type) :
    variable_name(std::move(var_name)), variable_type(std::move(var_type)) {}

std::string VariableDeclaration::get_name () {
  return variable_name;
}

std::string VariableDeclaration::get_type () {
  return variable_type;
}

void VariableDeclaration::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

VariableDeclaration::~VariableDeclaration () = default;
