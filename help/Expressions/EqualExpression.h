#ifndef PARSEREXAMPLE_EQUALEXPRESSION_H
#define PARSEREXAMPLE_EQUALEXPRESSION_H


#include <memory>
#include "help/Expression.h"

class EqualExpression: public Expression, public std::enable_shared_from_this<EqualExpression> {
public:
    EqualExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);
    std::shared_ptr<Expression> get_left_exp();
    std::shared_ptr<Expression> get_right_exp();
    void accept(Visitor* visitor) override;

    ~EqualExpression() override;
private:
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;
};


#endif //PARSEREXAMPLE_EQUALEXPRESSION_H
