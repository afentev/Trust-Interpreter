#ifndef PARSEREXAMPLE_OREXPRESSION_H
#define PARSEREXAMPLE_OREXPRESSION_H

#include <memory>
#include "Expression.h"

class OrExpression : public Expression, public std::enable_shared_from_this<OrExpression> {
 public:
  OrExpression (std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);

  std::shared_ptr<Expression> get_left_exp ();

  std::shared_ptr<Expression> get_right_exp ();

  void accept (Visitor* visitor) override;

  ~OrExpression () override;

 private:
  std::shared_ptr<Expression> left;
  std::shared_ptr<Expression> right;
};


#endif //PARSEREXAMPLE_OREXPRESSION_H
