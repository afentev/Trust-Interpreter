#include "Boolean.h"

Boolean::Boolean(bool value): value(value) {
    ;
}

Types Boolean::get_type() {
    return Types::i32;
}

Boolean* Boolean::operator+ (const Object& other) {
    throw "Invalid operand type for operator&&. String or i32 expected, but bool found";
}

Boolean* Boolean::operator- (const Object& other) {
    throw "Invalid operand type for operator&&. i32 expected, but bool found";
}

Boolean* Boolean::operator* (const Object& other) {
    throw "Invalid operand type for operator&&. i32 expected, but bool found";
}

Boolean* Boolean::operator/ (const Object& other) {
    throw "Invalid operand type for operator&&. i32 expected, but bool found";
}

Boolean* Boolean::operator% (const Object& other) {
    throw "Invalid operand type for operator&&. i32 expected, but bool found";
}

bool Boolean::operator< (const Object& other) {
    return value < static_cast<const Boolean&>(other).value;
}

bool Boolean::operator<= (const Object& other) {
    return value <= static_cast<const Boolean&>(other).value;
}

bool Boolean::operator== (const Object& other) {
    return value == static_cast<const Boolean&>(other).value;
}

bool Boolean::operator!= (const Object& other) {
    return value != static_cast<const Boolean&>(other).value;
}

bool Boolean::operator>= (const Object& other) {
    return value >= static_cast<const Boolean&>(other).value;
}

bool Boolean::operator> (const Object& other) {
    return value > static_cast<const Boolean&>(other).value;
}

bool Boolean::operator&& (const Object& other) {
    return value && static_cast<const Boolean&>(other).value;
}

bool Boolean::operator|| (const Object& other) {
    return value || static_cast<const Boolean&>(other).value;
}

bool Boolean::operator! () {
    return !value;
}

Boolean* Boolean::operator- () {
    throw "Invalid operand type for operator&&. i32 expected, but bool found";
}

void Boolean::accept(Visitor* visitor) {
    ;
}

Boolean::~Boolean() = default;
