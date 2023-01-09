#include "VariableDeclInit.h"

VariableDeclInit::VariableDeclInit (std::string var_name, std::string var_type, bool constantness,
                                    std::shared_ptr<Expression> expr) :
    variable_name(std::move(var_name)), variable_type(std::move(var_type)), is_constant(constantness),
    value(std::move(expr)) {}

std::shared_ptr<Expression> VariableDeclInit::get_value () {
  return value;
}

std::string VariableDeclInit::get_name () {
  return variable_name;
}

std::string VariableDeclInit::get_type () {
  return variable_type;
}

bool VariableDeclInit::is_const () {
  return is_constant;
}

void VariableDeclInit::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

VariableDeclInit::~VariableDeclInit () = default;
