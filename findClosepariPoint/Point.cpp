#include "Point.h"
#pragma  once
Point::Point(double x, double y) : m_x(x), m_y(y)
{
}

std::ostream& operator<<(std::ostream& os, const Point& p) 
{
    os<<"P("<<p.getx()<<","<<p.gety()<<")";
    return os;
}
