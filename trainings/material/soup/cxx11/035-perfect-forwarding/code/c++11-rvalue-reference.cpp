#include <string>

void function(std::string&& rvref)
{
}

int main()
{
    std::string lvalue;
    function(lvalue);
    return 0;
}
