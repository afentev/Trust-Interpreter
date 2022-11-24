#ifndef PARSEREXAMPLE_FORITERABLESTATEMENT_H
#define PARSEREXAMPLE_FORITERABLESTATEMENT_H

#include "Statement.h"

class ForIterableStatement : public Statement, public std::enable_shared_from_this<ForIterableStatement> {
 public:
  ForIterableStatement (std::string var, std::shared_ptr<Expression> iter,
                        std::shared_ptr<Statement> statement, bool constantness);

  std::shared_ptr<Expression> get_iter ();
  std::shared_ptr<Statement> get_statement ();
  std::string get_variable ();
  bool is_var_const ();

  void accept (Visitor* visitor) override;
  ~ForIterableStatement () override;

 private:
  std::string variable;
  std::shared_ptr<Expression> iterable;
  std::shared_ptr<Statement> statement;
  bool is_const;
};


#endif //PARSEREXAMPLE_FORITERABLESTATEMENT_H
