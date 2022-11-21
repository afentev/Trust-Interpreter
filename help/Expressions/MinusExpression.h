#ifndef PARSEREXAMPLE_MINUSEXPRESSION_H
#define PARSEREXAMPLE_MINUSEXPRESSION_H

#include <memory>
#include "Expression.h"

class MinusExpression : public Expression, public std::enable_shared_from_this<MinusExpression> {
 public:
  MinusExpression (std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);

  std::shared_ptr<Expression> get_left_exp ();

  std::shared_ptr<Expression> get_right_exp ();

  void accept (Visitor* visitor) override;

  ~MinusExpression () override;

 private:
  std::shared_ptr<Expression> left;
  std::shared_ptr<Expression> right;
};


#endif //PARSEREXAMPLE_MINUSEXPRESSION_H
