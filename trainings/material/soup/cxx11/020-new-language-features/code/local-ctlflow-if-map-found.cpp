#include <map>
#include <iostream>

const std::map<int, const char*> int_words{
    { 42, "fourty-two" },
    {  7, "seven" },
};

int main()
{
    if (auto found = int_words.find(42); found != int_words.end())
        std::cout << found->second << '\n';
    else
        std::cout << "bummer\n";
    return 0;
}
