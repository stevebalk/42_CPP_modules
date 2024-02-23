#include "Animal.hpp"
#include "Colors.h"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

void Animal::makeSound() const {
	std::cout << "| Animal | makes a weird noise." << std::endl;
}

const std::string &Animal::getType() const {
	return _type;
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

Animal::Animal() :
		_type("Generic") {
	std::cout << GREEN "| Animal | default constructor called." C_RESET << std::endl;
}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

Animal::~Animal() {
	std::cout << RED "| Animal | got destroyed." C_RESET << std::endl;
}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

Animal::Animal(const Animal &other) :
		_type(other._type) {
	std::cout << BRIGHT_BLUE "| Animal | copy constructor called." C_RESET << std::endl;
}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

Animal &Animal::operator=(const Animal &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	std::cout << "| Animal | copy assignment operator called." << std::endl;
	return *this;
}
