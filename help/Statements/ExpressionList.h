#ifndef PARSEREXAMPLE_EXPRESSIONLIST_H
#define PARSEREXAMPLE_EXPRESSIONLIST_H

#include "help/Statements/Statements.h"

class ExpressionList : public Statement, public std::enable_shared_from_this<ExpressionList> {
 public:
  ExpressionList();

  void add_expression (std::shared_ptr<Expression> expression);
  std::shared_ptr<Expression> get_expression (size_t index);
  size_t subs_number ();

  void accept (Visitor* visitor) override;
  ~ExpressionList () override;

 private:
  std::vector<std::shared_ptr<Expression>> expressions;
};


#endif //PARSEREXAMPLE_EXPRESSIONLIST_H
