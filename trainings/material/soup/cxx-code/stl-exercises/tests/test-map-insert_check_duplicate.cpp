#include <gtest/gtest.h>

#include <map-exercises.h>                             // <--- implement this

#include <map>
#include <string>
using namespace std;

TEST(stl_exercises_suite, map_insert_check_duplicate)
{
    map<string, int> my_map = {{"eins", 1}};

    bool inserted;

    inserted = map_insert_check_duplicate(             // <--- implement this
        my_map, "eins", 2);

    ASSERT_FALSE(inserted);
    ASSERT_EQ(my_map.size(), 1);
    ASSERT_TRUE(my_map.contains("eins"));
    ASSERT_EQ(my_map["eins"], 1);

    inserted = map_insert_check_duplicate(             // <--- implement this
        my_map, "zwei", 2);

    ASSERT_TRUE(inserted);
    ASSERT_EQ(my_map.size(), 2);
    ASSERT_TRUE(my_map.contains("eins"));
    ASSERT_TRUE(my_map.contains("zwei"));
    ASSERT_EQ(my_map["eins"], 1);
    ASSERT_EQ(my_map["zwei"], 2);
}
