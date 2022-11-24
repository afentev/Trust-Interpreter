#include "Boolean.h"
#include "Vector.h"
#include "Usize.h"

Vector::Vector (std::string type, bool is_pure_empty): type(std::move(type)), is_pure_empty(is_pure_empty) {}

Vector::Vector (std::shared_ptr<Object> value, std::shared_ptr<Object> count) : is_pure_empty(false) {
  type = value->get_type();
  std::string count_type = count->get_type();
  if (count_type != "usize") {
    throw InterpretationException("Type " + count_type + " can not be used as size of vec. Use usize instead");
  }
  array.assign(std::dynamic_pointer_cast<Usize>(count)->to_usize(), value);
}

Vector& Vector::operator= (const Vector& other) {
  if (other.is_pure_empty) {
    array.clear();
    return *this;
  }
  if (type != other.type) {
    throw InterpretationException("Can not assign " + other.get_type() + " to " + get_type());
  }
  array = other.array;
  return *this;
}

std::shared_ptr<Boolean> Vector::operator< (const Object& other) {
  throw InterpretationException("Invalid operand type for operator<: " + get_type());
}

std::shared_ptr<Boolean> Vector::operator<= (const Object& other) {
  throw InterpretationException("Invalid operand type for operator<=: " + get_type());
}

std::shared_ptr<Boolean> Vector::operator== (const Object& other) const {
  check_type("==", this, other);
  return std::make_shared<Boolean>(array == dynamic_cast<const Vector&>(other).array);
}

std::shared_ptr<Boolean> Vector::operator!= (const Object& other) {
  check_type("!=", this, other);
  return std::make_shared<Boolean>(array != dynamic_cast<const Vector&>(other).array);
}

std::shared_ptr<Boolean> Vector::operator>= (const Object& other) {
  throw InterpretationException("Invalid operand type for operator>=: " + get_type());
}

std::shared_ptr<Boolean> Vector::operator> (const Object& other) {
  throw InterpretationException("Invalid operand type for operator>: " + get_type());
}

std::shared_ptr<Object> Vector::operator[] (const Object& pos) {
  std::string pos_type = pos.get_type();
  if (pos_type != "usize") {
    throw InterpretationException("Subscription index must be usize type, not " + pos_type);
  }
  size_t index = dynamic_cast<const Usize&>(pos).to_usize();
  if (index >= array.size()) {
    throw InterpretationException("Subscription index is out of bounds");
  }
  return array[index];
}

void Vector::push (std::shared_ptr<Object> value) {
  if (value->get_type() != type) {
    throw InterpretationException("Pushing type " + value->get_type() + " into a Vec<" + type + "> is type mismatch");
  }
  array.push_back(value);
}

void Vector::pop () {
  if (array.empty()) {
    throw InterpretationException("Pop from an empty vec");
  }
  array.pop_back();
}

std::string Vector::as_string () {
  throw InterpretationException(get_type() + " can not be represented as string");
}

void Vector::subscript_assign (const Object& pos, std::shared_ptr<Object> rhs) {
  check_type("[]", operator[](pos).get(), *rhs);
  std::string pos_type = pos.get_type();
  if (pos_type != "usize") {
    throw InterpretationException("Subscription index must be usize type, not " + pos_type);
  }
  size_t index = dynamic_cast<const Usize&>(pos).to_usize();
  if (index >= array.size()) {
    throw InterpretationException("Subscription index is out of bounds");
  }
  array[index] = rhs;
}

std::shared_ptr<Usize> Vector::len () const {
  return std::make_shared<Usize>(array.size());
}

std::string Vector::get_type () const {
  return "Vec<" + type + ">";
}

void Vector::assign_into (std::shared_ptr<Object> lhs) {
  lhs->operator=(*this);
}

void Vector::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

Vector::~Vector() = default;
