#include "PrintStatement.h"

PrintStatement::PrintStatement (std::string format, bool new_line) :
    format_string(std::move(format)), add_newline(new_line) {}

PrintStatement::PrintStatement (std::string format, std::shared_ptr<ExpressionList> subs, bool new_line) :
    format_string(std::move(format)), substitutors(std::move(subs)), add_newline(new_line) {}

bool PrintStatement::newline () {
  return add_newline;
}

const std::string PrintStatement::get_string () {
  return format_string;
}

std::shared_ptr<Expression> PrintStatement::get_substitution (size_t index) {
  return substitutors->get_expression(index);
}

size_t PrintStatement::subs_number () {
  return substitutors->subs_number();
}

void PrintStatement::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

PrintStatement::~PrintStatement () = default;
