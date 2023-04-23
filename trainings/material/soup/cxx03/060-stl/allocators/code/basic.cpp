#include <gtest/gtest.h>

#include <memory>


TEST(allocator_suite, alloc_uninit)
{
    std::allocator<int> alloc;
    int* allocation = alloc.allocate(2);
    alloc.deallocate(allocation, 2);
}


struct Foo
{
    Foo(int i) { n_objects++; }
    ~Foo() { n_objects--; }

    int i{666};
    static inline int n_objects = 0;
};

TEST(allocator_suite, alloc_construct)
{
    std::allocator<Foo> heap;
    using traits = std::allocator_traits<std::allocator<Foo>>;

    Foo* allocation = traits::allocate(heap, 2);
    ASSERT_EQ(Foo::n_objects, 0);

    traits::construct(heap, &allocation[0], 7);        // <--- placement new, internally
    ASSERT_EQ(Foo::n_objects, 1);

    traits::destroy(heap, &allocation[0]);             // <--- explicit dtor, internally
    ASSERT_EQ(Foo::n_objects, 0);

    traits::deallocate(heap, allocation, 2);
}
