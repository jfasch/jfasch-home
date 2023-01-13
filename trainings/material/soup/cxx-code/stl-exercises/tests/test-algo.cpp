#include <gtest/gtest.h>

#include <algo-exercises.h>   // <--- implement this

#include <vector>
#include <string>
using namespace std;


// jjj hint: pass (const) char**
// jjj try to use std::copy
TEST(stl_exercises_suite, copy_into_vector)
{
    const char* src[] = {"Joerg", "Caro", "Isi", "Johanna"};
    vector<string> dst;

    copy_into_vector(src, 4, dst);   // <--- implement this

    ASSERT_EQ(dst.size(), 4);
    const vector<string> required_content = {"Joerg", "Caro", "Isi", "Johanna"};
    ASSERT_EQ(dst, required_content);
}

TEST(stl_exercises_suite, find_in_vector)
{
    const vector<string> my_vec = {"Joerg", "Caro", "Isi", "Johanna"};
    
    bool found;

    found = find_in_vector(my_vec, "Isi");
    ASSERT_TRUE(found);
    
    found = find_in_vector(my_vec, "Wladimir");
    ASSERT_FALSE(found);
}
