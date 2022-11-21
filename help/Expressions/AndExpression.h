#ifndef PARSEREXAMPLE_ANDEXPRESSION_H
#define PARSEREXAMPLE_ANDEXPRESSION_H

#include <memory>
#include "Expression.h"

class AndExpression : public Expression, public std::enable_shared_from_this<AndExpression> {
 public:
  AndExpression (std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);

  std::shared_ptr<Expression> get_left_exp ();

  std::shared_ptr<Expression> get_right_exp ();

  void accept (Visitor* visitor) override;

  ~AndExpression () override;

 private:
  std::shared_ptr<Expression> left;
  std::shared_ptr<Expression> right;
};


#endif //PARSEREXAMPLE_ANDEXPRESSION_H
