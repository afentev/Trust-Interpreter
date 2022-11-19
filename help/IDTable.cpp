#include "IDTable.h"

#include <utility>

void IDTable::add_scope() {
    ++current_scope;
}

void IDTable::left_scope() {
    --current_scope;
    while (!stack.empty() && identifiers.at(stack.top()).top().get_scope() > current_scope) {
        identifiers.at(stack.top()).pop();
        stack.pop();
    }
}

void IDTable::add_identifier(const std::string& name, const Identifier& id) {
    stack.push(name);
    identifiers[name].push(id);
}

void IDTable::mut_identifier(const std::string& name, std::shared_ptr<Object> value) {
    Identifier& object = identifiers.at(name).top();
    if (object.get_constantness()) {
        throw "Attempt of modifying non-mut identifier";
    }
    object.set_object(std::move(value));
    object.set_initialised(true);
}

std::shared_ptr<Object> IDTable::get_identifier(const std::string& name) {
    Identifier& object = identifiers.at(name).top();
    if (!object.is_initialised()) {
        throw "Use of uninitialised variable \"" + name + "\"";
    }
    return object.get_object();
}

uint8_t IDTable::get_scope() {
    return current_scope;
}

IDTable::~IDTable() = default;
