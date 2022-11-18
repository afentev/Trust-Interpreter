#include "String.h"


String::String(const std::string& value): string(value) {};

Types String::get_type() {
    return Types::Str;
}

String* String::operator+ (const Object& other) {
    return new String(string + static_cast<const String&>(other).string);
}

String* String::operator- (const Object& other) {
    throw "Invalid operand type for operator&&. i32 expected, but String found";
}

String* String::operator* (const Object& other) {
    throw "Invalid operand type for operator&&. i32 expected, but String found";
}

String* String::operator/ (const Object& other) {
    throw "Invalid operand type for operator&&. i32 expected, but String found";
}

String* String::operator% (const Object& other) {
    throw "Invalid operand type for operator&&. i32 expected, but String found";
}

bool String::operator< (const Object& other) {
    return string < static_cast<const String&>(other).string;
}

bool String::operator<= (const Object& other) {
    return string <= static_cast<const String&>(other).string;
}

bool String::operator== (const Object& other) {
    return string == static_cast<const String&>(other).string;
}

bool String::operator!= (const Object& other) {
    return string != static_cast<const String&>(other).string;
}

bool String::operator>= (const Object& other) {
    return string >= static_cast<const String&>(other).string;
}

bool String::operator> (const Object& other) {
    return string > static_cast<const String&>(other).string;
}

bool String::operator&& (const Object& other) {
    throw "Invalid operand type for operator&&. bool expected, but String found";
}

bool String::operator|| (const Object& other) {
    throw "Invalid operand type for operator||. bool expected, but String found";
}

bool String::operator! () {
    throw "Invalid operand type for operator!. bool expected, but i32 found";
}

String* String::operator- () {
    throw "Invalid operand type for operator!. i32 expected, but i32 found";
}

void String::accept(Visitor* visitor) {
    ;
}

String::~String() = default;
