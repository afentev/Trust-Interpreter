#include "ContinueStatement.h"

ContinueStatement::ContinueStatement() = default;

void ContinueStatement::accept(Visitor* visitor) {
    visitor->visit(shared_from_this());
}

ContinueStatement::~ContinueStatement() = default;
