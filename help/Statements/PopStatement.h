#ifndef PARSEREXAMPLE_POPSTATEMENT_H
#define PARSEREXAMPLE_POPSTATEMENT_H

#include "help/Expressions/Expression.h"

class PopStatement : public Statement, public std::enable_shared_from_this<PopStatement> {
 public:
  PopStatement (std::string id);

  std::string get_lhs ();

  void accept (Visitor* visitor) override;
  ~PopStatement () override;

 private:
  std::string lhs;
};


#endif //PARSEREXAMPLE_POPSTATEMENT_H
