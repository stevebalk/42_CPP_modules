#include "Point.hpp"
#include <cassert>

int main() {
	Point triangle[] =	{
	Point(0.0f, 0.0f),
	Point(1.0f, 0.0f),
	Point(0.0f, 1.0f)
	};

	// Test point inside the triangle
	Point inside_point(0.25f, 0.25f);
	assert(bsp(triangle[0], triangle[1], triangle[2], inside_point) == true);

	// Test point outside the triangle
	Point outside_point(0.505f, 0.505f);
	assert(bsp(triangle[0], triangle[1], triangle[2], outside_point) == false);

	std::cout << "All tests passed!" << std::endl;
	return 0;
}
