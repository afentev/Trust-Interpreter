#include "Boolean.h"
#include "Integer.h"
#include "String.h"
#include "Float.h"

Integer::Integer (int32_t value) : number(value) {}

Integer& Integer::operator= (const Boolean& other) {
  throw InterpretationException("Can not assign bool to i32");
}

Integer& Integer::operator= (const Integer& other) {
  number = other.number;
  return *this;
}

Integer& Integer::operator= (const Float& other) {
  throw InterpretationException("Can not assign f64 to i32");
}

Integer& Integer::operator= (const String& other) {
  throw InterpretationException("Can not assign String to i32");
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

std::shared_ptr<Boolean> Integer::operator&& (const Object& other) {
  throw InterpretationException("Invalid operand type for operator&&. bool expected, but i32 found");
}

std::shared_ptr<Boolean> Integer::operator|| (const Object& other) {
  throw InterpretationException("Invalid operand type for operator||. bool expected, but i32 found");
}

std::shared_ptr<Boolean> Integer::operator! () {
  throw InterpretationException("Invalid operand type for operator!. bool expected, but i32 found");
}

std::shared_ptr<Object> Integer::operator- () {
  return std::make_shared<Integer>(-number);
}

std::shared_ptr<String> Integer::operator[] (int32_t pos) {
  throw InterpretationException("Invalid operand type for operator[]. String expected, but i32 found");
}

std::shared_ptr<Boolean> Integer::as_bool () {
  throw InterpretationException("Can not cast i32 to bool. Compare with zero instead");
}

std::shared_ptr<Integer> Integer::as_i32 () {
  return std::make_shared<Integer>(number);
}

std::shared_ptr<Float> Integer::as_f64 () {
  return std::make_shared<Float>(number);
}

std::shared_ptr<String> Integer::as_String () {
  throw InterpretationException("Can not cast i32 to String");
}

bool Integer::as_predicate () {
  throw InterpretationException("Invalid usage of type i32 in condition");
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
