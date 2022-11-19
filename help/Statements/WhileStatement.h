#ifndef PARSEREXAMPLE_WHILESTATEMENT_H
#define PARSEREXAMPLE_WHILESTATEMENT_H

#include <memory>
#include "Statement.h"

class WhileStatement: public Statement, public std::enable_shared_from_this<WhileStatement> {
public:
    WhileStatement(std::shared_ptr<Expression> cond, std::shared_ptr<Statement> state);
    void accept(Visitor* visitor) override;

    std::shared_ptr<Expression> get_condition();
    std::shared_ptr<Statement> get_statement();

    ~WhileStatement() override;
private:
    std::shared_ptr<Expression> condition;
    std::shared_ptr<Statement> statement;
};


#endif //PARSEREXAMPLE_WHILESTATEMENT_H
