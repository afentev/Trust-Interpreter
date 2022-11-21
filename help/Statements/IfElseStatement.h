#ifndef PARSEREXAMPLE_IFELSESTATEMENT_H
#define PARSEREXAMPLE_IFELSESTATEMENT_H

#include "Statement.h"

class IfElseStatement : public Statement, public std::enable_shared_from_this<IfElseStatement> {
 public:
  IfElseStatement (std::shared_ptr<Expression> cond, std::shared_ptr<Statement> true_statement,
                   std::shared_ptr<Statement> false_statement);

  std::shared_ptr<Expression> get_condition ();
  std::shared_ptr<Statement> get_true_statement ();
  std::shared_ptr<Statement> get_false_statement ();

  void accept (Visitor* visitor) override;
  ~IfElseStatement () override;

 private:
  std::shared_ptr<Expression> condition;
  std::shared_ptr<Statement> true_statement;
  std::shared_ptr<Statement> false_statement;
};


#endif //PARSEREXAMPLE_IFELSESTATEMENT_H
