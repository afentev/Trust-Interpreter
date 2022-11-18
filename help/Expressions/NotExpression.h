#ifndef PARSEREXAMPLE_NOTEXPRESSION_H
#define PARSEREXAMPLE_NOTEXPRESSION_H

#include <memory>
#include "help/Expression.h"

class NotExpression: public Expression {
public:
    NotExpression(std::shared_ptr<Expression> expression);
    void accept(Visitor& visitor) override;
    std::shared_ptr<Expression> get_expression();

    ~NotExpression() override;
private:
    std::shared_ptr<Expression> expression;
};


#endif //PARSEREXAMPLE_NOTEXPRESSION_H
