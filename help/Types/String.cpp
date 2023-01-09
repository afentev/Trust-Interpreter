#include "Boolean.h"
#include "String.h"
#include "Char.h"
#include "Usize.h"

String::String (const std::string& value, bool strip) : string() {
  if (strip) {
    std::string stripped = remove_escape_chars(value.substr(1, value.size() - 2));
    for (char chr: stripped) {
      string.push_back(std::make_shared<Char>(chr));
    }
  } else {
    for (char chr: value) {
      string.push_back(std::make_shared<Char>(chr));
    }
  }
}

String& String::operator= (const String& other) {
  string = other.string;
  return *this;
}

std::shared_ptr<Object> String::operator+ (const Object& other) {
  check_type("+", this, other);
  String copy = *this;
  for (std::shared_ptr<Object> chr: dynamic_cast<const String&>(other).string) {
    copy.string.push_back(chr);
  }
  return std::make_shared<String>(copy);
}

std::shared_ptr<Boolean> String::operator< (const Object& other) const {
  check_type("<", this, other);
  auto other_cast = dynamic_cast<const String&>(other);
  size_t minima = std::min(string.size(), other_cast.string.size());
  for (size_t index = 0; index < minima; ++index) {
    if (string[index] < other_cast.string[index]) {
      return std::make_shared<Boolean>(true);
    } else if (string[index] > other_cast.string[index]) {
      return std::make_shared<Boolean>(false);
    }
  }
  if (string.size() < other_cast.string.size()) {
    return std::make_shared<Boolean>(true);
  }
  return std::make_shared<Boolean>(false);
}

std::shared_ptr<Boolean> String::operator<= (const Object& other) const {
  check_type("<=", this, other);
  return !*(other > *this)->as_bool();
}

std::shared_ptr<Boolean> String::operator== (const Object& other) const {
  check_type("==", this, other);
  auto other_cast = dynamic_cast<const String&>(other);
  if (string.size() != other_cast.string.size()) {
    return std::make_shared<Boolean>(false);
  }
  for (int index = 0; index < string.size(); ++index) {
    if (string[index] != other_cast.string[index]) {
      return std::make_shared<Boolean>(false);
    }
  }
  return std::make_shared<Boolean>(true);
}

std::shared_ptr<Boolean> String::operator!= (const Object& other) const {
  check_type("!=", this, other);
  return !*(*this == other)->as_bool();
}

std::shared_ptr<Boolean> String::operator>= (const Object& other) const {
  check_type(">=", this, other);
  return !*(*this < other)->as_bool();
}

std::shared_ptr<Boolean> String::operator> (const Object& other) const {
  check_type(">", this, other);
  return dynamic_cast<const String&>(other) < *this;
}

std::shared_ptr<Object> String::operator[] (const Object& pos) {
  std::string pos_type = pos.get_type();
  if (pos_type != "usize") {
    throw InterpretationException("Subscription index must be usize type, not " + pos_type);
  }
  size_t index = dynamic_cast<const Usize&>(pos).to_usize();
  if (index >= string.size()) {
    throw InterpretationException("Subscription index is out of bounds");
  }
  return string[index];
}

std::shared_ptr<String> String::as_String () {
  std::string result;
  for (std::shared_ptr<Object> chr: string) {
    result.push_back(std::dynamic_pointer_cast<Char>(chr)->get_char());
  }
  return std::make_shared<String>(result);
}

const std::vector<std::shared_ptr<Object>>& String::iter () {
  return string;
}

std::string String::as_string () {
  std::string result;
  for (std::shared_ptr<Object> chr: string) {
    result.push_back(std::dynamic_pointer_cast<Char>(chr)->get_char());
  }
  return result;
}

void String::subscript_assign (const Object& pos, std::shared_ptr<Object> rhs) {
  check_type("[]", operator[](pos).get(), *rhs);
  std::string pos_type = pos.get_type();
  if (pos_type != "usize") {
    throw InterpretationException("Subscription index must be usize type, not " + pos_type);
  }
  size_t index = dynamic_cast<const Usize&>(pos).to_usize();
  if (index >= string.size()) {
    throw InterpretationException("Subscription index is out of bounds");
  }
  string[index] = std::dynamic_pointer_cast<Char>(rhs);
}

std::shared_ptr<Usize> String::len () const {
  return std::make_shared<Usize>(string.size());
}

std::string String::get_type () const {
  return "String";
}

void String::assign_into (std::shared_ptr<Object> lhs) {
  lhs->operator=(*this);
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
