#ifndef PARSEREXAMPLE_FLOAT_H
#define PARSEREXAMPLE_FLOAT_H

#include "help/Types/Object.h"

class Float : public Object, public std::enable_shared_from_this<Float> {
 public:
  explicit Float (double);

  Float& operator= (const Float& other) override;

  std::shared_ptr<Object> operator+ (const Object& other) override;
  std::shared_ptr<Object> operator- (const Object& other) override;
  std::shared_ptr<Object> operator* (const Object& other) override;
  std::shared_ptr<Object> operator/ (const Object& other) override;

  std::shared_ptr<Boolean> operator< (const Object& other) const override;
  std::shared_ptr<Boolean> operator<= (const Object& other) const override;
  std::shared_ptr<Boolean> operator== (const Object& other) const override;
  std::shared_ptr<Boolean> operator!= (const Object& other) const override;
  std::shared_ptr<Boolean> operator>= (const Object& other) const override;
  std::shared_ptr<Boolean> operator> (const Object& other) const override;

  std::shared_ptr<Object> operator- () override;

  std::shared_ptr<Integer> as_i32 () override;
  std::shared_ptr<Float> as_f64 () override;
  std::shared_ptr<Usize> as_usize () override;

  std::string as_string () override;

  std::string get_type () const override;
  void assign_into (std::shared_ptr<Object> lhs) override;

  void accept (Visitor* visitor) override;
  ~Float () override;

 private:
  double number;
};


#endif //PARSEREXAMPLE_FLOAT_H
