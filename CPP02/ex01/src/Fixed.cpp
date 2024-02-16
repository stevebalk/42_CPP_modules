#include "Fixed.hpp"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

float Fixed::toFloat() const {
	return static_cast<float>(number) / (1 << fractional_bits);
}

int Fixed::toInt() const {
	return number >> fractional_bits;
}

int Fixed::getRawBits() const {
	return number;
}

void Fixed::setRawBits(int const raw) {
	number = raw;
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

Fixed::Fixed() :
		number(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number) {
	std::cout << "Int constructor called" << std::endl;
	this->number = number << fractional_bits;
}

Fixed::Fixed(const float number) {
	std::cout << "Float constructor called" << std::endl;
	this->number = static_cast<int>(roundf(number * (1 << fractional_bits)));
}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		number = other.getRawBits();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return out;
}
