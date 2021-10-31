/*
* AUTHOR: HUY NGUYEN
* 11/2/2020
*/

#include "Point.h"
 //CONSTRUCTOR
Point::Point()
{
    x_ = 0;
    y_ = 0;
}

Point::Point(int x, int y)
{
    x_ = x;
    y_ = y;
}

Point::Point(const Point& other)
{
    x_ = other.get_x();
    y_ = other.get_y();
}


//GETTER - SETTERS
int Point::get_x() const
{
    return x_;
}
int Point::get_y() const
{
    return y_;
}

void Point::set_x_y(int x, int y)
{
    x_ = x;
    y_ = y;
}

//OPERATOR OVERLOAD
Point Point::operator+(const Point &rhs) const
{
    Point newPoint = *this;
    newPoint.x_ += rhs.get_x();
    newPoint.y_ += rhs.get_y();

    return newPoint;
}    

Point Point::operator-(const Point &rhs) const
{
    Point newPoint = *this;
    newPoint.x_ -= rhs.get_x();
    newPoint.y_ -= rhs.get_y();

    return newPoint;    
}

bool Point::operator==(const Point &rhs) const
{
    if(x_ == rhs.get_x() && y_ == rhs.get_y()){
        return true;
    }
    return false;
}  

bool Point::operator!=(const Point &rhs) const
{
    if(x_ != rhs.get_x() && y_ != rhs.get_y()){
            return true;
        }
        return false;
} 
