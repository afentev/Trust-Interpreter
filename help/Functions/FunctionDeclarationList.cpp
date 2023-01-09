#include "FunctionDeclarationList.h"

FunctionDeclarationList::FunctionDeclarationList () = default;

void FunctionDeclarationList::add_declaration (std::shared_ptr<FunctionDeclaration> declaration) {
  declarations.push_back(std::move(declaration));
}

const std::vector<std::shared_ptr<FunctionDeclaration>>& FunctionDeclarationList::get_declarations () {
  return declarations;
}

void FunctionDeclarationList::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

FunctionDeclarationList::~FunctionDeclarationList () = default;
