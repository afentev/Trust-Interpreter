#ifndef PARSEREXAMPLE_IFSTATEMENT_H
#define PARSEREXAMPLE_IFSTATEMENT_H

#include "Statement.h"

class IfStatement : public Statement, public std::enable_shared_from_this<IfStatement> {
 public:
  IfStatement (std::shared_ptr<Expression> cond, std::shared_ptr<Statement> state);

  std::shared_ptr<Expression> get_condition ();
  std::shared_ptr<Statement> get_statement ();

  void accept (Visitor* visitor) override;
  ~IfStatement () override;

 private:
  std::shared_ptr<Expression> condition;
  std::shared_ptr<Statement> statement;
};


#endif //PARSEREXAMPLE_IFSTATEMENT_H
