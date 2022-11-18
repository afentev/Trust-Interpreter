#include "VariableDeclInit.h"

void VariableDeclInit::accept(Visitor* visitor) {
    visitor->visit(shared_from_this());
}

VariableDeclInit::VariableDeclInit(std::string var_name, std::string var_type, bool constantness,
                                   std::shared_ptr<Expression> expr):
        variable_name(std::move(var_name)), variable_type(std::move(var_type)), is_constant(constantness),
        value(std::move(expr)) {}

VariableDeclInit::~VariableDeclInit() = default;