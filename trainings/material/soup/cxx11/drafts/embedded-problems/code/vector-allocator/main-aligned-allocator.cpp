#include <vector>
#include <iostream>

template <typename T>
class AlignedAllocator
{
public:
    using value_type = T;
    using pointer = T*;

    pointer allocate(size_t n, [[maybe_unused]] const void* localityhint = nullptr)
    {
        return reinterpret_cast<T*>(std::aligned_alloc(alignof(T), n*sizeof(T)));
    }
    void deallocate(pointer p, [[maybe_unused]] size_t n)
    {
        free(p);
    }
};

int main()
{
    std::vector<int, AlignedAllocator<int>> v{1, 2, 3, 4, 5};
    for (int i: v)
        std::cout << i << std::endl;
    return 0;
}
