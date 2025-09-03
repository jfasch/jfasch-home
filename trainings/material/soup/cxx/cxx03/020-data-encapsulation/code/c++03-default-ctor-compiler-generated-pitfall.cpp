#include <iostream>

class Something
{
public:
    int i;
};

void dirty_stack()
{
    Something sth;
    sth.i = 666;
    (void)sth; // avoid "unused" warning
}

void use_uninitialized()
{
    Something sth;
    std::cout << "sth.i: " << sth.i << std::endl;
}

int main()
{
    dirty_stack();        // <--- write 666 onto stack, AND LEAVE IT THERE
    use_uninitialized();  // <--- TRAPPED!
    return 0;
}
