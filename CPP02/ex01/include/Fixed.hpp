#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(int const number);
	Fixed(float const number);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int number;
	static const int fractional_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
