#ifndef PARSEREXAMPLE_STRING_H
#define PARSEREXAMPLE_STRING_H

#include "help/Types/Object.h"

class String : public Object, public std::enable_shared_from_this<String> {
 public:
  explicit String (const std::string&, bool strip = true);

  String& operator= (const Boolean& other) override;
  String& operator= (const Integer& other) override;
  String& operator= (const Float& other) override;
  String& operator= (const String& other) override;
  String& operator= (const Usize& other) override;

  std::shared_ptr<Object> operator+ (const Object& other) override;
  std::shared_ptr<Object> operator- (const Object& other) override;
  std::shared_ptr<Object> operator* (const Object& other) override;
  std::shared_ptr<Object> operator/ (const Object& other) override;
  std::shared_ptr<Object> operator% (const Object& other) override;

  std::shared_ptr<Boolean> operator< (const Object& other) override;
  std::shared_ptr<Boolean> operator<= (const Object& other) override;
  std::shared_ptr<Boolean> operator== (const Object& other) const override;
  std::shared_ptr<Boolean> operator!= (const Object& other) override;
  std::shared_ptr<Boolean> operator>= (const Object& other) override;
  std::shared_ptr<Boolean> operator> (const Object& other) override;

  std::shared_ptr<Boolean> operator&& (const Object& other) override;
  std::shared_ptr<Boolean> operator|| (const Object& other) override;
  std::shared_ptr<Boolean> operator! () override;

  std::shared_ptr<Object> operator- () override;
  std::shared_ptr<String> operator[] (int32_t pos) override;

  std::shared_ptr<Boolean> as_bool () override;
  std::shared_ptr<Integer> as_i32 () override;
  std::shared_ptr<Float> as_f64 () override;
  std::shared_ptr<String> as_String () override;
  std::shared_ptr<Usize> as_usize () override;

  bool as_predicate () override;
  std::string as_string () override;

  std::string get_type () const override;
  void assign_into (std::shared_ptr<Object> lhs) override;

  static std::string remove_escape_chars (const std::string& string);

  void accept (Visitor* visitor) override;
  ~String () override;

 private:
  std::string string;
};


#endif //PARSEREXAMPLE_STRING_H
