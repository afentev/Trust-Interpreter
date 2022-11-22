#include "FunctionDeclaration.h"

FunctionDeclaration::FunctionDeclaration (std::string name, std::string return_type,
                                          std::shared_ptr<ParamList> params,
                                          std::shared_ptr<Statements> statements,
                                          std::shared_ptr<ReturnStatement> return_expression) : name(
    std::move(name)), return_type(std::move(return_type)), params(std::move(params)), statements(std::move(statements)),
    return_expression(std::move(return_expression)) {}

std::string FunctionDeclaration::get_name () {
  return name;
}

std::string FunctionDeclaration::get_return_type () {
  return return_type;
}

std::shared_ptr<ParamList> FunctionDeclaration::get_params () {
  return params;
}

std::shared_ptr<Statements> FunctionDeclaration::get_statements () {
  return statements;
}

std::shared_ptr<ReturnStatement> FunctionDeclaration::get_return_expression () {
  return return_expression;
}

void FunctionDeclaration::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

FunctionDeclaration::~FunctionDeclaration () = default;
