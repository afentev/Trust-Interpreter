#ifndef PARSEREXAMPLE_FORSTATEMENT_H
#define PARSEREXAMPLE_FORSTATEMENT_H

#include "Statement.h"

class ForStatement : public Statement, public std::enable_shared_from_this<ForStatement> {
 public:
  ForStatement (std::string var, std::shared_ptr<Expression> start, std::shared_ptr<Expression> end,
                std::shared_ptr<Statement> statement, bool inclusivity, bool constantness);

  std::shared_ptr<Expression> get_start ();
  std::shared_ptr<Expression> get_end ();
  std::shared_ptr<Statement> get_statement ();
  std::string get_variable ();
  bool get_inclusivity ();
  bool is_var_const ();

  void accept (Visitor* visitor) override;
  ~ForStatement () override;

 private:
  std::string variable;
  std::shared_ptr<Expression> start;
  std::shared_ptr<Expression> end;
  std::shared_ptr<Statement> statement;
  bool inclusivity;
  bool is_const;
};


#endif //PARSEREXAMPLE_FORSTATEMENT_H
