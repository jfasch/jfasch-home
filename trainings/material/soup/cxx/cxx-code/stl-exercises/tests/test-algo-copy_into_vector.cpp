#include <gtest/gtest.h>

#include <algo-exercises.h>                            // <--- implement this

#include <vector>
#include <string>
using namespace std;

TEST(stl_exercises_suite, copy_into_vector)
{
    const char* src[] = {"Joerg", "Caro", "Isi", "Johanna"};
    vector<string> dst;

    copy_into_vector(src, 4, dst);                     // <--- implement this

    ASSERT_EQ(dst.size(), 4);
    const vector<string> required_content = {"Joerg", "Caro", "Isi", "Johanna"};
    ASSERT_EQ(dst, required_content);
}
