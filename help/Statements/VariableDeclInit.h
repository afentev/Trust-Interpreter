#ifndef PARSEREXAMPLE_VARIABLEDECLINIT_H
#define PARSEREXAMPLE_VARIABLEDECLINIT_H

#include "Statement.h"

class VariableDeclInit : public Statement, public std::enable_shared_from_this<VariableDeclInit> {
 public:
  explicit VariableDeclInit (std::string var_name, std::string var_type, bool constantness,
                             std::shared_ptr<Expression> expr);

  std::shared_ptr<Expression> get_value ();
  std::string get_name ();
  std::string get_type ();
  bool is_const ();

  void accept (Visitor* visitor) override;
  ~VariableDeclInit () override;

 private:
  const std::string variable_name;
  const std::string variable_type;
  std::shared_ptr<Expression> value;
  bool is_constant;
};


#endif //PARSEREXAMPLE_VARIABLEDECLINIT_H
