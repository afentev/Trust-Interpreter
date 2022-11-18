#ifndef PARSEREXAMPLE_IFELIFSTATEMENT_H
#define PARSEREXAMPLE_IFELIFSTATEMENT_H

#include <memory>
#include "help/Statement.h"

class IfElifStatement: public Statement, public std::enable_shared_from_this<IfElifStatement> {
public:
    IfElifStatement(std::shared_ptr<Expression> cond, std::shared_ptr<Statement> true_statement,
                    std::shared_ptr<Statement> elif_statement);
    void accept(Visitor* visitor) override;

    std::shared_ptr<Expression> get_condition();
    std::shared_ptr<Statement> get_elif_statement();
    std::shared_ptr<Statement> get_true_statement();

    ~IfElifStatement() override;
private:
    std::shared_ptr<Expression> condition;
    std::shared_ptr<Statement> true_statement;
    std::shared_ptr<Statement> elif_statement;
};

#endif //PARSEREXAMPLE_IFELIFSTATEMENT_H
