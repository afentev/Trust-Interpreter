#ifndef PARSEREXAMPLE_PROGRAM_H
#define PARSEREXAMPLE_PROGRAM_H

#include <memory>
#include "help/Statements/Statements.h"

class Program {
public:
    Program(std::shared_ptr<Statements> statements);
    std::shared_ptr<Statements> get_statements();

private:
    std::shared_ptr<Statements> statements;
};


#endif //PARSEREXAMPLE_PROGRAM_H
