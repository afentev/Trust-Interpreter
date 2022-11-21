#include "ExpressionList.h"

void ExpressionList::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

void ExpressionList::add_expression (std::shared_ptr<Expression> expression) {
  expressions.push_back(expression);
}

std::shared_ptr<Expression> ExpressionList::get_expression (size_t index) {
  if (index >= expressions.size()) {
    throw "Attempt to extract more values than were passed";
  }
  return expressions[index];
}

size_t ExpressionList::subs_number () {
  return expressions.size();
}

ExpressionList::~ExpressionList () = default;
