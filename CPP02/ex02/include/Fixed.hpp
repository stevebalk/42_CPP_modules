#ifndef FIXED_HPP
#define FIXED_HPP

// https://www.h-schmidt.net/FloatConverter/IEEE754.html

#include <cmath>
#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(int const fixed_point_nb);
	Fixed(float const fixed_point_nb);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(Fixed const &a, Fixed const &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(Fixed const &a, Fixed const &b);

	bool operator<(const Fixed &other) const;
	bool operator>(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed operator+(const Fixed &other);
	Fixed operator-(const Fixed &other);
	Fixed operator*(const Fixed &other);
	Fixed operator/(const Fixed &other);

	Fixed &operator++(void); //prefix
	Fixed operator++(int); //postfix
	Fixed &operator--(void); //prefix
	Fixed operator--(int); //postfix

private:
	int fixed_point_nb;
	static const int fractional_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
