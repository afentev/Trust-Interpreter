#include "Integer.h"

Integer::Integer(int32_t value): number(value) {};

Types Integer::get_type() {
    return Types::i32;
}

Integer* Integer::operator+ (const Object& other) {
    return new Integer(number + static_cast<const Integer&>(other).number);
}

Integer* Integer::operator- (const Object& other) {
    return new Integer(number - static_cast<const Integer&>(other).number);
}

Integer* Integer::operator* (const Object& other) {
    return new Integer(number * static_cast<const Integer&>(other).number);
}

Integer* Integer::operator/ (const Object& other) {
    return new Integer(number / static_cast<const Integer&>(other).number);
}

Integer* Integer::operator% (const Object& other) {
    return new Integer(number % static_cast<const Integer&>(other).number);
}

bool Integer::operator< (const Object& other) {
    return number < static_cast<const Integer&>(other).number;
}

bool Integer::operator<= (const Object& other) {
    return number <= static_cast<const Integer&>(other).number;
}

bool Integer::operator== (const Object& other) {
    return number == static_cast<const Integer&>(other).number;
}

bool Integer::operator!= (const Object& other) {
    return number != static_cast<const Integer&>(other).number;
}

bool Integer::operator>= (const Object& other) {
    return number >= static_cast<const Integer&>(other).number;
}

bool Integer::operator> (const Object& other) {
    return number > static_cast<const Integer&>(other).number;
}

bool Integer::operator&& (const Object& other) {
    throw "Invalid operand type for operator&&. bool expected, but i32 found";
}

bool Integer::operator|| (const Object& other) {
    throw "Invalid operand type for operator||. bool expected, but i32 found";
}

bool Integer::operator! () {
    throw "Invalid operand type for operator!. bool expected, but i32 found";
}

Integer* Integer::operator- () {
    return new Integer(-number);
}

void Integer::accept(Visitor& visitor) {
    ;
}

Integer::~Integer() = default;
