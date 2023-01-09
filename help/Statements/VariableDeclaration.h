#ifndef PARSEREXAMPLE_VARIABLEDECLARATION_H
#define PARSEREXAMPLE_VARIABLEDECLARATION_H

#include "Statement.h"

class VariableDeclaration : public Statement, public std::enable_shared_from_this<VariableDeclaration> {
 public:
  explicit VariableDeclaration (std::string var_name, std::string var_type);

  std::string get_name ();
  std::string get_type ();

  void accept (Visitor* visitor) override;
  ~VariableDeclaration () override;

 private:
  const std::string variable_name;
  const std::string variable_type;
};


#endif //PARSEREXAMPLE_VARIABLEDECLARATION_H
