#ifndef PARSEREXAMPLE_EXPRESSIONLIST_H
#define PARSEREXAMPLE_EXPRESSIONLIST_H

#include <memory>
#include <vector>
#include "help/Expressions/Expression.h"
#include "help/Statements/Statements.h"
#include "help/InterpretationExceptions/InterpretationExceptions.h"

class ExpressionList : public Statement, public std::enable_shared_from_this<ExpressionList> {
 public:
  void add_expression (std::shared_ptr<Expression> expression);

  void accept (Visitor* visitor) override;

  std::shared_ptr<Expression> get_expression (size_t index);

  size_t subs_number ();

  ~ExpressionList () override;

 private:
  std::vector<std::shared_ptr<Expression>> expressions;
};


#endif //PARSEREXAMPLE_EXPRESSIONLIST_H
