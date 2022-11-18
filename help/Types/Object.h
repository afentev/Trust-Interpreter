#ifndef PARSEREXAMPLE_OBJECT_H
#define PARSEREXAMPLE_OBJECT_H

#include "help/Expression.h"

enum Types {
    Str,
    i32,
    real,
    boolean
};

class Boolean;

class Object: public Expression {
public:
    virtual Types get_type() = 0;

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

    ~Object() override = default;
};

#endif //PARSEREXAMPLE_OBJECT_H
