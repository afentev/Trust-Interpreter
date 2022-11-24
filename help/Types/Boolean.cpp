#include "Boolean.h"
#include "Integer.h"
#include "Usize.h"

Boolean::Boolean (bool value) : value(value) {}

Boolean& Boolean::operator= (const Boolean& other) {
  value = other.value;
  return *this;
}

std::shared_ptr<Boolean> Boolean::operator< (const Object& other) {
  check_type("<", this, other);
  return std::make_shared<Boolean>(value < dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator<= (const Object& other) {
  check_type("<=", this, other);
  return std::make_shared<Boolean>(value <= dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator== (const Object& other) const {
  check_type("==", this, other);
  return std::make_shared<Boolean>(value == dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator!= (const Object& other) {
  check_type("!=", this, other);
  return std::make_shared<Boolean>(value != dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator>= (const Object& other) {
  check_type(">=", this, other);
  return std::make_shared<Boolean>(value >= dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator> (const Object& other) {
  check_type(">", this, other);
  return std::make_shared<Boolean>(value > dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator&& (const Object& other) {
  check_type("&&", this, other);
  return std::make_shared<Boolean>(value && dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator|| (const Object& other) {
  check_type("||", this, other);
  return std::make_shared<Boolean>(value || dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator! () {
  return std::make_shared<Boolean>(!value);
}

std::shared_ptr<Boolean> Boolean::as_bool () {
  return std::make_shared<Boolean>(value);
}

std::shared_ptr<Integer> Boolean::as_i32 () {
  return std::make_shared<Integer>(value);
}

std::shared_ptr<Float> Boolean::as_f64 () {
  throw InterpretationException("Can not cast bool to f64. Cast through an i32 first");
}

std::shared_ptr<Usize> Boolean::as_usize () {
  return std::make_shared<Usize>(value);
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

std::string Boolean::get_type () const {
  return "bool";
}

void Boolean::assign_into (std::shared_ptr<Object> lhs) {
  lhs->operator=(*this);
}

void Boolean::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

Boolean::~Boolean () = default;
