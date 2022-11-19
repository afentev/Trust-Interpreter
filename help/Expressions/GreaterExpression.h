#ifndef PARSEREXAMPLE_GREATEREXPRESSION_H
#define PARSEREXAMPLE_GREATEREXPRESSION_H

#include <memory>
#include "Expression.h"

class GreaterExpression: public Expression, public std::enable_shared_from_this<GreaterExpression> {
public:
    GreaterExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);
    std::shared_ptr<Expression> get_left_exp();
    std::shared_ptr<Expression> get_right_exp();
    void accept(Visitor* visitor) override;

    ~GreaterExpression() override;
private:
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;
};


#endif //PARSEREXAMPLE_GREATEREXPRESSION_H
