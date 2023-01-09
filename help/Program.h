#ifndef PARSEREXAMPLE_PROGRAM_H
#define PARSEREXAMPLE_PROGRAM_H

#include <utility>
#include "help/Functions/FunctionDeclarationList.h"

class Program {
 public:
  Program (std::shared_ptr<FunctionDeclarationList> functions);

  std::shared_ptr<FunctionDeclarationList> get_functions ();

 private:
  std::shared_ptr<FunctionDeclarationList> functions;
};


#endif //PARSEREXAMPLE_PROGRAM_H
