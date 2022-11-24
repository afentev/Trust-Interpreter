#ifndef PARSEREXAMPLE_USIZE_H
#define PARSEREXAMPLE_USIZE_H

#include "help/Types/Object.h"

class Usize : public Object, public std::enable_shared_from_this<Usize> {
 public:
  explicit Usize (size_t value);

  Usize& operator= (const Usize& other) override;

  std::shared_ptr<Object> operator+ (const Object& other) override;
  std::shared_ptr<Object> operator- (const Object& other) override;
  std::shared_ptr<Object> operator* (const Object& other) override;
  std::shared_ptr<Object> operator/ (const Object& other) override;
  std::shared_ptr<Object> operator% (const Object& other) override;

  std::shared_ptr<Boolean> operator< (const Object& other) const override;
  std::shared_ptr<Boolean> operator<= (const Object& other) const override;
  std::shared_ptr<Boolean> operator== (const Object& other) const override;
  std::shared_ptr<Boolean> operator!= (const Object& other) const override;
  std::shared_ptr<Boolean> operator>= (const Object& other) const override;
  std::shared_ptr<Boolean> operator> (const Object& other) const override;

  std::shared_ptr<Boolean> as_bool () override;
  std::shared_ptr<Integer> as_i32 () override;
  std::shared_ptr<Float> as_f64 () override;
  std::shared_ptr<Usize> as_usize () override;

  std::string as_string () override;
  size_t to_usize () const;

  std::string get_type () const override;
  Object& operator++ () override;
  void assign_into (std::shared_ptr<Object> lhs) override;

  void accept (Visitor* visitor) override;
  ~Usize () override;

 private:
  size_t number;
};


#endif //PARSEREXAMPLE_USIZE_H
