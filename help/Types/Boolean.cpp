#include "Boolean.h"

Boolean::Boolean(bool value): value(value) {
    ;
}

Types Boolean::get_type() {
    return Types::i32;
}

std::shared_ptr<Object> Boolean::operator+ (const Object& other) {
    throw "Invalid operand type for operator&&. String or i32 expected, but bool found";
}

std::shared_ptr<Object> Boolean::operator- (const Object& other) {
    throw "Invalid operand type for operator&&. i32 expected, but bool found";
}

std::shared_ptr<Object> Boolean::operator* (const Object& other) {
    throw "Invalid operand type for operator&&. i32 expected, but bool found";
}

std::shared_ptr<Object> Boolean::operator/ (const Object& other) {
    throw "Invalid operand type for operator&&. i32 expected, but bool found";
}

std::shared_ptr<Object> Boolean::operator% (const Object& other) {
    throw "Invalid operand type for operator&&. i32 expected, but bool found";
}

std::shared_ptr<Boolean> Boolean::operator< (const Object& other) {
    return std::make_shared<Boolean>(value < dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator<= (const Object& other) {
    return std::make_shared<Boolean>(value <= dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator== (const Object& other) {
    return std::make_shared<Boolean>(value == dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator!= (const Object& other) {
    return std::make_shared<Boolean>(value != dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator>= (const Object& other) {
    return std::make_shared<Boolean>(value >= dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator> (const Object& other) {
    return std::make_shared<Boolean>(value > dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator&& (const Object& other) {
    return std::make_shared<Boolean>(value && dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator|| (const Object& other) {
    return std::make_shared<Boolean>(value || dynamic_cast<const Boolean&>(other).value);
}

std::shared_ptr<Boolean> Boolean::operator! () {
    return std::make_shared<Boolean>(!value);
}

std::shared_ptr<Object> Boolean::operator- () {
    throw "Invalid operand type for operator&&. i32 expected, but bool found";
}

bool Boolean::as_predicate() {
    return value;
}

void Boolean::accept(Visitor* visitor) {
    visitor->visit(shared_from_this());
}

Boolean::~Boolean() = default;
