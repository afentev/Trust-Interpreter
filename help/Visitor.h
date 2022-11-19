#ifndef PARSEREXAMPLE_VISITOR_H
#define PARSEREXAMPLE_VISITOR_H

#include <memory>
#include "help/IDTable.h"

class Object;
class Visitor;
class Expression;
class Program;
class Statement;
class Statements;
class VariableDeclaration;
class VariableDeclInit;
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

class WhileStatement;
class IfStatement;
class IfElseStatement;
class ForStatement;
class Iterator;
class AssignmentStatement;
class ExpressionList;
class PrintStatement;
class BreakStatement;
class ContinueStatement;

class Visitor {
public:
    virtual void visit(std::shared_ptr<Program> expression);

//    virtual std::shared_ptr<Object> visit(std::shared_ptr<Object> expression);
    virtual void visit(std::shared_ptr<Boolean> expression);
    virtual void visit(std::shared_ptr<Integer> expression);
    virtual void visit(std::shared_ptr<String> expression);
    virtual void visit(std::shared_ptr<NotExpression> expression);
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

    virtual void visit(std::shared_ptr<Statements> expression);
    virtual void visit(std::shared_ptr<VariableDeclaration> expression);
    virtual void visit(std::shared_ptr<VariableDeclInit> expression);
    virtual void visit(std::shared_ptr<WhileStatement> expression);
    virtual void visit(std::shared_ptr<IfStatement> expression);
    virtual void visit(std::shared_ptr<IfElseStatement> expression);
    virtual void visit(std::shared_ptr<ForStatement> expression);
    virtual void visit(std::shared_ptr<Iterator> expression);
    virtual void visit(std::shared_ptr<AssignmentStatement> expression);
    virtual void visit(std::shared_ptr<ExpressionList> expression);
    virtual void visit(std::shared_ptr<PrintStatement> expression);
    virtual void visit(std::shared_ptr<BreakStatement> expression);
    virtual void visit(std::shared_ptr<ContinueStatement> expression);
    virtual ~Visitor();

    void set_object(std::shared_ptr<Object> new_value);

private:
    std::shared_ptr<Object> object;
    IDTable variables;
};


#endif //PARSEREXAMPLE_VISITOR_H
