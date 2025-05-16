#include <gtest/gtest.h>

#include <initializer_list>
#include <vector>
#include <iostream>

TEST(initializer_list_suite, vector_init)
{
    std::vector<int> ints{1, 2, 3};
    std::vector<std::pair<int, std::string>> pairs{{1, "one"}, {2, "two"}};
}

struct point
{
    int x, y;
};

static void do_something_with(point) { /* ... */ }

TEST(initializer_list_suite, direct_usage)
{
    std::initializer_list<point> points {{1, 2}, {3, 4}};
    for (auto p: points)
        do_something_with(p);
}

class PointCloud
{
public:
    PointCloud(std::initializer_list<point> points) : _points(points) {}
private:
    std::vector<point> _points;
};

TEST(initializer_list_suite, cloud)
{
    PointCloud cloud{{1, 2}, {2, 3}};
}

