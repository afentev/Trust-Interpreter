#ifndef PARSEREXAMPLE_VECTORENUMERATIONEXPRESSION_H
#define PARSEREXAMPLE_VECTORENUMERATIONEXPRESSION_H

#include "help/Expressions/Expression.h"
#include "help/Statements/ExpressionList.h"

class VectorEnumerationExpression
    : public Expression, public std::enable_shared_from_this<VectorEnumerationExpression> {
 public:
  VectorEnumerationExpression (std::shared_ptr<ExpressionList> values);

  std::shared_ptr<ExpressionList> get_values ();

  void accept (Visitor* visitor) override;
  ~VectorEnumerationExpression () override;

 private:
  std::shared_ptr<ExpressionList> values;
};


#endif //PARSEREXAMPLE_VECTORENUMERATIONEXPRESSION_H
