#include "ForIterableStatement.h"

ForIterableStatement::ForIterableStatement (std::string var, std::shared_ptr<Expression> iter,
                                            std::shared_ptr<Statement> statement, bool constantness) :
    variable(std::move(var)), iterable(std::move(iter)), statement(std::move(statement)), is_const(constantness) {}

std::shared_ptr<Expression> ForIterableStatement::get_iter () {
  return iterable;
}

std::shared_ptr<Statement> ForIterableStatement::get_statement () {
  return statement;
}

std::string ForIterableStatement::get_variable () {
  return variable;
}

bool ForIterableStatement::is_var_const () {
  return is_const;
}

void ForIterableStatement::accept (Visitor* visitor) {
  visitor->visit(this->shared_from_this());
}

ForIterableStatement::~ForIterableStatement () = default;
