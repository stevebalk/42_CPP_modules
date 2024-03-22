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
