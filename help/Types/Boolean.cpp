#include "Boolean.h"

Boolean::Boolean (bool value) : value(value) {
  ;
}

Boolean& Boolean::operator= (const Boolean& other) {
  value = other.value;
  return *this;
}

Boolean& Boolean::operator= (const Integer& other) {
  throw "Can not assign i32 to bool";
}

Boolean& Boolean::operator= (const String& other) {
  throw "Can not assign String to bool";
}

void Boolean::assign_into (std::shared_ptr<Object> lhs) {
  lhs->operator=(*this);
}

std::shared_ptr<Object> Boolean::operator+ (const Object& other) {
  throw "Invalid operand type for operator&&. String or i32 expected, but bool found";
}

std::shared_ptr<Object> Boolean::operator- (const Object& other) {
  throw "Invalid operand type for operator&&. i32 expected, but bool found";
}

std::shared_ptr<Object> Boolean::operator* (const Object& other) {
  throw "Invalid operand type for operator&&. i32 expected, but bool found";
}

std::shared_ptr<Object> Boolean::operator/ (const Object& other) {
  throw "Invalid operand type for operator&&. i32 expected, but bool found";
}

std::shared_ptr<Object> Boolean::operator% (const Object& other) {
  throw "Invalid operand type for operator&&. i32 expected, but bool found";
}

std::shared_ptr<Boolean> Boolean::operator< (const Object& other) {
  return std::make_shared<Boolean>(value < dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator<= (const Object& other) {
  return std::make_shared<Boolean>(value <= dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator== (const Object& other) {
  return std::make_shared<Boolean>(value == dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator!= (const Object& other) {
  return std::make_shared<Boolean>(value != dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator>= (const Object& other) {
  return std::make_shared<Boolean>(value >= dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator> (const Object& other) {
  return std::make_shared<Boolean>(value > dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator&& (const Object& other) {
  return std::make_shared<Boolean>(value && dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator|| (const Object& other) {
  return std::make_shared<Boolean>(value || dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator! () {
  return std::make_shared<Boolean>(!value);
}

std::shared_ptr<Object> Boolean::operator- () {
  throw "Invalid operand type for operator&&. i32 expected, but bool found";
}

std::shared_ptr<String> Boolean::operator[] (int32_t pos) {
  throw "Invalid operand type for operator[]. String expected, but bool found";
}

bool Boolean::as_predicate () {
  return value;
}

std::string Boolean::as_string () {
  if (value) {
    return "true";
  } else {
    return "false";
  }
}

std::string Boolean::get_type () {
  return "bool";
}

void Boolean::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

Boolean::~Boolean () = default;
