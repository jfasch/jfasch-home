#include <variant>
#include <iostream>

struct Visitor
{
    void operator()(int i) { std::cout << "int: " << i << std::endl; }
    void operator()(float f) { std::cout << "float: " << f << std::endl; }
};

int main()
{
    std::variant<int, float> v = 42; 
    Visitor visitor;

    std::visit(visitor, v);

    v = 1.234f;
    std::visit(visitor, v);

    return 0;
}
