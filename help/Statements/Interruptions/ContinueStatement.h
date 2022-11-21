#ifndef PARSEREXAMPLE_CONTINUESTATEMENT_H
#define PARSEREXAMPLE_CONTINUESTATEMENT_H

#include <memory>
#include "help/Statements/Statement.h"
#include "help/Statements/Interruptions/Interruptions.h"

class ContinueStatement : public Statement, public std::enable_shared_from_this<ContinueStatement> {
 public:
  ContinueStatement ();

  void accept (Visitor* visitor) override;

  ~ContinueStatement () override;
};


#endif //PARSEREXAMPLE_CONTINUESTATEMENT_H
