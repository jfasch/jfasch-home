#include <gtest/gtest.h>

#include <map-exercises.h>                             // <--- implement this

#include <map>
#include <string>
using namespace std;

TEST(stl_exercises_suite, map_find)
{
    const map<string, int> my_map = {{"eins", 1}};

    bool found;
    int value;

    found = map_find(my_map, "eins", value);           // <--- implement this

    ASSERT_TRUE(found);
    ASSERT_EQ(value, 1);

    found = map_find(my_map, "zwei", value);           // <--- implement this
    ASSERT_FALSE(found);
}
