#ifndef PARSEREXAMPLE_SUBSCRIPTIONASSIGNMENT_H
#define PARSEREXAMPLE_SUBSCRIPTIONASSIGNMENT_H

#include <memory>
#include "help/Expressions/IDExpression.h"

class SubscriptionAssignment : public Statement, public std::enable_shared_from_this<SubscriptionAssignment> {
 public:
  SubscriptionAssignment (std::string lhs, std::shared_ptr<Expression> index,
                          std::shared_ptr<Expression> rhs);

  std::string get_lhs ();
  std::shared_ptr<Expression> get_index ();
  std::shared_ptr<Expression> get_rhs ();

  void accept (Visitor* visitor) override;
  ~SubscriptionAssignment () override;

 private:
  std::string lhs;
  std::shared_ptr<Expression> index;
  std::shared_ptr<Expression> rhs;
};


#endif //PARSEREXAMPLE_SUBSCRIPTIONASSIGNMENT_H
