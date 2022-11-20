#ifndef PARSEREXAMPLE_FORSTATEMENT_H
#define PARSEREXAMPLE_FORSTATEMENT_H

#include <string>
#include <memory>
#include "Statement.h"

class ForStatement: public Statement, public std::enable_shared_from_this<ForStatement> {
public:
    ForStatement(std::string var, std::shared_ptr<Expression> start, std::shared_ptr<Expression> end,
                 std::shared_ptr<Statement> statement, bool inclusivity, bool constantness):
        variable(std::move(var)), start(std::move(start)), end(std::move(end)), statement(std::move(statement)),
        inclusivity(inclusivity), is_const(constantness)
         {}

    void accept(Visitor* visitor) override {
        visitor->visit(this->shared_from_this());
    }

    std::shared_ptr<Expression> get_start() {
        return start;
    }

    std::shared_ptr<Expression> get_end() {
        return end;
    }
    
    std::string get_variable() {
        return variable;
    }

    bool get_inclusivity() {
        return inclusivity;
    }

    bool is_var_const() {
        return is_const;
    }

    std::shared_ptr<Statement> get_statement() {
        return statement;
    }

    ~ForStatement() override = default;
private:
    std::string variable;
    std::shared_ptr<Expression> start;
    std::shared_ptr<Expression> end;
    std::shared_ptr<Statement> statement;
    bool inclusivity;
    bool is_const;
};


#endif //PARSEREXAMPLE_FORSTATEMENT_H
