#ifndef PARSEREXAMPLE_VISITOR_H
#define PARSEREXAMPLE_VISITOR_H

#include <memory>

class Number;
class Statements;
class Program;
class Object;

class Visitor {
public:
    virtual void Visit(std::shared_ptr<Program> expression);
    virtual void Visit(std::shared_ptr<Statements> expression);
//    virtual void Visit(std::shared_ptr<Number> expression);
    virtual ~Visitor();

    std::shared_ptr<Object> object;
};


#endif //PARSEREXAMPLE_VISITOR_H
