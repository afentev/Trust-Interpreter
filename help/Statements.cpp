#include "Statements.h"

void Statements::accept(Visitor& visitor) {

}

void Statements::add_statement(std::shared_ptr<Statement> statement) {
    statements.push_back(statement);
}
