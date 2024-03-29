#ifndef PARSEREXAMPLE_UNARYMINUSEXPRESSION_H
#define PARSEREXAMPLE_UNARYMINUSEXPRESSION_H

#include <memory>
#include "Expression.h"

class UnaryMinusExpression : public Expression, public std::enable_shared_from_this<UnaryMinusExpression> {
 public:
  UnaryMinusExpression (std::shared_ptr<Expression> expression);

  std::shared_ptr<Expression> get_expression ();

  void accept (Visitor* visitor) override;
  ~UnaryMinusExpression () override;

 private:
  std::shared_ptr<Expression> expression;
};


#endif //PARSEREXAMPLE_UNARYMINUSEXPRESSION_H
