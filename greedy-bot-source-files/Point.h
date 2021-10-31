/*
* AUTHOR: HUY NGUYEN
* 11/2/2020
*/
#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

/*
* This class represents a Point (X, y) on a 2D plane
*/
class Point {

    friend ostream& operator<<(ostream &outStream, const Point &myPoint)
    {
        outStream << "x: " << myPoint.get_x() << " y: " << myPoint.get_y();
        return outStream;
    }

public:
    //CONSTRUCTOR
    Point();
    Point(int x, int y);
    Point(const Point& other);

    //GETTER - SETTERS
    int get_x() const;
    int get_y() const;
    void set_x_y(int x, int y);

    //OPERATOR OVERLOAD
    /*
    * Allowable operations on Points are add, minus, equal and not equal
    */
    Point operator+(const Point &rhs) const;    
    Point operator-(const Point &rhs) const; 
    bool operator==(const Point &rhs) const;    
    bool operator!=(const Point &rhs) const; 

private:
    int x_;
    int y_;
};
#endif
