#include "Integer.h"

Integer::Integer(int32_t value): number(value) {};

Object& Integer::operator=(const Boolean& other) {
    throw "Can not assign bool to i32";
}

Object& Integer::operator=(const Integer& other) {
    number = other.number;
    return *this;
}

Object& Integer::operator=(const String& other) {
    throw "Can not assign String to i32";
}

void Integer::assign_into(std::shared_ptr<Object> lhs) {
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
    throw "Invalid operand type for operator&&. bool expected, but i32 found";
}

std::shared_ptr<Boolean> Integer::operator|| (const Object& other) {
    throw "Invalid operand type for operator||. bool expected, but i32 found";
}

std::shared_ptr<Boolean> Integer::operator! () {
    throw "Invalid operand type for operator!. bool expected, but i32 found";
}

std::shared_ptr<Object> Integer::operator- () {
    return std::make_shared<Integer>(-number);
}

bool Integer::as_predicate() {
    throw "Invalid usage of type integer in condition";
}

void Integer::accept(Visitor* visitor) {
    visitor->visit(shared_from_this());
}

Integer::~Integer() = default;
