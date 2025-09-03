#include <gtest/gtest.h>

#include <map-exercises.h>                             // <--- implement this

#include <map>
#include <string>
using namespace std;

TEST(stl_exercises_suite, map_insert_remove_by_key)
{
    map<string, int> my_map = {{"eins", 1}, {"zwei", 2}};

    bool removed;

    removed = map_remove_by_key(my_map, "eins");       // <--- implement this

    ASSERT_TRUE(removed);
    ASSERT_EQ(my_map.size(), 1);
    ASSERT_TRUE(my_map.contains("zwei"));
    ASSERT_EQ(my_map["zwei"], 2);

    removed = map_remove_by_key(my_map, "eins");       // <--- implement this

    ASSERT_FALSE(removed);
    ASSERT_EQ(my_map.size(), 1);
    ASSERT_TRUE(my_map.contains("zwei"));
    ASSERT_EQ(my_map["zwei"], 2);
}
