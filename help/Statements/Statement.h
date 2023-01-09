#ifndef PARSEREXAMPLE_STATEMENT_H
#define PARSEREXAMPLE_STATEMENT_H

#include "help/Visitor.h"

class Statement {
 public:
  virtual void accept (Visitor* visitor) = 0;
  virtual ~Statement () = default;
};

#endif //PARSEREXAMPLE_STATEMENT_H
