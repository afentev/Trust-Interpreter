#include "Integer.h"

Integer::Integer(int32_t value): number(value) {};

Types Integer::get_type() {
    return Types::i32;
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
