#ifndef PARSEREXAMPLE_OBJECT_H
#define PARSEREXAMPLE_OBJECT_H

#include "help/Expression.h"

enum Types {
    Str,
    i32,
    real,
    boolean
};

class Object: public Expression {
public:
    virtual Types get_type() = 0;

    virtual Object* operator- () = 0;
    virtual Object* operator+ (const Object& other) = 0;
    virtual Object* operator- (const Object& other) = 0;
    virtual Object* operator* (const Object& other) = 0;
    virtual Object* operator/ (const Object& other) = 0;
    virtual Object* operator% (const Object& other) = 0;

    virtual bool operator< (const Object& other) = 0;
    virtual bool operator<= (const Object& other) = 0;
    virtual bool operator== (const Object& other) = 0;
    virtual bool operator!= (const Object& other) = 0;
    virtual bool operator>= (const Object& other) = 0;
    virtual bool operator> (const Object& other) = 0;

    virtual bool operator&& (const Object& other) = 0;
    virtual bool operator|| (const Object& other) = 0;
    virtual bool operator! () = 0;

    ~Object() override = default;
};

#endif //PARSEREXAMPLE_OBJECT_H
