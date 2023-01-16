#include <gtest/gtest.h>

#include <map-exercises.h>                             // <--- implement this

#include <map>
#include <string>
using namespace std;

TEST(stl_exercises_suite, map_insert)
{
    map<string, int> my_map;

    map_insert_simple(my_map, "eins", 1);              // <--- implement this

    ASSERT_EQ(my_map.size(), 1);
    ASSERT_TRUE(my_map.contains("eins"));
    ASSERT_EQ(my_map["eins"], 1);
}
