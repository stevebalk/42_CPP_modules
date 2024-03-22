#include "Cat.hpp"
#include "Colors.h"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

void Cat::makeSound() const {
	std::cout << "| Cat    | makes \"Meow Meow brr brr\"." << std::endl;
}

Brain *Cat::getBrain() const {
	return _brain;
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

Cat::Cat() {
	Animal::_type = "Cat";
	std::cout << GREEN "| Cat    | default constructor called." C_RESET << std::endl;
	_brain = new Brain();
}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

Cat::~Cat() {
	delete (_brain);
	std::cout << RED "| Cat    | got destroyed." C_RESET << std::endl;
}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

Cat::Cat(const Cat &other) :
		Animal(other) {
	_type = other._type;
	std::cout << BRIGHT_BLUE "| Cat    | copy constructor called." C_RESET << std::endl;
	_brain = new Brain(*other._brain);
}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

Cat &Cat::operator=(const Cat &rhs) {
	if (this != &rhs) {
		delete (_brain);
		_type = rhs._type;
		_brain = new Brain(*rhs._brain);
	}
	std::cout << "| Cat    | copy assignment operator called." << std::endl;
	return *this;
}
