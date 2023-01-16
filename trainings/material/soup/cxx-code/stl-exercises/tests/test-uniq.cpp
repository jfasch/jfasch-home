#include <gtest/gtest.h>

#include <uniq.h>                                      // <--- implement this
#include <vector>

using namespace std;

TEST(stl_exercises_suite, uniq)
{
    const vector<int> input = {42, 3, 42, 5, 6, 7, 5, 3, 666};
    const vector<int> orig_input = input;

    const vector<int> output = uniq(input);            // <--- implement this

    const vector<int> required_output = {42, 3, 5, 6, 7, 666}; 
    ASSERT_EQ(output, required_output);
    ASSERT_EQ(input, orig_input);                      // <--- function must not modify input
}
