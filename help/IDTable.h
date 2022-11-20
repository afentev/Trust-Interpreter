#ifndef PARSEREXAMPLE_IDTABLE_H
#define PARSEREXAMPLE_IDTABLE_H

#include <stack>
#include <unordered_map>
#include "help/Identifier.h"

class IDTable {
public:
    void add_scope();
    void left_scope();
    void add_identifier(const std::string&, std::shared_ptr<Object> obj, bool is_const, bool is_init);
    void mut_identifier(const std::string&, std::shared_ptr<Object>);
    std::shared_ptr<Object> get_identifier(const std::string&);
    uint8_t get_scope();
    ~IDTable();
private:
    std::unordered_map<std::string, std::stack<Identifier>> identifiers;
    std::stack<std::string> stack;
    uint8_t current_scope;
};


#endif //PARSEREXAMPLE_IDTABLE_H
