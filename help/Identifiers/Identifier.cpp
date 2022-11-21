#include "Identifier.h"

#include "help/Types/ObjectCreation.h"

Identifier::Identifier (std::shared_ptr<Object> obj, uint8_t layer, bool is_const, bool is_init) :
    object(std::move(obj)), scope_layer(layer), is_constant(is_const), _is_initialised(is_init) {}

std::shared_ptr<Object> Identifier::get_object () {
  return object;
}

void Identifier::set_object (std::shared_ptr<Object> value) {
  value->assign_into(object);
}

uint8_t Identifier::get_scope () {
  return scope_layer;
}

bool Identifier::get_constantness () {
  return is_constant;
}

bool Identifier::is_initialised () {
  return _is_initialised;
}

void Identifier::set_initialised (bool new_value) {
  _is_initialised = new_value;
}

Identifier::~Identifier () = default;
