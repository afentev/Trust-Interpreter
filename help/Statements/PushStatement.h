#ifndef PARSEREXAMPLE_PUSHSTATEMENT_H
#define PARSEREXAMPLE_PUSHSTATEMENT_H

#include "help/Expressions/Expression.h"

class PushStatement : public Statement, public std::enable_shared_from_this<PushStatement> {
 public:
  PushStatement (std::string id, std::shared_ptr<Expression> expression);

  std::string get_lhs ();
  std::shared_ptr<Expression> get_expression ();

  void accept (Visitor* visitor) override;
  ~PushStatement () override;

 private:
  std::string lhs;
  std::shared_ptr<Expression> expression;
};


#endif //PARSEREXAMPLE_PUSHSTATEMENT_H
