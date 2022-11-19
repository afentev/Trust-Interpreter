#ifndef PARSEREXAMPLE_MULEXPRESSION_H
#define PARSEREXAMPLE_MULEXPRESSION_H

#include <memory>
#include "Expression.h"

class MulExpression: public Expression, public std::enable_shared_from_this<MulExpression> {
public:
    MulExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);
    std::shared_ptr<Expression> get_left_exp();
    std::shared_ptr<Expression> get_right_exp();
    void accept(Visitor* visitor) override;

    ~MulExpression() override;
private:
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;
};



#endif //PARSEREXAMPLE_MULEXPRESSION_H
