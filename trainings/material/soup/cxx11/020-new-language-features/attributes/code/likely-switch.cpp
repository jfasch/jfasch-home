#include <string>

int main(int, const char* const* argv)
{
    int num = std::stoi(argv[1]);

    switch (num) {
        case 1: [[fallthrough]];
        case 2: [[fallthrough]];
        case 3: [[fallthrough]];
        // ...
        // even though 1..41 fall through to 42, they aren't as
        // likely as 42
        // ...
        case 41: [[fallthrough]];

        [[likely]] case 42:
            return 0;
        default:
            return 1;
    }
}
