#ifndef PARSEREXAMPLE_VARIABLEDECLINIT_H
#define PARSEREXAMPLE_VARIABLEDECLINIT_H

#include <string>
#include <utility>
#include "help/Statement.h"

class VariableDeclInit: public Statement, public std::enable_shared_from_this<VariableDeclInit> {
public:
    explicit VariableDeclInit(std::string, std::string, bool, std::shared_ptr<Expression>);
    void accept(Visitor* visitor) override;
    ~VariableDeclInit() override;

private:
    const std::string variable_name;
    const std::string variable_type;
    std::shared_ptr<Expression> value;
    bool is_constant;
};


#endif //PARSEREXAMPLE_VARIABLEDECLINIT_H
