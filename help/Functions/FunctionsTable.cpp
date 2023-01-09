#include "FunctionsTable.h"
#include "help/Functions/FunctionDeclaration.h"

void FunctionsTable::add_function (std::shared_ptr<FunctionDeclaration> function) {
  std::string function_name = function->get_name();
  if (functions.contains(function_name)) {
    throw InterpretationException("Two functions can not have the same name");
  }
  functions[function_name] = function;
}

std::shared_ptr<FunctionDeclaration> FunctionsTable::get_function (const std::string& name) {
  return functions.at(name);
}

bool FunctionsTable::contains(const std::string& name) {
  return functions.contains(name);
}
