#ifndef PARSEREXAMPLE_BOOLEAN_H
#define PARSEREXAMPLE_BOOLEAN_H

#include "help/Types/Object.h"

class Boolean: public Object {
public:
    explicit Boolean(bool);
    Types get_type() override;
    Boolean* operator+ (const Object& other) override;
    Boolean* operator- (const Object& other) override;
    Boolean* operator* (const Object& other) override;
    Boolean* operator/ (const Object& other) override;
    Boolean* operator% (const Object& other) override;
    bool operator< (const Object& other) override;
    bool operator<= (const Object& other) override;
    bool operator== (const Object& other) override;
    bool operator!= (const Object& other) override;
    bool operator>= (const Object& other) override;
    bool operator> (const Object& other) override;
    bool operator&& (const Object& other) override;
    bool operator|| (const Object& other) override;
    bool operator! () override;
    Boolean* operator- () override;
    void accept(Visitor* visitor) override;
    ~Boolean() override;

private:
    bool value;
};


#endif //PARSEREXAMPLE_BOOLEAN_H
