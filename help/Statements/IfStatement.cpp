#include "IfStatement.h"

IfStatement::IfStatement(std::shared_ptr<Expression> cond, std::shared_ptr<Statement> state):
        condition(std::move(cond)), statement(std::move(state)) {

}

void IfStatement::accept(Visitor *visitor) {
    visitor->visit(shared_from_this());
}

std::shared_ptr<Expression> IfStatement::get_condition() {
    return condition;
}

std::shared_ptr<Statement> IfStatement::get_statement() {
    return statement;
}

IfStatement::~IfStatement() = default;
