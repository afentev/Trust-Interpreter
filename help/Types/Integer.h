#ifndef PARSEREXAMPLE_INTEGER_H
#define PARSEREXAMPLE_INTEGER_H

#include "help/Types/Object.h"

class Integer: public Object {
public:
    explicit Integer(int32_t);
    Types get_type() override;
    Integer* operator+ (const Object& other) override;
    Integer* operator- (const Object& other) override;
    Integer* operator* (const Object& other) override;
    Integer* operator/ (const Object& other) override;
    Integer* operator% (const Object& other) override;
    bool operator< (const Object& other) override;
    bool operator<= (const Object& other) override;
    bool operator== (const Object& other) override;
    bool operator!= (const Object& other) override;
    bool operator>= (const Object& other) override;
    bool operator> (const Object& other) override;
    bool operator&& (const Object& other) override;
    bool operator|| (const Object& other) override;
    bool operator! () override;
    Integer* operator- () override;
    void accept(Visitor& visitor) override;
    ~Integer() override;

private:
    int32_t number;
};


#endif //PARSEREXAMPLE_INTEGER_H
