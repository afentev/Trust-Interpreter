#include "Boolean.h"
#include "Integer.h"
#include "String.h"
#include "Float.h"
#include "Usize.h"
#include "Char.h"

Integer::Integer (int32_t value) : number(value) {}

Integer& Integer::operator= (const Integer& other) {
  number = other.number;
  return *this;
}

std::shared_ptr<Object> Integer::operator+ (const Object& other) {
  check_type("+", this, other);
  return std::make_shared<Integer>(number + dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Object> Integer::operator- (const Object& other) {
  check_type("-", this, other);
  return std::make_shared<Integer>(number - dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Object> Integer::operator* (const Object& other) {
  check_type("*", this, other);
  return std::make_shared<Integer>(number * dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Object> Integer::operator/ (const Object& other) {
  check_type("/", this, other);
  return std::make_shared<Integer>(number / dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Object> Integer::operator% (const Object& other) {
  check_type("%", this, other);
  return std::make_shared<Integer>(number % dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Boolean> Integer::operator< (const Object& other) {
  check_type("<", this, other);
  return std::make_shared<Boolean>(number < dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Boolean> Integer::operator<= (const Object& other) {
  check_type("<=", this, other);
  return std::make_shared<Boolean>(number <= dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Boolean> Integer::operator== (const Object& other) const {
  check_type("==", this, other);
  return std::make_shared<Boolean>(number == dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Boolean> Integer::operator!= (const Object& other) {
  check_type("!=", this, other);
  return std::make_shared<Boolean>(number != dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Boolean> Integer::operator>= (const Object& other) {
  check_type(">=", this, other);
  return std::make_shared<Boolean>(number >= dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Boolean> Integer::operator> (const Object& other) {
  check_type(">", this, other);
  return std::make_shared<Boolean>(number > dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Object> Integer::operator- () {
  return std::make_shared<Integer>(-number);
}

std::shared_ptr<Integer> Integer::as_i32 () {
  return std::make_shared<Integer>(number);
}

std::shared_ptr<Float> Integer::as_f64 () {
  return std::make_shared<Float>(number);
}

std::shared_ptr<Usize> Integer::as_usize () {
  return std::make_shared<Usize>(static_cast<size_t>(number));
}

std::string Integer::as_string () {
  return std::to_string(number);
}

int32_t Integer::to_int () {
  return number;
}

std::string Integer::get_type () const {
  return "i32";
}

void Integer::assign_into (std::shared_ptr<Object> lhs) {
  lhs->operator=(*this);
}

void Integer::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

Integer::~Integer () = default;
