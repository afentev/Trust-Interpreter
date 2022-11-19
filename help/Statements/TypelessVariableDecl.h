#ifndef PARSEREXAMPLE_TYPELESSVARIABLEDECL_H
#define PARSEREXAMPLE_TYPELESSVARIABLEDECL_H

#include <string>
#include <utility>
#include "Statement.h"

class TypelessVariableDecl: public Statement, public std::enable_shared_from_this<TypelessVariableDecl> {
public:
    explicit TypelessVariableDecl(std::string, bool, std::shared_ptr<Expression>);
    void accept(Visitor* visitor) override;
    std::string get_name();
    bool is_const();
    std::shared_ptr<Expression> get_value();
    ~TypelessVariableDecl() override;

private:
    const std::string variable_name;
    std::shared_ptr<Expression> value;
    bool is_constant;
};

#endif //PARSEREXAMPLE_TYPELESSVARIABLEDECL_H
