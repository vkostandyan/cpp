#ifndef Point_HPP
# define Point_HPP

#include "Fixed.hpp"

class Point
{
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point& other);
        Point& operator=(const Point& rhs);
        ~Point();

    public:
        float getX(void) const;
        float getY(void) const;

    private:
        const Fixed x;
        const Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif