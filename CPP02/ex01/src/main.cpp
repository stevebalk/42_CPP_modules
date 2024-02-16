#include "Fixed.hpp"

// int main(void) {
// 	float numbers[3] = { 1234.4321f, 10, 42.42f };
// 	Fixed a;
// 	Fixed const b(numbers[1]);
// 	Fixed const c(numbers[2]);
// 	Fixed const d(b);

// 	a = Fixed(numbers[0]);

// 	std::cout << std::endl;
// 	std::cout << "[a] before   " << numbers[0] << std::endl;
// 	std::cout << "    raw:     " << a.getRawBits() << std::endl;
// 	std::cout << "    after:   " << a << std::endl;
// 	std::cout << "    integer: " << a.toInt() << std::endl
// 			  << std::endl;
// 	std::cout << "[b] before   " << numbers[1] << std::endl;
// 	std::cout << "    raw:     " << b.getRawBits() << std::endl;
// 	std::cout << "    after:   " << b << std::endl;
// 	std::cout << "    integer: " << b.toInt() << std::endl
// 			  << std::endl;
// 	std::cout << "[c] before   " << numbers[2] << std::endl;
// 	std::cout << "    raw:     " << c.getRawBits() << std::endl;
// 	std::cout << "    after:   " << c << std::endl;
// 	std::cout << "    integer: " << c.toInt() << std::endl
// 			  << std::endl;
// 	std::cout << "[d] before   " << numbers[1] << std::endl;
// 	std::cout << "    raw:     " << d.getRawBits() << std::endl;
// 	std::cout << "    after:   " << d << std::endl;
// 	std::cout << "    integer: " << d.toInt() << std::endl
// 			  << std::endl;

// 	return 0;
// }

int main(void) {
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}
