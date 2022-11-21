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
    uint16_t get_scope();
    void reduce_scope(uint16_t new_scope);  // used when break or continue happens
    ~IDTable();
private:
    void unwind_stack();
    std::unordered_map<std::string, std::stack<Identifier>> identifiers;
    std::stack<std::string> stack;
    uint16_t current_scope = 0;
};


#endif //PARSEREXAMPLE_IDTABLE_H
