#include "TypelessVariableDecl.h"

TypelessVariableDecl::TypelessVariableDecl (std::string var_name, bool constantness,
                                            std::shared_ptr<Expression> expr) :
    variable_name(std::move(var_name)), is_constant(constantness),
    value(std::move(expr)) {}

std::shared_ptr<Expression> TypelessVariableDecl::get_value () {
  return value;
}

std::string TypelessVariableDecl::get_name () {
  return variable_name;
}

bool TypelessVariableDecl::is_const () {
  return is_constant;
}

void TypelessVariableDecl::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

TypelessVariableDecl::~TypelessVariableDecl () = default;
