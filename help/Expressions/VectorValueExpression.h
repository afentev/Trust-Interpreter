#ifndef PARSEREXAMPLE_VECTORVALUEEXPRESSION_H
#define PARSEREXAMPLE_VECTORVALUEEXPRESSION_H

#include "help/Expressions/Expression.h"
#include "help/Statements/ExpressionList.h"

class VectorValueExpression : public Expression, public std::enable_shared_from_this<VectorValueExpression> {
 public:
  VectorValueExpression (std::shared_ptr<Expression> value, std::shared_ptr<Expression> count);

  std::shared_ptr<Expression> get_value ();
  std::shared_ptr<Expression> get_count ();

  void accept (Visitor* visitor) override;
  ~VectorValueExpression () override;

 private:
  std::shared_ptr<Expression> value;
  std::shared_ptr<Expression> count;
};


#endif //PARSEREXAMPLE_VECTORVALUEEXPRESSION_H
