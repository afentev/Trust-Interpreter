#ifndef PARSEREXAMPLE_SIZEEXPRESSION_H
#define PARSEREXAMPLE_SIZEEXPRESSION_H

#include "help/Expressions/Expression.h"

class SizeExpression : public Expression, public std::enable_shared_from_this<SizeExpression> {
 public:
  SizeExpression (std::string id);

  std::string get_lhs ();

  void accept (Visitor* visitor) override;
  ~SizeExpression () override;

 private:
  std::string lhs;
};


#endif //PARSEREXAMPLE_SIZEEXPRESSION_H
