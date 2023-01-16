#include <gtest/gtest.h>

#include <vector-exercises.h>                          // <--- implement this

#include <vector>
#include <string>
using namespace std;

TEST(stl_exercises_suite, vector_join)
{
    const vector<string> my_vec = {"Word1", "Word2", "Word3"};

    string joined_content = vector_join(my_vec, ':');  // <--- implement this

    ASSERT_EQ(joined_content, "Word1:Word2:Word3");
}
