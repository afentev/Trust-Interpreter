#ifndef PARSEREXAMPLE_IDTABLE_H
#define PARSEREXAMPLE_IDTABLE_H

#include <stack>
#include <unordered_map>
#include "help/Identifiers/Identifier.h"
#include "help/InterpretationExceptions/InterpretationExceptions.h"

class IDTable {
 public:
  IDTable();

  void add_scope ();
  void left_scope ();
  void add_identifier (const std::string& name, std::shared_ptr<Object> obj, bool is_const, bool is_init);
  void mut_identifier (const std::string& name, std::shared_ptr<Object> value);
  bool is_mutable (const std::string& name);
  std::shared_ptr<Object> get_identifier (const std::string& name);
  uint16_t get_scope ();
  void reduce_scope (uint16_t new_scope);  // used when break or continue happens
  ~IDTable ();

 private:
  Identifier& safe_get_identifier(const std::string& name);
  void unwind_stack ();

  std::unordered_map<std::string, std::stack<Identifier>> identifiers;
  std::stack<std::string> stack;
  uint16_t current_scope = 0;
};


#endif //PARSEREXAMPLE_IDTABLE_H
