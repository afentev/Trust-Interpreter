#ifndef PARSEREXAMPLE_CHAR_H
#define PARSEREXAMPLE_CHAR_H

#include "help/Types/Object.h"

class Char : public Object, public std::enable_shared_from_this<Char> {
 public:
  explicit Char (unsigned char symbol);

  Char& operator= (const Char& other) override;

  std::shared_ptr<Boolean> operator< (const Object& other) const override;
  std::shared_ptr<Boolean> operator<= (const Object& other) const override;
  std::shared_ptr<Boolean> operator== (const Object& other) const override;
  std::shared_ptr<Boolean> operator!= (const Object& other) const override;
  std::shared_ptr<Boolean> operator>= (const Object& other) const override;
  std::shared_ptr<Boolean> operator> (const Object& other) const override;

  std::shared_ptr<Integer> as_i32 () override;
  std::shared_ptr<Usize> as_usize () override;
  std::shared_ptr<Char> as_char () override;

  std::string as_string () override;

  char get_char() const;

  std::string get_type () const override;
  void assign_into (std::shared_ptr<Object> lhs) override;

  void accept (Visitor* visitor) override;
  ~Char () override;

 private:
  unsigned char symbol;
};


#endif //PARSEREXAMPLE_CHAR_H
