#ifndef PARSEREXAMPLE_ASEXPRESSION_H
#define PARSEREXAMPLE_ASEXPRESSION_H

#include <memory>
#include "Expression.h"

class AsExpression : public Expression, public std::enable_shared_from_this<AsExpression> {
 public:
  AsExpression (std::shared_ptr<Expression> expression, std::string type);

  std::shared_ptr<Expression> get_expression ();
  std::string get_type ();

  void accept (Visitor* visitor) override;
  ~AsExpression () override;

 private:
  std::shared_ptr<Expression> expression;
  std::string type;
};


#endif //PARSEREXAMPLE_ASEXPRESSION_H
