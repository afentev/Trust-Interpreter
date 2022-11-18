#include "ForStatement.h"

ForStatement::ForStatement(std::string var, std::shared_ptr<Iterator> iterator,
                           std::shared_ptr<Statement> statement):
        variable(std::move(var)), iterator(std::move(iterator)), statement(std::move(statement)) {

}

void ForStatement::accept(Visitor *visitor) {
    visitor->visit(shared_from_this());
}

std::string ForStatement::get_variable() {
    return variable;
}

std::shared_ptr<Iterator> ForStatement::get_iterator() {
    return iterator;
}

std::shared_ptr<Statement> ForStatement::get_statement() {
    return statement;
}

ForStatement::~ForStatement() = default;
