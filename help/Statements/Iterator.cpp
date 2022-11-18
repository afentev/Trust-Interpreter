#include "Iterator.h"

void Iterator::accept(Visitor *visitor) {
    visitor->visit(shared_from_this());
}

Iterator::~Iterator() = default;