#ifndef PARSEREXAMPLE_VISITOR_H
#define PARSEREXAMPLE_VISITOR_H

#include <memory>

class Object;
class Visitor;
class Expression;
class Program;
class Statement;
class Statements;
class VariableDeclaration;
class Boolean;
class String;
class Integer;
class NotExpression;
class AndExpression;
class OrExpression;
class EqualExpression;
class NotEqualExpression;
class LessEqExpression;
class LessExpression;
class GreaterEqExpression;
class GreaterExpression;
class PlusExpression;
class MinusExpression;
class UnaryMinusExpression;
class MulExpression;
class DivExpression;
class ModExpression;
class IDExpression;

class Visitor {
public:
    virtual void visit(std::shared_ptr<Program> expression);
    virtual void visit(std::shared_ptr<Statement> expression);
    virtual void visit(std::shared_ptr<Statements> expression);
    virtual void visit(std::shared_ptr<Expression> expression);
    virtual void visit(std::shared_ptr<VariableDeclaration> expression);
    virtual void visit(std::shared_ptr<Object> expression);
    virtual void visit(std::shared_ptr<Boolean> expression);
    virtual void visit(std::shared_ptr<Integer> expression);
    virtual void visit(std::shared_ptr<String> expression);
    virtual void visit(std::shared_ptr<AndExpression> expression);
    virtual void visit(std::shared_ptr<OrExpression> expression);
    virtual void visit(std::shared_ptr<DivExpression> expression);
    virtual void visit(std::shared_ptr<MulExpression> expression);
    virtual void visit(std::shared_ptr<ModExpression> expression);
    virtual void visit(std::shared_ptr<PlusExpression> expression);
    virtual void visit(std::shared_ptr<MinusExpression> expression);
    virtual void visit(std::shared_ptr<UnaryMinusExpression> expression);
    virtual void visit(std::shared_ptr<GreaterExpression> expression);
    virtual void visit(std::shared_ptr<GreaterEqExpression> expression);
    virtual void visit(std::shared_ptr<EqualExpression> expression);
    virtual void visit(std::shared_ptr<NotEqualExpression> expression);
    virtual void visit(std::shared_ptr<LessEqExpression> expression);
    virtual void visit(std::shared_ptr<LessExpression> expression);
    virtual void visit(std::shared_ptr<IDExpression> expression);
    virtual ~Visitor();

    std::shared_ptr<Object> object;
};


#endif //PARSEREXAMPLE_VISITOR_H
