#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>


class Point
{
public:
    Point(int x, int y) : _x(x), _y(y) {}
    int x() const { return _x; }
    int y() const { return _y; }
private:
    int _x;
    int _y;
};


bool x_equals_666(const Point& p)
{
    if (p.x() == 666)
        return true;
    else
        return false;
}

bool x_equals_4(const Point& p)
{
    if (p.x() == 4)
        return true;
    else
        return false;
}

class x_equal
{
public:
    x_equal(int criterion) : _criterion(criterion) {}
    bool operator()(const Point& p) const
    {
        if (p.x() == _criterion)
            return true;
        else
            return false;
    }
private:
    int _criterion;
};

int main()
{
    std::vector<Point> points;
    points.push_back(Point(1, 2));
    points.push_back(Point(2, 3));
    points.push_back(Point(4, 5));
    points.push_back(Point(666, 42));
    points.push_back(Point(666, 43));

    // for (size_t i=0; i<points.size(); i++) {
    //     if (points[i].x() == 666) {
    //         cout << '(' << points[i].x() << ',' << points[i].y() << ')' << endl;
    //         break;
    //     }
    // }

    // for (size_t i=0; i<points.size(); i++) {
    //     bool yesno = x_equals_666(points[i]);
    //     if (yesno) {
    //         cout << '(' << points[i].x() << ',' << points[i].y() << ')' << endl;
    //         break;
    //     }
    // }

    // std::vector<Point>::const_iterator found = std::find_if(points.begin(), points.end(), x_equals_666);
    // if (found != points.end())
    //     cout << '(' << found->x() << ',' << found->y() << ')' << endl;

    // found = std::find_if(points.begin(), points.end(), x_equals_4);
    // if (found != points.end())
    //     cout << '(' << found->x() << ',' << found->y() << ')' << endl;

    std::vector<Point>::const_iterator found = std::find_if(points.begin(), points.end(), x_equal(666));
    if (found != points.end())
        cout << '(' << found->x() << ',' << found->y() << ')' << endl;

    found = std::find_if(points.begin(), points.end(), x_equal(4));
    if (found != points.end())
        cout << '(' << found->x() << ',' << found->y() << ')' << endl;

    return 0;
}
