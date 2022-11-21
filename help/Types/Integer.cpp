#include "Integer.h"

Integer::Integer (int32_t value) : number(value) {};

int32_t Integer::to_int () {
  return number;
}

Integer& Integer::operator= (const Boolean& other) {
  throw InterpretationException("Can not assign bool to i32");
}

Integer& Integer::operator= (const Integer& other) {
  number = other.number;
  return *this;
}

Integer& Integer::operator= (const String& other) {
  throw InterpretationException("Can not assign String to i32");
}

void Integer::assign_into (std::shared_ptr<Object> lhs) {
  lhs->operator=(*this);
}

std::shared_ptr<Object> Integer::operator+ (const Object& other) {
  return std::make_shared<Integer>(number + dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Object> Integer::operator- (const Object& other) {
  return std::make_shared<Integer>(number - dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Object> Integer::operator* (const Object& other) {
  return std::make_shared<Integer>(number * dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Object> Integer::operator/ (const Object& other) {
  return std::make_shared<Integer>(number / dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Object> Integer::operator% (const Object& other) {
  return std::make_shared<Integer>(number % dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Boolean> Integer::operator< (const Object& other) {
  return std::make_shared<Boolean>(number < dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Boolean> Integer::operator<= (const Object& other) {
  return std::make_shared<Boolean>(number <= dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Boolean> Integer::operator== (const Object& other) {
  return std::make_shared<Boolean>(number == dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Boolean> Integer::operator!= (const Object& other) {
  return std::make_shared<Boolean>(number != dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Boolean> Integer::operator>= (const Object& other) {
  return std::make_shared<Boolean>(number >= dynamic_cast<const Integer&>(other).number);
}

std::shared_ptr<Boolean> Integer::operator> (const Object& other) {
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

bool Integer::as_predicate () {
  throw InterpretationException("Invalid usage of type integer in condition");
}

std::string Integer::as_string () {
  return std::to_string(number);
}

std::string Integer::get_type () {
  return "i32";
}

void Integer::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

Integer::~Integer () = default;
