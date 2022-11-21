#ifndef PARSEREXAMPLE_BREAKSTATEMENT_H
#define PARSEREXAMPLE_BREAKSTATEMENT_H

#include "help/Statements/Statement.h"

class BreakStatement : public Statement, public std::enable_shared_from_this<BreakStatement> {
 public:
  BreakStatement ();

  void accept (Visitor* visitor) override;
  ~BreakStatement () override;
};


#endif //PARSEREXAMPLE_BREAKSTATEMENT_H
