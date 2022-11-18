#ifndef PARSEREXAMPLE_STATEMENTS_H
#define PARSEREXAMPLE_STATEMENTS_H

#include <vector>
#include "help/Statement.h"

class Statements: public Statement {
public:
    void add_statement(std::shared_ptr<Statement> statement);
    void accept(Visitor* visitor) override;
    ~Statements() override = default;

    std::vector<std::shared_ptr<Statement>> statements;
};


#endif //PARSEREXAMPLE_STATEMENTS_H
