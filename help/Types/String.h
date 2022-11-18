#ifndef PARSEREXAMPLE_STRING_H
#define PARSEREXAMPLE_STRING_H

#include <string>
#include "help/Types/Object.h"

class String: public Object {
public:
    explicit String(const std::string&);
    Types get_type() override;
    String* operator+ (const Object& other) override;
    String* operator- (const Object& other) override;
    String* operator* (const Object& other) override;
    String* operator/ (const Object& other) override;
    String* operator% (const Object& other) override;
    bool operator< (const Object& other) override;
    bool operator<= (const Object& other) override;
    bool operator== (const Object& other) override;
    bool operator!= (const Object& other) override;
    bool operator>= (const Object& other) override;
    bool operator> (const Object& other) override;
    bool operator&& (const Object& other) override;
    bool operator|| (const Object& other) override;
    bool operator! () override;
    String* operator- () override;
    void accept(Visitor& visitor) override;
    ~String() override;

private:
    std::string string;
};


#endif //PARSEREXAMPLE_STRING_H
