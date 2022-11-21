#include "String.h"


String::String (const std::string& value, bool strip) : string() {
  if (strip) {
    string = remove_escape_chars(value.substr(1, value.size() - 2));
  } else {
    string = value;
  }
};

String& String::operator= (const Boolean& other) {
  throw "Can not assign bool to String";
}

String& String::operator= (const Integer& other) {
  throw "Can not assign i32 to String";
}

String& String::operator= (const String& other) {
  string = other.string;
  return *this;
}

void String::assign_into (std::shared_ptr<Object> lhs) {
  lhs->operator=(*this);
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

std::shared_ptr<String> String::operator[] (int32_t pos) {
  if (pos < 0 || pos >= string.size()) {
    throw "Subscription index is out of bounds";
  }
  return std::make_shared<String>(std::string(1, string[pos]), false);
}

bool String::as_predicate () {
  throw "Invalid usage of type string in condition";
}

std::string String::as_string () {
  return string;
}

std::string String::get_type () {
  return "String";
}

std::string String::remove_escape_chars (const std::string& string) {
//    \'	single quote	byte 0x27 in ASCII encoding
//    \"	double quote	byte 0x22 in ASCII encoding
//    \?	question mark	byte 0x3f in ASCII encoding
//    \\	backslash	byte 0x5c in ASCII encoding
//    \a	audible bell	byte 0x07 in ASCII encoding
//    \b	backspace	byte 0x08 in ASCII encoding
//    \f	form feed - new page	byte 0x0c in ASCII encoding
//    \n	line feed - new line	byte 0x0a in ASCII encoding
//    \r	carriage return	byte 0x0d in ASCII encoding
//    \t	horizontal tab	byte 0x09 in ASCII encoding
//    \v
  std::string result;
  auto it = string.begin();
  while (it != string.end()) {
    char c = *it++;
    if (c == '\\' && it != string.end()) {
      switch (*it++) {
        case '\'':
          c = '\'';
          break;
        case '\"':
          c = '\"';
          break;
        case '\?':
          c = '\?';
          break;
        case '\\':
          c = '\\';
          break;
        case 'a':
          c = '\a';
          break;
        case 'b':
          c = '\b';
          break;
        case 'f':
          c = '\f';
          break;
        case 'n':
          c = '\n';
          break;
        case 'r':
          c = '\r';
          break;
        case 't':
          c = '\t';
          break;
        case 'v':
          c = '\v';
          break;
        default:
          continue;
      }
    }
    result += c;
  }

  return result;
}

void String::accept (Visitor* visitor) {
  visitor->visit(shared_from_this());
}

String::~String () = default;
