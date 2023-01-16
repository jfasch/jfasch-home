#include <gtest/gtest.h>

#include <vector-exercises.h>                          // <--- implement this

#include <vector>
#include <string>
using namespace std;

TEST(stl_exercises_suite, vector_append)
{
    vector<string> my_vec = {"Joerg", "Caro", "Isi", "Johanna"};
    
    vector_append(my_vec, "Philipp");                  // <--- implement this

    ASSERT_EQ(my_vec.size(), 5);
    ASSERT_EQ(my_vec[4], "Philipp");
}
