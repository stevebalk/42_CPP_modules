#include "Cat.hpp"
#include "Colors.h"

Cat::Cat() {
	_type = "Cat";
	std::cout << GREEN "| Cat    | default constructor called." C_RESET << std::endl;
}

Cat::~Cat() {
	std::cout << RED "| Cat    | got destroyed." C_RESET << std::endl;
}

Cat::Cat(const Cat &other) :
		Animal(other) {
	_type = other._type;
	std::cout << "| Cat    | copy constructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
	if (this != &rhs) {
		_type = rhs._type;
	}
	std::cout << "| Cat    | copy assignment operator called." << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "| Cat    | makes \"Meow Meow brr brr\"." << std::endl;
}
