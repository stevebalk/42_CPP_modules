#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}


// int main() {
// 	Fixed a(3.5f);
// 	Fixed b(2.5f);
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << a << " >  " << b << " : " << (a > b ? "True" : "False") << std::endl;
// 	std::cout << a << " <  " << b << " : " << (a < b ? "True" : "False") << std::endl;
// 	std::cout << a << " >= " << b << " : " << (a >= b ? "True" : "False") << std::endl;
// 	std::cout << a << " <= " << b << " : " << (a <= b ? "True" : "False") << std::endl;
// 	std::cout << a << " == " << b << " : " << (a == b ? "True" : "False") << std::endl;
// 	std::cout << a << " != " << b << " : " << (a != b ? "True" : "False") << std::endl;
// 	std::cout << std::endl;

// 	// Arithmetic operators
// 	Fixed c = a + b;
// 	std::cout << "a + b = " << c << std::endl;
// 	Fixed d = a - b;
// 	std::cout << "a - b = " << d << std::endl;
// 	Fixed e = a * b;
// 	std::cout << "a * b = " << e << std::endl;
// 	Fixed f = a / b;
// 	std::cout << "a / b = " << f << std::endl;
// 	std::cout << std::endl;

// 	// Increment/decrement operators
// 	Fixed g = ++a; // Pre-increment
// 	std::cout << "++a = " << g << std::endl;
// 	Fixed h = a++; // Post-increment
// 	std::cout << "a++ = " << h << std::endl;
// 	std::cout << "a == " << a << std::endl;
// 	Fixed i = --b; // Pre-decrement
// 	std::cout << "--b = " << i << std::endl;
// 	Fixed j = b--; // Post-decrement
// 	std::cout << "b-- = " << j << std::endl;

// 	return 0;
// }
