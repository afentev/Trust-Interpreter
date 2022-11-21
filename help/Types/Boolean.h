#ifndef PARSEREXAMPLE_BOOLEAN_H
#define PARSEREXAMPLE_BOOLEAN_H

#include "help/Types/Object.h"

class Boolean : public Object, public std::enable_shared_from_this<Boolean> {
 public:
  explicit Boolean (bool);

  Boolean& operator= (const Boolean&) override;

  Boolean& operator= (const Integer&) override;

  Boolean& operator= (const Float&) override;

  Boolean& operator= (const String&) override;

  void assign_into (std::shared_ptr<Object>) override;

  std::shared_ptr<Object> operator+ (const Object& other) override;

  std::shared_ptr<Object> operator- (const Object& other) override;

  std::shared_ptr<Object> operator* (const Object& other) override;

  std::shared_ptr<Object> operator/ (const Object& other) override;

  std::shared_ptr<Object> operator% (const Object& other) override;

  std::shared_ptr<Boolean> operator< (const Object& other) override;

  std::shared_ptr<Boolean> operator<= (const Object& other) override;

  std::shared_ptr<Boolean> operator== (const Object& other) override;

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

  bool as_predicate () override;

  std::string as_string () override;

  std::string get_type () const override;

  void accept (Visitor* visitor) override;

  ~Boolean () override;

 private:
  bool value;
};


#endif //PARSEREXAMPLE_BOOLEAN_H
