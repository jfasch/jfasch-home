#include "expression.h"

#include <stdexcept>
#include <iostream>


int Context::get(const std::string& name) const
{
    auto found = _variables.find(name);
    if (found == _variables.end())
        return 0;
    return found->second;
}

void Context::set(const std::string& name, int value)
{
    _variables[name] = value;
}

int Literal::evaluate()
{
    return _value;
}

int Addition::evaluate()
{
    return _lhs.evaluate() + _rhs.evaluate();
}

int Subtraction::evaluate()
{
    return _lhs.evaluate() - _rhs.evaluate();
}

int Multiplication::evaluate()
{
    return _lhs.evaluate() * _rhs.evaluate();
}

int Division::evaluate()
{
    return _lhs.evaluate() / _rhs.evaluate();
}

int Variable::evaluate()
{
    return _context.get(_name);
}

void Variable::set(int value)
{
    _context.set(_name, value);
}

int Assignment::evaluate()
{
    int value = _exp.evaluate();
    _var.set(value);
    return value;
}
