#ifndef PARSEREXAMPLE_BOOLEAN_H
#define PARSEREXAMPLE_BOOLEAN_H

#include "help/Types/Object.h"

class Boolean : public Object, public std::enable_shared_from_this<Boolean> {
 public:
  explicit Boolean (bool);

  Boolean& operator= (const Boolean&) override;

  Boolean& operator= (const Integer&) override;

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

  bool as_predicate () override;

  std::string as_string () override;

  std::string get_type () override;

  void accept (Visitor* visitor) override;

  ~Boolean () override;

 private:
  bool value;
};


#endif //PARSEREXAMPLE_BOOLEAN_H
