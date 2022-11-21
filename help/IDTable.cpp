#include "IDTable.h"

#include <utility>
#include "help/Types/ObjectCreation.h"

void IDTable::add_scope() {
    ++current_scope;
}

void IDTable::left_scope() {
    --current_scope;
    unwind_stack();
}

void IDTable::unwind_stack() {
    while (!stack.empty() && identifiers.at(stack.top()).top().get_scope() > current_scope) {
        identifiers.at(stack.top()).pop();
        stack.pop();
    }
}

void IDTable::add_identifier(const std::string& name, std::shared_ptr<Object> obj, bool is_const, bool is_init) {
    Identifier id(create_object(obj->get_type()), get_scope(), is_const, is_init);
    id.set_object(obj);
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

void IDTable::reduce_scope(uint16_t new_scope) {
    current_scope = new_scope;
    unwind_stack();
}

uint16_t IDTable::get_scope() {
    return current_scope;
}

IDTable::~IDTable() = default;
