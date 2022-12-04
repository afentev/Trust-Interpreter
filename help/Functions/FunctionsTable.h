#ifndef PARSEREXAMPLE_FUNCTIONSTABLE_H
#define PARSEREXAMPLE_FUNCTIONSTABLE_H

#include <memory>
#include <string>
#include <unordered_map>

class FunctionDeclaration;

class FunctionsTable {
 public:
  void add_function(std::shared_ptr<FunctionDeclaration> function);
  std::shared_ptr<FunctionDeclaration> get_function(const std::string& name);
  bool contains(const std::string& name);

 private:
  std::unordered_map<std::string, std::shared_ptr<FunctionDeclaration>> functions;
};


#endif //PARSEREXAMPLE_FUNCTIONSTABLE_H
