#include "ForStatement.h"

ForStatement::ForStatement (std::string var, std::shared_ptr<Expression> start, std::shared_ptr<Expression> end,
                            std::shared_ptr<Statement> statement, bool inclusivity, bool constantness) :
    variable(std::move(var)), start(std::move(start)), end(std::move(end)), statement(std::move(statement)),
    inclusivity(inclusivity), is_const(constantness) {}

std::shared_ptr<Expression> ForStatement::get_start () {
  return start;
}

std::shared_ptr<Expression> ForStatement::get_end () {
  return end;
}

std::shared_ptr<Statement> ForStatement::get_statement () {
  return statement;
}

std::string ForStatement::get_variable () {
  return variable;
}

bool ForStatement::get_inclusivity () {
  return inclusivity;
}

bool ForStatement::is_var_const () {
  return is_const;
}

void ForStatement::accept (Visitor* visitor) {
  visitor->visit(this->shared_from_this());
}

ForStatement::~ForStatement () = default;
