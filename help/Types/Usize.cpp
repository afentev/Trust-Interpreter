#include "Boolean.h"
#include "Integer.h"
#include "Float.h"
#include "Usize.h"

Usize::Usize (size_t value) : number(value) {}

Usize& Usize::operator= (const Usize& other) {
  number = other.number;
  return *this;
}

std::shared_ptr<Object> Usize::operator+ (const Object& other) {
  check_type("+", this, other);
  return std::make_shared<Usize>(number + dynamic_cast<const Usize&>(other).number);
}

std::shared_ptr<Object> Usize::operator- (const Object& other) {
  check_type("-", this, other);
  return std::make_shared<Usize>(number - dynamic_cast<const Usize&>(other).number);
}

std::shared_ptr<Object> Usize::operator* (const Object& other) {
  check_type("*", this, other);
  return std::make_shared<Usize>(number * dynamic_cast<const Usize&>(other).number);
}

std::shared_ptr<Object> Usize::operator/ (const Object& other) {
  check_type("/", this, other);
  return std::make_shared<Usize>(number / dynamic_cast<const Usize&>(other).number);
}

std::shared_ptr<Object> Usize::operator% (const Object& other) {
  check_type("%", this, other);
  return std::make_shared<Usize>(number % dynamic_cast<const Usize&>(other).number);
}

std::shared_ptr<Boolean> Usize::operator< (const Object& other) const {
  check_type("<", this, other);
  return std::make_shared<Boolean>(number < dynamic_cast<const Usize&>(other).number);
}

std::shared_ptr<Boolean> Usize::operator<= (const Object& other) const {
  check_type("<=", this, other);
  return std::make_shared<Boolean>(number <= dynamic_cast<const Usize&>(other).number);
}

std::shared_ptr<Boolean> Usize::operator== (const Object& other) const {
  check_type("==", this, other);
  return std::make_shared<Boolean>(number == dynamic_cast<const Usize&>(other).number);
}

std::shared_ptr<Boolean> Usize::operator!= (const Object& other) const {
  check_type("!=", this, other);
  return std::make_shared<Boolean>(number != dynamic_cast<const Usize&>(other).number);
}

std::shared_ptr<Boolean> Usize::operator>= (const Object& other) const {
  check_type(">=", this, other);
  return std::make_shared<Boolean>(number >= dynamic_cast<const Usize&>(other).number);
}

std::shared_ptr<Boolean> Usize::operator> (const Object& other) const {
  check_type(">", this, other);
  return std::make_shared<Boolean>(number > dynamic_cast<const Usize&>(other).number);
}

std::shared_ptr<Boolean> Usize::as_bool () {
  throw InterpretationException("Can not cast usize to bool. Compare with zero instead");
}

std::shared_ptr<Integer> Usize::as_i32 () {
  return std::make_shared<Integer>(number);
}

std::shared_ptr<Float> Usize::as_f64 () {
  return std::make_shared<Float>(number);
}

std::shared_ptr<Usize> Usize::as_usize () {
  return std::make_shared<Usize>(number);
}

std::string Usize::as_string () {
  return std::to_string(number);
}

size_t Usize::to_usize () const {
  return number;
}

std::string Usize::get_type () const {
  return "usize";
}

Object& Usize::operator++ () {
  ++number;
  return *this;
}

void Usize::assign_into (std::shared_ptr<Object> lhs) {
  lhs->operator=(*this);
}

void Usize::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

Usize::~Usize () = default;
