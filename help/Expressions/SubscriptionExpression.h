#ifndef PARSEREXAMPLE_SUBSCRIPTIONEXPRESSION_H
#define PARSEREXAMPLE_SUBSCRIPTIONEXPRESSION_H

#include <memory>
#include "help/Expressions/IDExpression.h"

class SubscriptionExpression : public Expression, public std::enable_shared_from_this<SubscriptionExpression> {
 public:
  SubscriptionExpression (std::shared_ptr<IDExpression> lhs, std::shared_ptr<Expression> index);

  std::shared_ptr<IDExpression> get_lhs ();
  std::shared_ptr<Expression> get_index ();

  void accept (Visitor* visitor) override;
  ~SubscriptionExpression () override;

 private:
  std::shared_ptr<IDExpression> lhs;
  std::shared_ptr<Expression> index;
};


#endif //PARSEREXAMPLE_SUBSCRIPTIONEXPRESSION_H
