#ifndef PARSEREXAMPLE_STRING_H
#define PARSEREXAMPLE_STRING_H

#include <string>
#include "help/Types/Boolean.h"
#include "help/Types/Object.h"

class String: public Object, public std::enable_shared_from_this<String> {
public:
    explicit String(const std::string&, bool strip = true);
    String& operator=(const Boolean&) override;
    String& operator=(const Integer&) override;
    String& operator=(const String&) override;
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
    std::shared_ptr<String> operator[] (int32_t pos) override;
    bool as_predicate() override;
    std::string as_string() override;
    std::string get_type() override;

    static std::string remove_escape_chars(const std::string& string);

    void accept(Visitor* visitor) override;
    ~String() override;

private:
    std::string string;
};


#endif //PARSEREXAMPLE_STRING_H
