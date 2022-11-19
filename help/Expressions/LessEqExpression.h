#ifndef PARSEREXAMPLE_LESSEQEXPRESSION_H
#define PARSEREXAMPLE_LESSEQEXPRESSION_H

#include <memory>
#include "Expression.h"

class LessEqExpression: public Expression, public std::enable_shared_from_this<LessEqExpression> {
public:
    LessEqExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);
    std::shared_ptr<Expression> get_left_exp();
    std::shared_ptr<Expression> get_right_exp();
    void accept(Visitor* visitor) override;

    ~LessEqExpression() override;
private:
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;
};


#endif //PARSEREXAMPLE_LESSEQEXPRESSION_H
