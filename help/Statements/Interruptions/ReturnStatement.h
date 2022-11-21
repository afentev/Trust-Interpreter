#ifndef PARSEREXAMPLE_RETURNSTATEMENT_H
#define PARSEREXAMPLE_RETURNSTATEMENT_H

#include <memory>
#include "help/Statements/Statement.h"
#include "help/Statements/Interruptions/Interruptions.h"

class ReturnStatement : public Statement, public std::enable_shared_from_this<ReturnStatement> {
 public:
  ReturnStatement ();

  void accept (Visitor* visitor) override;

  ~ReturnStatement () override;
};


#endif //PARSEREXAMPLE_RETURNSTATEMENT_H
