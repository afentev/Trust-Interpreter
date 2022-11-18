#ifndef PARSEREXAMPLE_UNARYMINUSEXPRESSION_H
#define PARSEREXAMPLE_UNARYMINUSEXPRESSION_H

#include <memory>
#include "help/Expression.h"

class UnaryMinusExpression: public Expression {
public:
    UnaryMinusExpression(std::shared_ptr<Expression> expression);
    void accept(Visitor* visitor) override;
    std::shared_ptr<Expression> get_expression();

    ~UnaryMinusExpression() override;
private:
    std::shared_ptr<Expression> expression;
};




#endif //PARSEREXAMPLE_UNARYMINUSEXPRESSION_H
