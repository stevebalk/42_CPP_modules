#ifndef FIXED_HPP
#define FIXED_HPP

// https://www.h-schmidt.net/FloatConverter/IEEE754.html

#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int number;
	static const int fractional_bits = 8;
};

#endif
