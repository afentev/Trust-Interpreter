#ifndef PARSEREXAMPLE_RETURNSTATEMENT_H
#define PARSEREXAMPLE_RETURNSTATEMENT_H

#include "help/Statements/Statement.h"

class ReturnStatement : public Statement, public std::enable_shared_from_this<ReturnStatement> {
 public:
  ReturnStatement (std::shared_ptr<Expression> value);

  std::shared_ptr<Expression> get_value();

  void accept (Visitor* visitor) override;
  ~ReturnStatement () override;

 private:
  std::shared_ptr<Expression> value;
};


#endif //PARSEREXAMPLE_RETURNSTATEMENT_H
