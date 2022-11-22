#include "Boolean.h"
#include "Integer.h"
#include "String.h"
#include "Float.h"
#include "Usize.h"

Usize::Usize (size_t value) : number(value) {}

Usize& Usize::operator= (const Boolean& other) {
  throw InterpretationException("Can not assign bool to usize");
}

Usize& Usize::operator= (const Integer& other) {
  throw InterpretationException("Can not assign i32 to usize");
}

Usize& Usize::operator= (const Float& other) {
  throw InterpretationException("Can not assign f64 to usize");
}

Usize& Usize::operator= (const String& other) {
  throw InterpretationException("Can not assign String to usize");
}

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

std::shared_ptr<Boolean> Usize::operator< (const Object& other) {
  check_type("<", this, other);
  return std::make_shared<Boolean>(number < dynamic_cast<const Usize&>(other).number);
}

std::shared_ptr<Boolean> Usize::operator<= (const Object& other) {
  check_type("<=", this, other);
  return std::make_shared<Boolean>(number <= dynamic_cast<const Usize&>(other).number);
}

std::shared_ptr<Boolean> Usize::operator== (const Object& other) const {
  check_type("==", this, other);
  return std::make_shared<Boolean>(number == dynamic_cast<const Usize&>(other).number);
}

std::shared_ptr<Boolean> Usize::operator!= (const Object& other) {
  check_type("!=", this, other);
  return std::make_shared<Boolean>(number != dynamic_cast<const Usize&>(other).number);
}

std::shared_ptr<Boolean> Usize::operator>= (const Object& other) {
  check_type(">=", this, other);
  return std::make_shared<Boolean>(number >= dynamic_cast<const Usize&>(other).number);
}

std::shared_ptr<Boolean> Usize::operator> (const Object& other) {
  check_type(">", this, other);
  return std::make_shared<Boolean>(number > dynamic_cast<const Usize&>(other).number);
}

std::shared_ptr<Boolean> Usize::operator&& (const Object& other) {
  throw InterpretationException("Invalid operand type for operator&&. bool expected, but usize found");
}

std::shared_ptr<Boolean> Usize::operator|| (const Object& other) {
  throw InterpretationException("Invalid operand type for operator||. bool expected, but usize found");
}

std::shared_ptr<Boolean> Usize::operator! () {
  throw InterpretationException("Invalid operand type for operator!. bool expected, but usize found");
}

std::shared_ptr<Object> Usize::operator- () {
  throw InterpretationException("Invalid operand type for operator-. i32 expected, but usize found");
}

std::shared_ptr<String> Usize::operator[] (int32_t pos) {
  throw InterpretationException("Invalid operand type for operator[]. String expected, but usize found");
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

std::shared_ptr<String> Usize::as_String () {
  throw InterpretationException("Can not cast usize to String");
}

std::shared_ptr<Usize> Usize::as_usize () {
  return std::make_shared<Usize>(number);
}

bool Usize::as_predicate () {
  throw InterpretationException("Invalid usage of type usize in condition");
}

std::string Usize::as_string () {
  return std::to_string(number);
}

std::string Usize::get_type () const {
  return "usize";
}

void Usize::assign_into (std::shared_ptr<Object> lhs) {
  lhs->operator=(*this);
}

void Usize::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

Usize::~Usize () = default;
