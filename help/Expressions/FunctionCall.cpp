#include "FunctionCall.h"

FunctionCall::FunctionCall (std::string name, std::shared_ptr<ExpressionList> arguments) : function_name(
    std::move(name)), arguments(std::move(arguments)) {}

std::string FunctionCall::get_function_name () {
  return function_name;
}

std::shared_ptr<ExpressionList> FunctionCall::get_arguments () {
  return arguments;
}

void FunctionCall::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

FunctionCall::~FunctionCall () = default;
