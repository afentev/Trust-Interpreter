#include "ForStatement.h"

template <typename IteratorType>
ForStatement<IteratorType>::ForStatement():
        variable(), iterator(nullptr), statement(nullptr) {

}

template <typename IteratorType>
void ForStatement<IteratorType>::accept(Visitor *visitor) {
    visitor->visit(this->shared_from_this());
}

template <typename IteratorType>
std::string ForStatement<IteratorType>::get_variable() {
    return variable;
}

template <typename IteratorType>
std::shared_ptr<IteratorType> ForStatement<IteratorType>::get_iterator() {
    return iterator;
}

template <typename IteratorType>
std::shared_ptr<Statement> ForStatement<IteratorType>::get_statement() {
    return statement;
}

template <typename IteratorType>
ForStatement<IteratorType>::~ForStatement() = default;
