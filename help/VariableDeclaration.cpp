#include "VariableDeclaration.h"

void VariableDeclaration::accept(Visitor* visitor) {
    visitor->visit(shared_from_this());
}

VariableDeclaration::VariableDeclaration(std::string var_name, std::string var_type):
        variable_name(std::move(var_name)), variable_type(std::move(var_type)) {
}

VariableDeclaration::~VariableDeclaration() = default;