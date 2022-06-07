#include <string>
#include <vector>


// incorrect: reference to temporary object
const std::string& returns_temporary()
{
    return "blah";
}

// incorrect: reference to stack object
const std::string& returns_stackobject()
{
    std::string s{"blah"};
    return s;
}

// possibly expensive: return by copy
std::string returns_copy()
{
    std::string s{"blah"};
    return s;
}

// correct but ugly: explicit output parameter
void output_parameter(std::string& s)
{
    s = "blah";
}

// possibly expensive (well, there's Return Value Optimization (RVO)):
// return by copy
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
