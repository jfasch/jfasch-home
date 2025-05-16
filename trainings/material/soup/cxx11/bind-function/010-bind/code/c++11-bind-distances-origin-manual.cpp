#include <cmath>
#include <iostream>


struct Point
{
    Point(double x, double y)
      : x(x), y(y) {}
    double x, y;
};

double distance(Point p, Point q)
{
    return std::sqrt(
        std::pow(std::abs(p.x-q.x), 2) +
        std::pow(std::abs(p.y-q.y), 2)
    );
}

double distance_origin(Point p)
{
    return distance(p, {0,0});
}

int main()
{
    Point points[]{{1,2}, {3,4}, {5,6}};
    double origin_distances[sizeof(points)/sizeof(Point)];

    // compute origin-distances of points
    int i=0;     
    for (auto p: points)
        origin_distances[i++] = distance_origin(p);

    for (double dist: origin_distances)
        std::cout << dist << std::endl;
    
    return 0;
}
