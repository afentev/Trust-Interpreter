#ifndef PARSEREXAMPLE_STRING_H
#define PARSEREXAMPLE_STRING_H

#include <string>
#include "help/Types/Boolean.h"
#include "help/Types/Object.h"

class String: public Object, public std::enable_shared_from_this<String> {
public:
    explicit String(const std::string&);
    Types get_type() override;
    std::shared_ptr<Object> operator+ (const Object& other) override;
    std::shared_ptr<Object> operator- (const Object& other) override;
    std::shared_ptr<Object> operator* (const Object& other) override;
    std::shared_ptr<Object> operator/ (const Object& other) override;
    std::shared_ptr<Object> operator% (const Object& other) override;
    std::shared_ptr<Boolean> operator< (const Object& other) override;
    std::shared_ptr<Boolean> operator<= (const Object& other) override;
    std::shared_ptr<Boolean> operator== (const Object& other) override;
    std::shared_ptr<Boolean> operator!= (const Object& other) override;
    std::shared_ptr<Boolean> operator>= (const Object& other) override;
    std::shared_ptr<Boolean> operator> (const Object& other) override;
    std::shared_ptr<Boolean> operator&& (const Object& other) override;
    std::shared_ptr<Boolean> operator|| (const Object& other) override;
    std::shared_ptr<Boolean> operator! () override;
    std::shared_ptr<Object> operator- () override;
    bool as_predicate() override;
    void accept(Visitor* visitor) override;
    ~String() override;

private:
    std::string string;
};


#endif //PARSEREXAMPLE_STRING_H
