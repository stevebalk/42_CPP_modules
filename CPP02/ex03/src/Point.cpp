#include "Point.hpp"

Point::Point() :
		_x(0), _y(0) {}

Point::Point(const float x, const float y) :
		_x(x), _y(y) {}

Point::Point(const Point &rhs) :
		_x(rhs.getX()), _y(rhs.getY()) {
	return;
}

Point::~Point() {}

Point &Point::operator=(const Point &rhs) {
	std::cerr << "Warning! " << std::endl
			  << "Cannot assign to constant attributes. "
			  << "Use copy constructor instead" << std::endl;
	static_cast<void>(rhs);
	return *this;
}

Fixed Point::getX() const {
	return this->_x;
}

Fixed Point::getY() const {
	return this->_y;
}

static Fixed sign(Point const a, Point const b, Point const c) {
	return (a.getX() - c.getX()) * (b.getY() - c.getY()) - (b.getX() - c.getX()) * (a.getY() - c.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	bool b1 = sign(point, a, b) < 0.0f;
	bool b2 = sign(point, b, c) < 0.0f;
	bool b3 = sign(point, c, a) < 0.0f;

	return ((b1 == b2) && (b2 == b3));
}

// Fixed cross(Point const a, Point const b) {
// 	return a.getX() * b.getY() - a.getY() * b.getX();
// }

// bool getWeigths(Point const a, Point const b, Point const c, Point const point, Fixed &w_A, Fixed &w_B, Fixed &w_C) {
// 	Fixed xd = cross(a, b) + cross(b, c) + cross(c, a);

// 	if (std::abs(xd.toFloat()) < 0.0001f) {
// 		Fixed xa = cross(b, c) + cross(point, Point(b.getX().toFloat() - c.getX().toFloat(), b.getY().toFloat() - c.getY().toFloat()));
// 		Fixed xb = cross(c, a) + cross(point, Point(c.getX().toFloat() - a.getX().toFloat(), c.getY().toFloat() - a.getY().toFloat()));
// 		Fixed xc = cross(a, b) + cross(point, Point(a.getX().toFloat() - b.getX().toFloat(), a.getY().toFloat() - b.getY().toFloat()));

// 		w_A = xa / xd;
// 		w_B = xb / xd;
// 		w_C = xc / xd;
// 		return true;
// 	}

// 	w_A = 0;
// 	w_B = 0;
// 	w_C = 0;
// 	return false;
// }

// bool bsp(Point const a, Point const b, Point const c, Point const point) {
// 	Fixed w_A, w_B, w_C;
// 	if (getWeigths(a, b, c, point, w_A, w_B, w_C)) {
// 		return (w_A >= 0 && w_B >= 0 && w_C >= 0 && (w_A + w_B + w_C) <= 1);
// 	}
// 	return false;
// }

// bool bsp( Point const a, Point const b, Point const c, Point const point) {
// 	Fixed area = (Fixed)0.5f * ((b.getY() * -1) * c.getX() + a.getY() * ((b.getX()  * -1) + c.getX()) + a.getX() * (b.getY() - c.getY()) + b.getX() * c.getY());
// 	Fixed sign = area < 0 ? -1 : 1;
// 	Fixed s = (a.getY() * c.getX() - a.getX() * c.getY() + (c.getY() - a.getY()) * point.getX() + (a.getX() - c.getX()) * point.getY()) * sign;
// 	Fixed t = (a.getX() * b.getY() - a.getY() * b.getX() + (a.getY() - b.getY()) * point.getX() + (b.getX() - a.getX()) * point.getY()) * sign;

// 	return s > 0 && t > 0 && (s + t) < (Fixed)2 * area * sign;
// }

// function ptInTriangle(p, p0, p1, p2) {
//     var A = 1/2 * (-p1.y * p2.x + p0.y * (-p1.x + p2.x) + p0.x * (p1.y - p2.y) + p1.x * p2.y);
//     var sign = A < 0 ? -1 : 1;
//     var s = (p0.y * p2.x - p0.x * p2.y + (p2.y - p0.y) * p.x + (p0.x - p2.x) * p.y) * sign;
//     var t = (p0.x * p1.y - p0.y * p1.x + (p0.y - p1.y) * p.x + (p1.x - p0.x) * p.y) * sign;

//     return s > 0 && t > 0 && (s + t) < 2 * A * sign;
// }
