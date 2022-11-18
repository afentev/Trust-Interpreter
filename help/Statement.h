#ifndef PARSEREXAMPLE_STATEMENT_H
#define PARSEREXAMPLE_STATEMENT_H

#include "help/Visitor.h"

class Statement {
public:
    virtual ~Statement() = default;
    virtual void accept(Visitor& visitor) = 0;
};

#endif //PARSEREXAMPLE_STATEMENT_H
