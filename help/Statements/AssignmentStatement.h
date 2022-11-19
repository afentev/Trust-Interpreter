#ifndef PARSEREXAMPLE_ASSIGNMENTSTATEMENT_H
#define PARSEREXAMPLE_ASSIGNMENTSTATEMENT_H

#include <string>
#include <memory>
#include "help/Expressions/Expression.h"

class AssignmentStatement: public Statement, public std::enable_shared_from_this<AssignmentStatement> {
public:
    AssignmentStatement(std::string id, std::shared_ptr<Expression> expression);
    std::string get_identifier();
    std::shared_ptr<Expression> get_expression();
    void accept(Visitor *visitor) override;
    ~AssignmentStatement() override;
private:
    std::string identifier;
    std::shared_ptr<Expression> expression;
};


#endif //PARSEREXAMPLE_ASSIGNMENTSTATEMENT_H
