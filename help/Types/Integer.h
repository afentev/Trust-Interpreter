#ifndef PARSEREXAMPLE_INTEGER_H
#define PARSEREXAMPLE_INTEGER_H

#include "help/Types/Boolean.h"
#include "help/Types/Object.h"

class Integer: public Object, public std::enable_shared_from_this<Integer> {
public:
    explicit Integer(int32_t);
    Object& operator=(const Boolean&) override;
    Object& operator=(const Integer&) override;
    Object& operator=(const String&) override;
    void assign_into(std::shared_ptr<Object>) override;

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
    std::string as_string() override;
    std::string get_type() override;
    void accept(Visitor* visitor) override;
    ~Integer() override;

private:
    int32_t number;
};


#endif //PARSEREXAMPLE_INTEGER_H
