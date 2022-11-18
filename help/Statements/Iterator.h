#ifndef PARSEREXAMPLE_ITERATOR_H
#define PARSEREXAMPLE_ITERATOR_H

#include <memory>
#include "help/Statement.h"

class Iterator: public Statement, public std::enable_shared_from_this<Iterator> {
    void accept(Visitor* visitor) override;
    ~Iterator() override;
};


#endif //PARSEREXAMPLE_ITERATOR_H
