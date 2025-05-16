#include <gtest/gtest.h>

class point
{
public:
    point(int x, int y)
    : x{x}, y{y} {}

    int x;
    int y;
};

struct pointcloud
{
    pointcloud(point p1, point p2)                     // <--- explicit ctor
    {
        points.push_back(p1);
        points.push_back(p2);
        explicit_ctor_called = true;
        initlist_ctor_called = false;
    }
    pointcloud(std::initializer_list<point> points)    // <--- initializer_list ctor
    : points(points)
    {
        explicit_ctor_called = false;
        initlist_ctor_called = true;
    }

    std::vector<point> points;

    bool initlist_ctor_called;
    bool explicit_ctor_called;
};

TEST(brace_initialization_suite, explicit_ctor)
{
    point p1{1,2};
    point p2{3,4};

    pointcloud cloud(p1, p2);                          // <--- using explicit ctor

    ASSERT_TRUE(cloud.explicit_ctor_called);
    ASSERT_EQ(cloud.points.size(), 2);
}

TEST(brace_initialization_suite, initlist_ctor)
{
    point p1{1,2};
    point p2{3,4};

    pointcloud cloud{p1, p2};                          // <--- initializer_list ctor

    ASSERT_EQ(cloud.points.size(), 2);
    ASSERT_TRUE(cloud.initlist_ctor_called);
}

