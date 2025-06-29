#include <stdint.h>

int main()
{
    uint64_t what_is_it;                               // <-- to be or not to be!
    uint64_t what_is_it_supposed_to_be;                // <-- ...

    while (what_is_it)
        what_is_it = what_is_it_supposed_to_be;
    return 0;
}
