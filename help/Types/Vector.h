#ifndef PARSEREXAMPLE_VECTOR_H
#define PARSEREXAMPLE_VECTOR_H

#include <vector>
#include "help/Types/Object.h"

class Vector: public Object, public std::enable_shared_from_this<Vector> {
 public:
  Vector(std::string type, bool is_pure_empty);
  Vector(std::shared_ptr<Object> value, std::shared_ptr<Object> count);

  Vector& operator= (const Vector& other) override;

  std::shared_ptr<Boolean> operator< (const Object& other) override;
  std::shared_ptr<Boolean> operator<= (const Object& other) override;
  std::shared_ptr<Boolean> operator== (const Object& other) const override;
  std::shared_ptr<Boolean> operator!= (const Object& other) override;
  std::shared_ptr<Boolean> operator>= (const Object& other) override;
  std::shared_ptr<Boolean> operator> (const Object& other) override;

  std::shared_ptr<Object> operator[] (const Object& pos) override;

  void push(std::shared_ptr<Object> value);
  void pop();

  std::string as_string () override;

  void subscript_assign (const Object& pos, std::shared_ptr<Object> rhs) override;

  std::shared_ptr<Usize> len () const override;
  std::string get_type () const override;
  void assign_into (std::shared_ptr<Object> lhs) override;

  void accept (Visitor* visitor) override;
  ~Vector() override;

 private:
  std::vector<std::shared_ptr<Object>> array;
  std::string type;
  const bool is_pure_empty;  // whether object was created via empty vec![]
};


#endif //PARSEREXAMPLE_VECTOR_H
