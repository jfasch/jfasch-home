#include <gtest/gtest.h>

#include <sorted.h>        // <--- implement this
#include <vector>

using namespace std;

TEST(stl_exercises_suite, sorted)
{
    const vector<int> input = {42, 3, 42, 5, 6, 7, 5, 3, 666};
    const vector<int> orig_input = input;

    const vector<int> output = sorted(input);

    const vector<int> required_output = {3, 3, 5, 5, 6, 7, 42, 42, 666}; 
    ASSERT_EQ(output, required_output);
}
