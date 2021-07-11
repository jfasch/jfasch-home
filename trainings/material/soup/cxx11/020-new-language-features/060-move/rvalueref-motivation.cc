#include <string>
#include <vector>


const std::string& returns_temporary()
{
    return "blah";
}

const std::string& returns_stackobject()
{
    std::string s{"blah"};
    return s;
}

std::string returns_copy()
{
    std::string s{"blah"};
    return s;
}

void output_parameter(std::string& s)
{
    s = "blah";
}

std::vector<int> returns_vector_by_copy()
{
    std::vector<int> v;
    int i=100000;
    while (i--)
        v.push_back(i);
    return v;
}

int main()
{
    std::string s;
    s = returns_temporary();
    s = returns_stackobject();
    s = returns_copy();
    output_parameter(s);
    auto v = returns_vector_by_copy();
}
