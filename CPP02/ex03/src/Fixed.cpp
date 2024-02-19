#include "Fixed.hpp"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

float Fixed::toFloat() const {
	return static_cast<float>(fixed_point_nb) / (1 << fractional_bits);
}

int Fixed::toInt() const {
	return fixed_point_nb >> fractional_bits;
}

int Fixed::getRawBits() const {
	return fixed_point_nb;
}

void Fixed::setRawBits(int const raw) {
	fixed_point_nb = raw;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b) {
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b) {
	return (a > b ? a : b);
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

Fixed::Fixed() :
		fixed_point_nb(0) {
}

Fixed::Fixed(const int number) {
	this->fixed_point_nb = number << fractional_bits;
}

Fixed::Fixed(const float number) {
	this->fixed_point_nb = static_cast<int>(roundf(number * (1 << fractional_bits)));
}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

Fixed::~Fixed() {
}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		fixed_point_nb = other.getRawBits();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return out;
}

bool Fixed::operator<(const Fixed &other) const {
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>(const Fixed &other) const {
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const {
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const {
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const {
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const {
	return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++(void) {
	++(this->fixed_point_nb);
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed &Fixed::operator--(void) {
	--(this->fixed_point_nb);
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	--(*this);
	return temp;
}
