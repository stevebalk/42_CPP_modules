#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {
public:
	Point();
	Point(const float _x, const float _y);
	Point(const Point &rhs);
	Point &operator=(const Point &rhs);
	~Point();

	Fixed getX(void) const;
	Fixed getY(void) const;

private:
	Fixed const _x;
	Fixed const _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
