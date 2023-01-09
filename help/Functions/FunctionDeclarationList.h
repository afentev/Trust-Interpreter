#ifndef PARSEREXAMPLE_FUNCTIONDECLARATIONLIST_H
#define PARSEREXAMPLE_FUNCTIONDECLARATIONLIST_H

#include "help/Functions/FunctionDeclaration.h"

class FunctionDeclarationList : public Statement, public std::enable_shared_from_this<FunctionDeclarationList> {
 public:
  FunctionDeclarationList();

  void add_declaration (std::shared_ptr<FunctionDeclaration> declaration);
  const std::vector<std::shared_ptr<FunctionDeclaration>>& get_declarations ();

  void accept (Visitor* visitor) override;
  ~FunctionDeclarationList () override;

 private:
  std::vector<std::shared_ptr<FunctionDeclaration>> declarations;
};


#endif //PARSEREXAMPLE_FUNCTIONDECLARATIONLIST_H
