#include <gtest/gtest.h>

#include <algo-exercises.h>                            // <--- implement this

#include <vector>
#include <string>
using namespace std;

TEST(stl_exercises_suite, find_in_vector)
{
    const vector<string> my_vec = {"Joerg", "Caro", "Isi", "Johanna"};
    
    bool found;

    found = find_in_vector(my_vec, "Isi");             // <--- implement this
    ASSERT_TRUE(found);
    
    found = find_in_vector(my_vec, "Wladimir");        // <--- implement this
    ASSERT_FALSE(found);
}
