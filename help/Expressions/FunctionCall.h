#ifndef PARSEREXAMPLE_FUNCTIONCALL_H
#define PARSEREXAMPLE_FUNCTIONCALL_H

#include "help/Expressions/Expression.h"
#include "help/Statements/ExpressionList.h"

class FunctionCall : public Expression, public std::enable_shared_from_this<FunctionCall> {
 public:
  FunctionCall (std::string name, std::shared_ptr<ExpressionList> arguments);

  std::string get_function_name ();
  std::shared_ptr<ExpressionList> get_arguments ();

  void accept (Visitor* visitor) override;
  ~FunctionCall () override;

 private:
  std::string function_name;
  std::shared_ptr<ExpressionList> arguments;
};


#endif //PARSEREXAMPLE_FUNCTIONCALL_H
