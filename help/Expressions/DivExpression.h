#ifndef PARSEREXAMPLE_DIVEXPRESSION_H
#define PARSEREXAMPLE_DIVEXPRESSION_H

#include <memory>
#include "Expression.h"

class DivExpression : public Expression, public std::enable_shared_from_this<DivExpression> {
 public:
  DivExpression (std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);

  std::shared_ptr<Expression> get_left_exp ();
  std::shared_ptr<Expression> get_right_exp ();

  void accept (Visitor* visitor) override;
  ~DivExpression () override;

 private:
  std::shared_ptr<Expression> left;
  std::shared_ptr<Expression> right;
};


#endif //PARSEREXAMPLE_DIVEXPRESSION_H
