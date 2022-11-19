#ifndef PARSEREXAMPLE_BOOLEAN_H
#define PARSEREXAMPLE_BOOLEAN_H

#include "help/Types/Object.h"

class Boolean: public Object, public std::enable_shared_from_this<Boolean> {
public:
    explicit Boolean(bool);
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
    void accept(Visitor* visitor) override;
    ~Boolean() override;

private:
    bool value;
};


#endif //PARSEREXAMPLE_BOOLEAN_H
