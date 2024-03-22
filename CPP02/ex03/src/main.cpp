#include "Point.hpp"
#include <cassert>
#include "bsp.cpp"

int main() {
	Point triangle[] =	{
	Point(0.0f, 0.0f),
	Point(1.0f, 0.0f),
	Point(0.0f, 1.0f)
	};

	// Test point inside the triangle
	Point inside_point(0.25f, 0.25f);
	if (bsp(triangle[0], triangle[1], triangle[2], inside_point) == true) {
		std::cout << "Point 1 is inside" << std::endl;
	} else {
		std::cout << "Point 1 point is outside" << std::endl;
	}

	// Test point outside the triangle
	Point outside_point(0.51f, 0.51f);
	if (bsp(triangle[0], triangle[1], triangle[2], outside_point) == true) {
		std::cout << "Point 2 is inside" << std::endl;
	} else {
		std::cout << "Point 2 is outside" << std::endl;
	}

	return 0;
}
