#include "Boolean.h"
#include "Integer.h"
#include "Char.h"
#include "Usize.h"

Char::Char (unsigned char symbol) : symbol(symbol) {}

Char& Char::operator= (const Char& other) {
  symbol = other.symbol;
  return *this;
}

std::shared_ptr<Boolean> Char::operator< (const Object& other) {
  check_type("<", this, other);
  return std::make_shared<Boolean>(symbol < dynamic_cast<const Char&>(other).symbol);
}

std::shared_ptr<Boolean> Char::operator<= (const Object& other) {
  check_type("<=", this, other);
  return std::make_shared<Boolean>(symbol <= dynamic_cast<const Char&>(other).symbol);
}

std::shared_ptr<Boolean> Char::operator== (const Object& other) const {
  check_type("==", this, other);
  return std::make_shared<Boolean>(symbol == dynamic_cast<const Char&>(other).symbol);
}

std::shared_ptr<Boolean> Char::operator!= (const Object& other) {
  check_type("!=", this, other);
  return std::make_shared<Boolean>(symbol != dynamic_cast<const Char&>(other).symbol);
}

std::shared_ptr<Boolean> Char::operator>= (const Object& other) {
  check_type(">=", this, other);
  return std::make_shared<Boolean>(symbol >= dynamic_cast<const Char&>(other).symbol);
}

std::shared_ptr<Boolean> Char::operator> (const Object& other) {
  check_type(">", this, other);
  return std::make_shared<Boolean>(symbol > dynamic_cast<const Char&>(other).symbol);
}

std::shared_ptr<Integer> Char::as_i32 () {
  return std::make_shared<Integer>(symbol);
}

std::shared_ptr<Usize> Char::as_usize () {
  return std::make_shared<Usize>(symbol);
}

std::shared_ptr<Char> Char::as_char () {
  return std::make_shared<Char>(symbol);
}

std::string Char::as_string () {
  return std::string(1, symbol);
}

char Char::get_char () const {
  return symbol;
}

std::string Char::get_type () const {
  return "char";
}

void Char::assign_into (std::shared_ptr<Object> lhs) {
  lhs->operator=(*this);
}

void Char::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

Char::~Char () = default;
