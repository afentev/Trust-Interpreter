#include "help/Types/Object.h"
#include "help/Types/Vector.h"

Object& Object::operator= (const Boolean& other) {
  throw InterpretationException("Can not assign bool to " + get_type());
}

Object& Object::operator= (const Integer& other) {
  throw InterpretationException("Can not assign i32 to " + get_type());
}

Object& Object::operator= (const Float& other) {
  throw InterpretationException("Can not assign f64 to " + get_type());
}

Object& Object::operator= (const String& other) {
  throw InterpretationException("Can not assign String to " + get_type());
}

Object& Object::operator= (const Usize& other) {
  throw InterpretationException("Can not assign usize to " + get_type());
}

Object& Object::operator= (const Char& other) {
  throw InterpretationException("Can not assign char to " + get_type());
}

Object& Object::operator= (const Vector& other) {
  throw InterpretationException("Can not assign " + other.get_type() + " to " + get_type());
}

std::shared_ptr<Object> Object::operator+ (const Object& other) {
  throw InterpretationException("Invalid operand type for operator+: " + get_type());
}

std::shared_ptr<Object> Object::operator- (const Object& other) {
  throw InterpretationException("Invalid operand type for operator-: " + get_type());
}

std::shared_ptr<Object> Object::operator* (const Object& other) {
  throw InterpretationException("Invalid operand type for operator*: " + get_type());
}

std::shared_ptr<Object> Object::operator/ (const Object& other) {
  throw InterpretationException("Invalid operand type for operator/: " + get_type());
}

std::shared_ptr<Object> Object::operator% (const Object& other) {
  throw InterpretationException("Invalid operand type for operator%: " + get_type());
}

std::shared_ptr<Boolean> Object::operator&& (const Object& other) {
  throw InterpretationException("Invalid operand type for operator&&. bool expected, but " + get_type() + " found");
}

std::shared_ptr<Boolean> Object::operator|| (const Object& other) {
  throw InterpretationException("Invalid operand type for operator||. bool expected, but " + get_type() + " found");
}

std::shared_ptr<Boolean> Object::operator! () {
  throw InterpretationException("Invalid operand type for operator!. bool expected, but " + get_type() + " found");
}

std::shared_ptr<Object> Object::operator- () {
  throw InterpretationException("Invalid operand type for operator-: " + get_type());
}

std::shared_ptr<Object> Object::operator[] (const Object& pos) {
  throw InterpretationException("Invalid operand type for operator[]: " + get_type());
}

std::shared_ptr<Boolean> Object::as_bool () {
  throw InterpretationException("Can not cast " + get_type() + " to bool");
}

std::shared_ptr<Integer> Object::as_i32 () {
  throw InterpretationException("Can not cast " + get_type() + " to i32");
}

std::shared_ptr<Float> Object::as_f64 () {
  throw InterpretationException("Can not cast " + get_type() + " to f64");
}

std::shared_ptr<String> Object::as_String () {
  throw InterpretationException("Can not cast " + get_type() + " to String");
}

std::shared_ptr<Usize> Object::as_usize () {
  throw InterpretationException("Can not cast " + get_type() + " to usize");
}

std::shared_ptr<Char> Object::as_char () {
  throw InterpretationException("Can not cast " + get_type() + " to char");
}

const std::vector<std::shared_ptr<Object>>& Object::iter () {
  throw InterpretationException("Can not iterate through type " + get_type());
}

bool Object::as_predicate () {
  throw InterpretationException("Invalid usage of type " + get_type() + " in condition");
}

Object& Object::operator++ () {
  throw InterpretationException("INTERNAL ERROR: FOR-LOOP PREFIX INCREMENT WAS CALLED ON TYPE " + get_type());
}

void Object::subscript_assign (const Object& pos, std::shared_ptr<Object> rhs) {
  throw InterpretationException("Invalid operand type for operator[]: " + get_type());
}

std::shared_ptr<Usize> Object::len () const {
  throw InterpretationException("Calling size method allowed only with vec and String");
}

void Object::check_type (const std::string& operator_symbol, const Object* expected, const Object& got) {
  std::string given_type = got.get_type();
  std::string expected_type = expected->get_type();
  if (given_type != expected_type) {
    throw InterpretationException(
        "Invalid operands for operator" + operator_symbol + ": \"" + expected_type + "\" and \"" + given_type + "\"");
  }
}

Object::~Object () = default;
