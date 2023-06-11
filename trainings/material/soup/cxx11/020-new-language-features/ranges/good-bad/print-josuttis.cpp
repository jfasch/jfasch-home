#include <vector>
#include <list>
#include <map>
#include <ranges>
#include <iostream>

void print(const std::ranges::input_range auto& coll) // <--- since C++20
{
    for (const auto& elem: coll)
        std::cout << elem << std::endl;
}

int main()
{
    {
        std::vector numbers = {2, 1, 4, 3, 5}; 
        print(numbers | std::ranges::views::drop(2));
    }

    // zip (since C++23) does not work with gcc 12
    // { 
    //     std::vector names = {"Caro", "Johanna", "Joerg", "Isi"};
    //     std::vector indexes = {1,2,3,4,5};
    //     for (auto [index, name]: std::ranges::zip(indexes, names))
    //         std::cout << index << ": " << name << std::endl;
    // }

    // filter (since C++20)
    {
        std::map<std::string, int> persons = {
            {"Joerg", 57},
            {"Caro", 26},
            {"Johanna", 28},
            {"Isi", 51},
        };
        for (auto [name, age]: 
                 persons
                 | std::views::filter([](auto person) { return person.second >= 50; })
        )
            std::cout << name << ',' << age << std::endl;
    }

    // keys (since C++20)
    {
        std::map<std::string, int> persons = {
            {"Joerg", 57},
            {"Caro", 26},
            {"Johanna", 28},
            {"Isi", 51},
        };
        for (auto name: 
                 persons
                 | std::views::filter([](auto person) { return person.second >= 50; })
                 | std::views::keys
        )
            std::cout << name << std::endl;
    }

    // transform (since C++20)
    {
        std::vector numbers = {2, 1, 4, 3, 5}; 
        print(numbers | std::views::transform([](auto elem) { return elem*elem; }));
    }

    // compile time errors: performance
    {
        std::vector v = {2, 1, 4, 3, 5}; 
        std::list l = {2, 1, 4, 3, 5}; 

        print(v | std::views::drop(3));
        // print(l | std::views::drop(3));   // <--- compile time error: no cheap way to advance by 3 elements!

                                             // begin() would have to walk through the list untill 3 have
                                             // been dropped

        // implementation: concepts
    }

    return 0;
}
