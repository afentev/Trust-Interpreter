#ifndef PARSEREXAMPLE_TYPELESSVARIABLEDECL_H
#define PARSEREXAMPLE_TYPELESSVARIABLEDECL_H

#include "Statement.h"

class TypelessVariableDecl : public Statement, public std::enable_shared_from_this<TypelessVariableDecl> {
 public:
  explicit TypelessVariableDecl (std::string var_name, bool constantness, std::shared_ptr<Expression> expr);

  std::shared_ptr<Expression> get_value ();
  std::string get_name ();
  bool is_const ();

  void accept (Visitor* visitor) override;
  ~TypelessVariableDecl () override;

 private:
  const std::string variable_name;
  std::shared_ptr<Expression> value;
  bool is_constant;
};


#endif //PARSEREXAMPLE_TYPELESSVARIABLEDECL_H
