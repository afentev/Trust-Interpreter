#include "Boolean.h"
#include "Integer.h"
#include "String.h"
#include "Float.h"

Float::Float (double value) : number(value) {};

Float& Float::operator= (const Boolean& other) {
  throw InterpretationException("Can not assign bool to f64");
}

Float& Float::operator= (const Integer& other) {
  throw InterpretationException("Can not assign i32 to f64");
}

Float& Float::operator= (const Float& other) {
  number = other.number;
  return *this;
}

Float& Float::operator= (const String& other) {
  throw InterpretationException("Can not assign String to f64");
}

void Float::assign_into (std::shared_ptr<Object> lhs) {
  lhs->operator=(*this);
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

std::shared_ptr<Object> Float::operator% (const Object& other) {
  throw InterpretationException("Invalid operand type for operator%. i32 expected, but f64 found");
}

std::shared_ptr<Boolean> Float::operator< (const Object& other) {
  check_type("<", this, other);
  return std::make_shared<Boolean>(number < dynamic_cast<const Float&>(other).number);
}

std::shared_ptr<Boolean> Float::operator<= (const Object& other) {
  check_type("<=", this, other);
  return std::make_shared<Boolean>(number <= dynamic_cast<const Float&>(other).number);
}

std::shared_ptr<Boolean> Float::operator== (const Object& other) {
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

std::shared_ptr<Boolean> Float::operator&& (const Object& other) {
  throw InterpretationException("Invalid operand type for operator&&. bool expected, but f64 found");
}

std::shared_ptr<Boolean> Float::operator|| (const Object& other) {
  throw InterpretationException("Invalid operand type for operator||. bool expected, but f64 found");
}

std::shared_ptr<Boolean> Float::operator! () {
  throw InterpretationException("Invalid operand type for operator!. bool expected, but f64 found");
}

std::shared_ptr<Object> Float::operator- () {
  return std::make_shared<Float>(-number);
}

std::shared_ptr<String> Float::operator[] (int32_t pos) {
  throw InterpretationException("Invalid operand type for operator[]. String expected, but f64 found");
}

std::shared_ptr<Integer> Float::as_i32 () {
  return std::make_shared<Integer>(static_cast<int32_t>(number));
}

std::shared_ptr<Float> Float::as_f64 () {
  return std::make_shared<Float>(number);
}

std::shared_ptr<Boolean> Float::as_bool () {
  throw InterpretationException("Can not cast f64 to bool. Compare with zero instead");
}

std::shared_ptr<String> Float::as_String () {
  throw InterpretationException("Can not cast f64 to String");
}

bool Float::as_predicate () {
  throw InterpretationException("Invalid usage of type f64 in condition");
}

std::string Float::as_string () {
  return std::to_string(number);
}

std::string Float::get_type () const {
  return "f64";
}

void Float::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

Float::~Float () = default;
