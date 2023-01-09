#ifndef PARSEREXAMPLE_FUNCTIONDECLARATION_H
#define PARSEREXAMPLE_FUNCTIONDECLARATION_H

#include "help/Functions/ParamList.h"

class FunctionDeclaration: public Statement, public std::enable_shared_from_this<FunctionDeclaration> {
 public:
  FunctionDeclaration (std::string name, std::string return_type, std::shared_ptr<ParamList> params,
                       std::shared_ptr<Statements> statements, std::shared_ptr<ReturnStatement> return_expression);

  std::string get_name ();
  std::string get_return_type ();
  std::shared_ptr<ParamList> get_params ();
  std::shared_ptr<Statements> get_statements ();
  std::shared_ptr<ReturnStatement> get_return_expression ();

  void accept (Visitor *visitor) override;
  ~FunctionDeclaration ();

 private:
  std::string name;
  std::string return_type;
  std::shared_ptr<ParamList> params;
  std::shared_ptr<Statements> statements;
  std::shared_ptr<ReturnStatement> return_expression;
};


#endif //PARSEREXAMPLE_FUNCTIONDECLARATION_H
