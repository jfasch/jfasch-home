#include <string>

int main(int, const char* const* argv)
{
    int num = std::stoi(argv[1]);

    if (num < 42) [[likely]]
        return 0;
    else [[unlikely]]
        return 1;
}
