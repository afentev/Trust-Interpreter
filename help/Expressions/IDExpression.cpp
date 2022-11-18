#include "IDExpression.h"

void IDExpression::accept(Visitor* visitor) {

}

IDExpression::IDExpression(std::string id): identifier(std::move(id)) {}

std::string IDExpression::get_id() {
    return identifier;
}

