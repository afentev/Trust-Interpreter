#include "IfElifStatement.h"

IfElifStatement::IfElifStatement(std::shared_ptr<Expression> cond, std::shared_ptr<Statement> true_statement,
                                 std::shared_ptr<Statement> elif_statement):
        condition(std::move(cond)), true_statement(std::move(true_statement)),
        elif_statement(std::move(elif_statement)) {

}

void IfElifStatement::accept(Visitor *visitor) {
    visitor->visit(shared_from_this());
}

std::shared_ptr<Expression> IfElifStatement::get_condition() {
    return condition;
}

std::shared_ptr<Statement> IfElifStatement::get_true_statement() {
    return true_statement;
}

std::shared_ptr<Statement> IfElifStatement::get_elif_statement() {
    return elif_statement;
}

IfElifStatement::~IfElifStatement() = default;
