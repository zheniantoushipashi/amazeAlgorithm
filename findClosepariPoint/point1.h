#include<iostream>
#pragma  once
class  Point
{
    public:
	 Point(double x, double y);
	 double  getx() const
	 {
	    return  m_x;
	 }
	 double  gety() const
	 {
	    return  m_y;
	 }
	 friend  std::ostream &  operator <<(std::ostream& os, const Point& p);
    private:
	 double m_x;
	 double m_y;
}
