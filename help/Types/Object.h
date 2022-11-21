#ifndef PARSEREXAMPLE_OBJECT_H
#define PARSEREXAMPLE_OBJECT_H

#include "help/Expressions/Expression.h"
#include "help/InterpretationExceptions/InterpretationExceptions.h"

class Boolean;

class Integer;

class String;

class Float;

class Object : public Expression {
 public:
  virtual Object& operator= (const Boolean&) = 0;

  virtual Object& operator= (const Integer&) = 0;

  virtual Object& operator= (const Float&) = 0;

  virtual Object& operator= (const String&) = 0;

  virtual void assign_into (std::shared_ptr<Object>) = 0;

  /* this is needed for dynamic function dispatch. For example:
   * std::shared_ptr<Object> a;  // Integer
   * std::shared_ptr<Object> b;  // Integer
   * *a = *b;  // incorrect!
   * b->assign_into(a);  // correct!
   */

  virtual std::shared_ptr<Object> operator- () = 0;

  virtual std::shared_ptr<Object> operator+ (const Object& other) = 0;

  virtual std::shared_ptr<Object> operator- (const Object& other) = 0;

  virtual std::shared_ptr<Object> operator* (const Object& other) = 0;

  virtual std::shared_ptr<Object> operator/ (const Object& other) = 0;

  virtual std::shared_ptr<Object> operator% (const Object& other) = 0;

  virtual std::shared_ptr<Boolean> operator< (const Object& other) = 0;

  virtual std::shared_ptr<Boolean> operator<= (const Object& other) = 0;

  virtual std::shared_ptr<Boolean> operator== (const Object& other) = 0;

  virtual std::shared_ptr<Boolean> operator!= (const Object& other) = 0;

  virtual std::shared_ptr<Boolean> operator>= (const Object& other) = 0;

  virtual std::shared_ptr<Boolean> operator> (const Object& other) = 0;

  virtual std::shared_ptr<Boolean> operator&& (const Object& other) = 0;

  virtual std::shared_ptr<Boolean> operator|| (const Object& other) = 0;

  virtual std::shared_ptr<Boolean> operator! () = 0;

  virtual std::shared_ptr<String> operator[] (int32_t pos) = 0;

  virtual std::shared_ptr<Boolean> as_bool () = 0;

  virtual std::shared_ptr<Integer> as_i32 () = 0;

  virtual std::shared_ptr<Float> as_f64 () = 0;

  virtual std::shared_ptr<String> as_String () = 0;

  virtual bool as_predicate () = 0;

  virtual std::string as_string () = 0;

  virtual std::string get_type () const = 0;

  static void check_type(const std::string& operator_symbol, const Object* expected, const Object& got);

  ~Object () override = default;
};

#endif //PARSEREXAMPLE_OBJECT_H
