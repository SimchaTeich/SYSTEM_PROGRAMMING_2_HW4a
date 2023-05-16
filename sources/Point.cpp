#include "Point.hpp"
#include <cmath> // sqrt, pow

using namespace ariel;


Point::Point(double x, double y) : _x(x), _y(y) {};


Point::Point(const Point& other)
{
    _x = other._x;
    _y = other._y;
};


int Point::x() const
{
    return _x;
};


int Point::y() const
{
    return _y;
};


double Point::distance(const Point& other) const
{
    return sqrt(pow(_x - other._x, 2) + pow(_y - other._y, 2));
};


string Point::print() const
{
    string pointString = "(" + std::to_string(_x) + ", " + std::to_string(_y) + ")";
    return pointString;
};


// Helps after some changes:
// https://stackoverflow.com/questions/1800138/given-a-start-and-end-point-and-a-distance-calculate-a-point-along-a-line
Point Point::moveToWards(const Point& src, const Point& dst, double distance)
{
    double vx = dst._x - src._x;
    double vy = dst._y - src._y;

    double mag = sqrt(vx * vx + vy * vy);

    vx /= mag;
    vy /= mag;

    double new_x = src._x + vx * (mag - distance);
    double new_y = src._y + vy * (mag - distance);

    return Point(new_x, new_y);
}
