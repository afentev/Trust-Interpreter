#ifndef PARSEREXAMPLE_OBJECT_H
#define PARSEREXAMPLE_OBJECT_H

#include <vector>
#include "help/Expressions/Expression.h"

class Boolean;
class Integer;
class String;
class Float;
class Usize;
class Char;
class Vector;

class Object : public Expression {
 public:
  Object& operator= (const Object& other) = delete;
  virtual Object& operator= (const Boolean& other);
  virtual Object& operator= (const Integer& other);
  virtual Object& operator= (const Float& other);
  virtual Object& operator= (const String& other);
  virtual Object& operator= (const Usize& other);
  virtual Object& operator= (const Char& other);
  virtual Object& operator= (const Vector& other);

  virtual std::shared_ptr<Object> operator+ (const Object& other);
  virtual std::shared_ptr<Object> operator- (const Object& other);
  virtual std::shared_ptr<Object> operator* (const Object& other);
  virtual std::shared_ptr<Object> operator/ (const Object& other);
  virtual std::shared_ptr<Object> operator% (const Object& other);

  virtual std::shared_ptr<Boolean> operator< (const Object& other) const = 0;
  virtual std::shared_ptr<Boolean> operator<= (const Object& other) const = 0;
  virtual std::shared_ptr<Boolean> operator== (const Object& other) const = 0;
  virtual std::shared_ptr<Boolean> operator!= (const Object& other) const = 0;
  virtual std::shared_ptr<Boolean> operator>= (const Object& other) const = 0;
  virtual std::shared_ptr<Boolean> operator> (const Object& other) const = 0;

  virtual std::shared_ptr<Boolean> operator&& (const Object& other);
  virtual std::shared_ptr<Boolean> operator|| (const Object& other);
  virtual std::shared_ptr<Boolean> operator! ();

  virtual std::shared_ptr<Object> operator- ();
  virtual std::shared_ptr<Object> operator[] (const Object& pos);

  virtual std::shared_ptr<Boolean> as_bool ();
  virtual std::shared_ptr<Integer> as_i32 ();
  virtual std::shared_ptr<Float> as_f64 ();
  virtual std::shared_ptr<String> as_String ();
  virtual std::shared_ptr<Usize> as_usize ();
  virtual std::shared_ptr<Char> as_char ();

  virtual const std::vector<std::shared_ptr<Object>>& iter ();
  virtual bool as_predicate ();
  virtual std::string as_string () = 0;

  virtual Object& operator++ ();
  virtual void subscript_assign (const Object& pos, std::shared_ptr<Object> rhs);

  virtual std::shared_ptr<Usize> len () const;
  virtual std::string get_type () const = 0;
  virtual void assign_into (std::shared_ptr<Object> lhs) = 0;
  /* this is needed for dynamic function dispatch. For example:
   * std::shared_ptr<Object> a;  // Integer
   * std::shared_ptr<Object> b;  // Integer
   * *a = *b;  // incorrect!
   * b->assign_into(a);  // correct!
   */

  static void check_type (const std::string& operator_symbol, const Object* expected, const Object& got);

  ~Object () override;
};

#endif //PARSEREXAMPLE_OBJECT_H
