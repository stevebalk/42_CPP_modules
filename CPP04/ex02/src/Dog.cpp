#include "Dog.hpp"
#include "Colors.h"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

void Dog::makeSound() const {
	std::cout << "| Dog    | makes \"Woof Woof\"." << std::endl;
}

Brain *Dog::getBrain() const {
	return _brain;
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

Dog::Dog() {
	Animal::_type = "Dog";
	std::cout << GREEN "| Dog    | default constructor called." C_RESET << std::endl;
	_brain = new Brain();
}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

Dog::~Dog() {
	delete (_brain);
	std::cout << RED "| Dog    | got destroyed." C_RESET << std::endl;
}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

Dog::Dog(const Dog &other) :
		Animal(other) {
	_type = other._type;
	std::cout << BRIGHT_BLUE "| Dog    | copy constructor called." C_RESET << std::endl;
	_brain = new Brain(*other._brain);
}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

Dog &Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		_type = rhs._type;
		_brain = rhs._brain;
	}
	std::cout << "| Dog    | copy assignment operator called." << std::endl;
	return *this;
}
