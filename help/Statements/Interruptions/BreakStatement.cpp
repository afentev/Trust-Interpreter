#include "BreakStatement.h"

BreakStatement::BreakStatement() = default;

void BreakStatement::accept(Visitor *visitor) {
    visitor->visit(shared_from_this());
}

BreakStatement::~BreakStatement() = default;
