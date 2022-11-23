#include "Boolean.h"
#include "Integer.h"
#include "String.h"
#include "Float.h"
#include "Usize.h"
#include "Char.h"

Float::Float (double value) : number(value) {}

Float& Float::operator= (const Float& other) {
  number = other.number;
  return *this;
}

std::shared_ptr<Object> Float::operator+ (const Object& other) {
  check_type("+", this, other);
  return std::make_shared<Float>(number + dynamic_cast<const Float&>(other).number);
}

std::shared_ptr<Object> Float::operator- (const Object& other) {
  check_type("-", this, other);
  return std::make_shared<Float>(number - dynamic_cast<const Float&>(other).number);
}

std::shared_ptr<Object> Float::operator* (const Object& other) {
  check_type("*", this, other);
  return std::make_shared<Float>(number * dynamic_cast<const Float&>(other).number);
}

std::shared_ptr<Object> Float::operator/ (const Object& other) {
  check_type("/", this, other);
  return std::make_shared<Float>(number / dynamic_cast<const Float&>(other).number);
}

std::shared_ptr<Boolean> Float::operator< (const Object& other) {
  check_type("<", this, other);
  return std::make_shared<Boolean>(number < dynamic_cast<const Float&>(other).number);
}

std::shared_ptr<Boolean> Float::operator<= (const Object& other) {
  check_type("<=", this, other);
  return std::make_shared<Boolean>(number <= dynamic_cast<const Float&>(other).number);
}

std::shared_ptr<Boolean> Float::operator== (const Object& other) const {
  check_type("==", this, other);
  return std::make_shared<Boolean>(number == dynamic_cast<const Float&>(other).number);
}

std::shared_ptr<Boolean> Float::operator!= (const Object& other) {
  check_type("!=", this, other);
  return std::make_shared<Boolean>(number != dynamic_cast<const Float&>(other).number);
}

std::shared_ptr<Boolean> Float::operator>= (const Object& other) {
  check_type(">=", this, other);
  return std::make_shared<Boolean>(number >= dynamic_cast<const Float&>(other).number);
}

std::shared_ptr<Boolean> Float::operator> (const Object& other) {
  check_type(">", this, other);
  return std::make_shared<Boolean>(number > dynamic_cast<const Float&>(other).number);
}

std::shared_ptr<Object> Float::operator- () {
  return std::make_shared<Float>(-number);
}

std::shared_ptr<Integer> Float::as_i32 () {
  return std::make_shared<Integer>(static_cast<int32_t>(number));
}

std::shared_ptr<Float> Float::as_f64 () {
  return std::make_shared<Float>(number);
}

std::shared_ptr<Usize> Float::as_usize () {
  if (number <= 0) {
    return std::make_shared<Usize>(0);
  }
  return std::make_shared<Usize>(static_cast<size_t>(number));
}

std::string Float::as_string () {
  return std::to_string(number);
}

std::string Float::get_type () const {
  return "f64";
}

void Float::assign_into (std::shared_ptr<Object> lhs) {
  lhs->operator=(*this);
}

void Float::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

Float::~Float () = default;
