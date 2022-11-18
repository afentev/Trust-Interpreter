#include "String.h"


String::String(const std::string& value): string(value) {};

Types String::get_type() {
    return Types::Str;
}

std::shared_ptr<Object> String::operator+ (const Object& other) {
    return std::make_shared<String>(string + dynamic_cast<const String&>(other).string);
}

std::shared_ptr<Object> String::operator- (const Object& other) {
    throw "Invalid operand type for operator&&. i32 expected, but String found";
}

std::shared_ptr<Object> String::operator* (const Object& other) {
    throw "Invalid operand type for operator&&. i32 expected, but String found";
}

std::shared_ptr<Object> String::operator/ (const Object& other) {
    throw "Invalid operand type for operator&&. i32 expected, but String found";
}

std::shared_ptr<Object> String::operator% (const Object& other) {
    throw "Invalid operand type for operator&&. i32 expected, but String found";
}

std::shared_ptr<Boolean> String::operator< (const Object& other) {
    return std::make_shared<Boolean>(string < dynamic_cast<const String&>(other).string);
}

std::shared_ptr<Boolean> String::operator<= (const Object& other) {
    return std::make_shared<Boolean>(string <= dynamic_cast<const String&>(other).string);
}

std::shared_ptr<Boolean> String::operator== (const Object& other) {
    return std::make_shared<Boolean>(string == dynamic_cast<const String&>(other).string);
}

std::shared_ptr<Boolean> String::operator!= (const Object& other) {
    return std::make_shared<Boolean>(string != dynamic_cast<const String&>(other).string);
}

std::shared_ptr<Boolean> String::operator>= (const Object& other) {
    return std::make_shared<Boolean>(string >= dynamic_cast<const String&>(other).string);
}

std::shared_ptr<Boolean> String::operator> (const Object& other) {
    return std::make_shared<Boolean>(string > dynamic_cast<const String&>(other).string);
}

std::shared_ptr<Boolean> String::operator&& (const Object& other) {
    throw "Invalid operand type for operator&&. bool expected, but String found";
}

std::shared_ptr<Boolean> String::operator|| (const Object& other) {
    throw "Invalid operand type for operator||. bool expected, but String found";
}

std::shared_ptr<Boolean> String::operator! () {
    throw "Invalid operand type for operator!. bool expected, but i32 found";
}

std::shared_ptr<Object> String::operator- () {
    throw "Invalid operand type for operator!. i32 expected, but i32 found";
}

bool String::as_predicate() {
    throw "Invalid usage of type string in condition";
}

void String::accept(Visitor* visitor) {
    visitor->visit(shared_from_this());
}

String::~String() = default;
