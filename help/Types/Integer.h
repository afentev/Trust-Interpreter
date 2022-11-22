#ifndef PARSEREXAMPLE_INTEGER_H
#define PARSEREXAMPLE_INTEGER_H

#include "help/Types/Object.h"

class Integer : public Object, public std::enable_shared_from_this<Integer> {
 public:
  explicit Integer (int32_t value);

  Integer& operator= (const Boolean& other) override;
  Integer& operator= (const Integer& other) override;
  Integer& operator= (const Float& other) override;
  Integer& operator= (const String& other) override;
  Integer& operator= (const Usize& other) override;

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
  int32_t to_int ();

  std::string get_type () const override;
  void assign_into (std::shared_ptr<Object> lhs) override;

  void accept (Visitor* visitor) override;
  ~Integer () override;

 private:
  int32_t number;
};


#endif //PARSEREXAMPLE_INTEGER_H
