#include "Fixed.hpp"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
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
	number = other.getRawBits();
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
