#ifndef PARSEREXAMPLE_PRINTSTATEMENT_H
#define PARSEREXAMPLE_PRINTSTATEMENT_H

#include <string>
#include "help/Statements/Statement.h"
#include "help/Statements/ExpressionList.h"

class PrintStatement : public Statement, public std::enable_shared_from_this<PrintStatement> {
 public:
  PrintStatement (std::string format, bool new_line);

  PrintStatement (std::string format, std::shared_ptr<ExpressionList> subs, bool new_line);

  bool newline ();

  const std::string get_string ();

  std::shared_ptr<Expression> get_substitution (size_t index);

  size_t subs_number ();

  void accept (Visitor* visitor) override;

  ~PrintStatement ();

 private:
  std::string format_string;
  std::shared_ptr<ExpressionList> substitutors;
  bool add_newline;
};


#endif //PARSEREXAMPLE_PRINTSTATEMENT_H
