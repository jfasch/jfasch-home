#include <gtest/gtest.h>

#include <map-exercises.h>   // <--- implement this

#include <map>
#include <string>
using namespace std;


TEST(stl_exercises_suite, map_insert)
{
    map<string, int> my_map;

    map_insert_simple(my_map, "eins", 1);                  // <--- implement this

    ASSERT_EQ(my_map.size(), 1);
    ASSERT_TRUE(my_map.contains("eins"));
    ASSERT_EQ(my_map["eins"], 1);
}

TEST(stl_exercises_suite, map_insert_check_duplicate)
{
    map<string, int> my_map = {{"eins", 1}};

    bool inserted;

    inserted = map_insert_check_duplicate(my_map, "eins", 2);                  // <--- implement this

    ASSERT_FALSE(inserted);
    ASSERT_EQ(my_map.size(), 1);
    ASSERT_TRUE(my_map.contains("eins"));
    ASSERT_EQ(my_map["eins"], 1);

    inserted = map_insert_check_duplicate(my_map, "zwei", 2);                  // <--- implement this

    ASSERT_TRUE(inserted);
    ASSERT_EQ(my_map.size(), 2);
    ASSERT_TRUE(my_map.contains("eins"));
    ASSERT_TRUE(my_map.contains("zwei"));
    ASSERT_EQ(my_map["eins"], 1);
    ASSERT_EQ(my_map["zwei"], 2);
}

TEST(stl_exercises_suite, map_insert_remove_by_key)
{
    map<string, int> my_map = {{"eins", 1}, {"zwei", 2}};

    bool removed;

    removed = map_remove_by_key(my_map, "eins");                  // <--- implement this

    ASSERT_TRUE(removed);
    ASSERT_EQ(my_map.size(), 1);
    ASSERT_TRUE(my_map.contains("zwei"));
    ASSERT_EQ(my_map["zwei"], 2);

    removed = map_remove_by_key(my_map, "eins");                  // <--- implement this

    ASSERT_FALSE(removed);
    ASSERT_EQ(my_map.size(), 1);
    ASSERT_TRUE(my_map.contains("zwei"));
    ASSERT_EQ(my_map["zwei"], 2);
}

TEST(stl_exercises_suite, map_find)
{
    const map<string, int> my_map = {{"eins", 1}};

    bool found;
    int value;

    found = map_find(my_map, "eins", value);                  // <--- implement this

    ASSERT_TRUE(found);
    ASSERT_EQ(value, 1);

    found = map_find(my_map, "zwei", value);                  // <--- implement this
    ASSERT_FALSE(found);
}
