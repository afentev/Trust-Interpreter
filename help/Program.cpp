#include "Program.h"

Program::Program (std::shared_ptr<FunctionDeclarationList> functions) : functions(std::move(functions)) {}

std::shared_ptr<FunctionDeclarationList> Program::get_functions () {
  return functions;
}
