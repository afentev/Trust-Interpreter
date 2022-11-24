#include "IDTable.h"

#include "help/Types/ObjectCreation.h"

IDTable::IDTable () = default;

void IDTable::add_scope () {
  ++current_scope;
}

void IDTable::left_scope () {
  --current_scope;
  unwind_stack();
}

void IDTable::add_identifier (const std::string& name, std::shared_ptr<Object> obj, bool is_const, bool is_init) {
  Identifier id(create_object(obj->get_type()), get_scope(), is_const, is_init);
  id.set_object(obj);
  stack.push(name);
  identifiers[name].push(id);
}

void IDTable::mut_identifier (const std::string& name, std::shared_ptr<Object> value) {
  Identifier& object = safe_get_identifier(name);
  if (object.get_constantness()) {
    throw InterpretationException("Attempt of modifying non-mut identifier \"" + name + "\"");
  }
  object.set_object(std::move(value));
  object.set_initialised(true);
}

void IDTable::set_mutability (const std::string& name, bool new_value) {
  Identifier& object = safe_get_identifier(name);
  object.set_constantness(!new_value);
}

bool IDTable::is_mutable (const std::string& name) {
  Identifier& object = safe_get_identifier(name);
  return !object.get_constantness();
}

std::shared_ptr<Object> IDTable::get_identifier (const std::string& name) {
  Identifier& object = safe_get_identifier(name);
  if (!object.is_initialised()) {
    throw InterpretationException("Use of uninitialised variable \"" + name + "\"");
  }
  return object.get_object();
}

uint16_t IDTable::get_scope () {
  return current_scope;
}

void IDTable::reduce_scope (uint16_t new_scope) {
  current_scope = new_scope;
  unwind_stack();
}

Identifier& IDTable::safe_get_identifier (const std::string& name) {
  auto var_stack = identifiers.find(name);
  if (var_stack == identifiers.end()) {
    throw InterpretationException("Use of undeclared variable \"" + name + "\"");
  } else if (var_stack->second.empty()) {
    throw InterpretationException("Use of undeclared variable \"" + name + "\". It probably went out of scope");
  }
  return var_stack->second.top();
}

void IDTable::unwind_stack () {
  while (!stack.empty() && identifiers.at(stack.top()).top().get_scope() > current_scope) {
    identifiers.at(stack.top()).pop();
    stack.pop();
  }
}

IDTable::~IDTable () = default;
