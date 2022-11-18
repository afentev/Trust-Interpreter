#ifndef PARSEREXAMPLE_LESSEXPRESSION_H
#define PARSEREXAMPLE_LESSEXPRESSION_H

#include <memory>
#include "help/Expression.h"

class LessExpression: public Expression, public std::enable_shared_from_this<LessExpression> {
public:
    LessExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);
    std::shared_ptr<Expression> get_left_exp();
    std::shared_ptr<Expression> get_right_exp();
    void accept(Visitor* visitor) override;

    ~LessExpression() override;
private:
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;
};


#endif //PARSEREXAMPLE_LESSEXPRESSION_H
