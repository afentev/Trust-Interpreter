#ifndef PARSEREXAMPLE_VARIABLEDECLINIT_H
#define PARSEREXAMPLE_VARIABLEDECLINIT_H

#include <string>
#include <utility>
#include "Statement.h"

class VariableDeclInit: public Statement, public std::enable_shared_from_this<VariableDeclInit> {
public:
    explicit VariableDeclInit(std::string, std::string, bool, std::shared_ptr<Expression>);
    void accept(Visitor* visitor) override;
    std::string get_name();
    std::string get_type();
    bool is_const();
    std::shared_ptr<Expression> get_value();
    ~VariableDeclInit() override;

private:
    const std::string variable_name;
    const std::string variable_type;
    std::shared_ptr<Expression> value;
    bool is_constant;
};


#endif //PARSEREXAMPLE_VARIABLEDECLINIT_H
