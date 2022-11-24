#ifndef PARSEREXAMPLE_STRING_H
#define PARSEREXAMPLE_STRING_H

#include "help/Types/Object.h"

class String : public Object, public std::enable_shared_from_this<String> {
 public:
  explicit String (const std::string& value, bool strip = true);

  String& operator= (const String& other) override;

  std::shared_ptr<Object> operator+ (const Object& other) override;

  std::shared_ptr<Boolean> operator< (const Object& other) const override;
  std::shared_ptr<Boolean> operator<= (const Object& other) const override;
  std::shared_ptr<Boolean> operator== (const Object& other) const override;
  std::shared_ptr<Boolean> operator!= (const Object& other) const override;
  std::shared_ptr<Boolean> operator>= (const Object& other) const override;
  std::shared_ptr<Boolean> operator> (const Object& other) const override;

  std::shared_ptr<Object> operator[] (const Object& pos) override;

  std::shared_ptr<String> as_String () override;

  const std::vector<std::shared_ptr<Object>>& iter () override;
  std::string as_string () override;

  void subscript_assign (const Object& pos, std::shared_ptr<Object> rhs) override;

  std::shared_ptr<Usize> len () const override;
  std::string get_type () const override;
  void assign_into (std::shared_ptr<Object> lhs) override;

  static std::string remove_escape_chars (const std::string& string);

  void accept (Visitor* visitor) override;
  ~String () override;

 private:
  std::vector<std::shared_ptr<Object>> string;
};


#endif //PARSEREXAMPLE_STRING_H
