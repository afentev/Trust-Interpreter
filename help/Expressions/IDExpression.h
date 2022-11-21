#ifndef PARSEREXAMPLE_IDEXPRESSION_H
#define PARSEREXAMPLE_IDEXPRESSION_H

#include <memory>
#include <utility>
#include <string>
#include "Expression.h"

class IDExpression : public Expression, public std::enable_shared_from_this<IDExpression> {
 public:
  explicit IDExpression (std::string id);

  void accept (Visitor* visitor) override;

  std::string get_id ();

 private:
  std::string identifier;
};


#endif //PARSEREXAMPLE_IDEXPRESSION_H
