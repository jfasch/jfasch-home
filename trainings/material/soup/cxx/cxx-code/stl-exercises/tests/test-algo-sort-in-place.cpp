#include <gtest/gtest.h>

#include <sort-in-place.h>        // <--- implement this
#include <vector>

using namespace std;

TEST(stl_exercises_suite, sort_in_place)
{
    vector<int> numbers = {42, 3, 42, 5, 6, 7, 5, 3, 666};

    sort_in_place(numbers);

    vector<int> required_output = {3, 3, 5, 5, 6, 7, 42, 42, 666}; 
    ASSERT_EQ(numbers, required_output);
}
