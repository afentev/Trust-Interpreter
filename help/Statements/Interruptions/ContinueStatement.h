#ifndef PARSEREXAMPLE_CONTINUESTATEMENT_H
#define PARSEREXAMPLE_CONTINUESTATEMENT_H

#include "help/Statements/Statement.h"

class ContinueStatement : public Statement, public std::enable_shared_from_this<ContinueStatement> {
 public:
  ContinueStatement ();

  void accept (Visitor* visitor) override;
  ~ContinueStatement () override;
};


#endif //PARSEREXAMPLE_CONTINUESTATEMENT_H
