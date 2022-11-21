#include "help/Types/Object.h"

void Object::check_type (const std::string& operator_symbol, const Object* expected, const Object& got) {
  std::string given_type = got.get_type();
  std::string expected_type = expected->get_type();
  if (given_type != expected_type) {
    throw InterpretationException(
        "Invalid operands for operator" + operator_symbol + ": \"" + expected_type + "\" and \"" + given_type + "\"");
  }
}

Object::~Object () = default;
