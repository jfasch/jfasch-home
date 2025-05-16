#include <iostream>
#include <vector>
#include <concepts>

// template <typename T>
// void print(const T& obj)
// {
//     std::cout << obj << std::endl;
// }


// can be iterated over using range based for

// * std::begin(obj) returns begin iterator

// * std::end(obj) returns end iterator

// * begin supports ++ (pre-inc)

// * begin != end is (convertible to) bool

// * *begin (not void)

// * begin and end are copy constructible and destructible 40:16

// 34:11 Neqable
template <typename BEGIN, typename END>
concept not_equal_able = requires(BEGIN b, END e) {
    { b != e } -> std::convertible_to<bool>;
};

// usage 1
template <typename BEGIN, typename END>
requires not_equal_able<BEGIN, END>
bool foo1(BEGIN b, END e)
{
    return true;
}

// usage 2
template <typename BEGIN, typename END>
bool foo2(BEGIN b, END e) requires not_equal_able<BEGIN, END>
{
    return true;
}

template <typename CONTAINER>
concept has_begin = requires(CONTAINER c) {
    std::begin(c);
};

template <typename CONTAINER>
concept has_end = requires(CONTAINER c) {
    std::end(c);
};

template <typename CONTAINER>
concept begin_has_increment = requires(CONTAINER c) {
    ++std::begin(c);
};

template <typename CONTAINER>
concept begin_ne_end_is_bool = requires(CONTAINER c) {
    { std::begin(c) != std::end(c) } -> std::same_as<bool>;
};

template <typename CONTAINER>
concept begin_dereferenceable = requires(CONTAINER c) {
    *std::begin(c);
};

template <typename CONTAINER>
concept begin_deference_is_void = requires(CONTAINER c) {
    { *std::begin(c) } -> std::same_as<void>;
};

template <typename CONTAINER>
concept begin_is_copy_constructible = requires(CONTAINER c) {
    requires std::copy_constructible<decltype(std::begin(c))>;
};

template <typename CONTAINER>
concept end_is_copy_constructible = requires(CONTAINER c) {
    requires std::copy_constructible<decltype(std::end(c))>;
};

template <typename CONTAINER>
concept begin_is_destructible = requires(CONTAINER c) {
    requires std::destructible<decltype(std::begin(c))>;
};

template <typename CONTAINER>
concept end_is_destructible = requires(CONTAINER c) {
    requires std::destructible<decltype(std::end(c))>;
};


template <typename T>
concept is_container = 
    has_begin<T> &&
    has_end<T> &&
    begin_has_increment<T> &&
    begin_ne_end_is_bool<T> &&
    begin_dereferenceable<T> &&
    ! begin_deference_is_void<T> &&
    begin_is_copy_constructible<T> &&
    end_is_copy_constructible<T> &&
    begin_is_destructible<T> &&
    end_is_destructible<T>;

template <typename T>
requires is_container<T>
void print(const T& obj)
{
    std::cout << "container" << std::endl;
}

template <typename T>
requires std::integral<T>
void print(const T& obj)
{
    std::cout << "integral" << std::endl;
}

int main()
{
    std::vector<int> v;
    std::cout << foo1(v.begin(), v.end()) << std::endl;
    std::cout << foo2(v.begin(), v.end()) << std::endl;

    print(v);
    print(42);
    return 0;
}
