#ifndef PARSEREXAMPLE_FORSTATEMENT_H
#define PARSEREXAMPLE_FORSTATEMENT_H

#include <string>
#include <memory>
#include "Statement.h"
#include "help/Statements/Iterator.h"

class ForStatement: public Statement, public std::enable_shared_from_this<ForStatement> {
public:
    ForStatement(std::string var, std::shared_ptr<Iterator> iterator, std::shared_ptr<Statement> statement);
    void accept(Visitor* visitor) override;

    std::string get_variable();
    std::shared_ptr<Iterator> get_iterator();
    std::shared_ptr<Statement> get_statement();

    ~ForStatement() override;
private:
    std::string variable;
    std::shared_ptr<Iterator> iterator;
    std::shared_ptr<Statement> statement;
};


#endif //PARSEREXAMPLE_FORSTATEMENT_H
