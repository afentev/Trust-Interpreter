#ifndef PARSEREXAMPLE_GREATEREQEXPRESSION_H
#define PARSEREXAMPLE_GREATEREQEXPRESSION_H

#include <memory>
#include "help/Expression.h"

class GreaterEqExpression: public Expression, public std::enable_shared_from_this<GreaterEqExpression> {
public:
    GreaterEqExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);
    std::shared_ptr<Expression> get_left_exp();
    std::shared_ptr<Expression> get_right_exp();
    void accept(Visitor* visitor) override;

    ~GreaterEqExpression() override;
private:
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;
};


#endif //PARSEREXAMPLE_GREATEREQEXPRESSION_H
