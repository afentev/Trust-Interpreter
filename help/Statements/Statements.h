#ifndef PARSEREXAMPLE_STATEMENTS_H
#define PARSEREXAMPLE_STATEMENTS_H

#include <memory>
#include <vector>
#include "Statement.h"

class Statements: public Statement, public std::enable_shared_from_this<Statements> {
public:
    void add_statement(std::shared_ptr<Statement> statement);
    void accept(Visitor* visitor) override;

    const std::vector<std::shared_ptr<Statement>>& get_statements();

    ~Statements() override = default;

private:
    std::vector<std::shared_ptr<Statement>> statements;
};


#endif //PARSEREXAMPLE_STATEMENTS_H
