#ifndef PARSEREXAMPLE_OBJECT_H
#define PARSEREXAMPLE_OBJECT_H

#include "help/Expressions/Expression.h"

class Boolean;
class Integer;
class String;

class Object: public Expression {
public:
    virtual Object& operator=(const Boolean&) = 0;
    virtual Object& operator=(const Integer&) = 0;
    virtual Object& operator=(const String&) = 0;
    virtual void assign_into(std::shared_ptr<Object>) = 0;
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

    virtual bool as_predicate() = 0;
    virtual std::string as_string() = 0;

    ~Object() override = default;
};

#endif //PARSEREXAMPLE_OBJECT_H
