//
// Created by System Administrator on 11/18/22.
//

#ifndef PARSEREXAMPLE_PLUSEXPRESSION_H
#define PARSEREXAMPLE_PLUSEXPRESSION_H

#include <memory>
#include "Expression.h"

class PlusExpression: public Expression, public std::enable_shared_from_this<PlusExpression> {
public:
    PlusExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);
    std::shared_ptr<Expression> get_left_exp();
    std::shared_ptr<Expression> get_right_exp();
    void accept(Visitor* visitor) override;

    ~PlusExpression() override;
private:
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;
};



#endif //PARSEREXAMPLE_PLUSEXPRESSION_H
