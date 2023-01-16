#include <gtest/gtest.h>

#include <filter-odd.h>                                // <--- implement this
#include <vector>

using namespace std;

TEST(stl_exercises_suite, filter_odd)
{
    const vector<int> input = {42, 3, 42, 5, 6, 7, 5, 3, 666};
    const vector<int> orig_input = input;

    const vector<int> output = filter_odd(input);      // <--- implement this

    const vector<int> required_output = {3, 5, 7, 5, 3};
    ASSERT_EQ(output, required_output);
    ASSERT_EQ(input, orig_input);                      // <--- function must not modify input
}
