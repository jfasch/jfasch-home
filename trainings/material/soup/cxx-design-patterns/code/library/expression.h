#pragma once

#include <string>
#include <map>


class Context
{
public:
    int get(const std::string& name) const;
    void set(const std::string& name, int value);

private:
    std::map<std::string, int> _variables;
};

class Expression
{
public:
    virtual ~Expression() {}
    virtual int evaluate() = 0;
};

class Literal : public Expression
{
public:
    Literal(int value) : _value(value) {}
    int evaluate() override;

private:
    int _value;
};

class Addition : public Expression
{
public:
    Addition(Expression& lhs, Expression& rhs)
    : _lhs(lhs), _rhs(rhs) {}

    int evaluate() override;

private:
    Expression& _lhs;
    Expression& _rhs;
};

class Subtraction : public Expression
{
public:
    Subtraction(Expression& lhs, Expression& rhs)
    : _lhs(lhs), _rhs(rhs) {}

    int evaluate() override;

private:
    Expression& _lhs;
    Expression& _rhs;
};

class Multiplication : public Expression
{
public:
    Multiplication(Expression& lhs, Expression& rhs)
    : _lhs(lhs), _rhs(rhs) {}

    int evaluate() override;

private:
    Expression& _lhs;
    Expression& _rhs;
};

class Division : public Expression
{
public:
    Division(Expression& lhs, Expression& rhs)
    : _lhs(lhs), _rhs(rhs) {}

    int evaluate() override;

private:
    Expression& _lhs;
    Expression& _rhs;
};

class Variable : public Expression
{
public:
    Variable(Context& context, const std::string& name)
    : _context(context), _name(name) {}

    int evaluate() override;
    void set(int value);

private:
    Context& _context;
    std::string _name;
};

class Assignment : public Expression
{
public:
    Assignment(Variable& var, Expression& exp)
    : _var(var), _exp(exp) {}

    int evaluate() override;

private:
    Variable& _var;
    Expression& _exp;
};
