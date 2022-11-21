#ifndef PARSEREXAMPLE_IDEXPRESSION_H
#define PARSEREXAMPLE_IDEXPRESSION_H

#include <memory>
#include <utility>
#include <string>
#include "Expression.h"

class IDExpression : public Expression, public std::enable_shared_from_this<IDExpression> {
 public:
  explicit IDExpression (std::string id);

  std::string get_id ();

  void accept (Visitor* visitor) override;
  ~IDExpression() override;

 private:
  std::string identifier;
};


#endif //PARSEREXAMPLE_IDEXPRESSION_H
