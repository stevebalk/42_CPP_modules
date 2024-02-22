#include "Dog.hpp"
#include "Colors.h"

Dog::Dog() {
	Animal::_type = "Dog";
	std::cout << GREEN "| Dog    | default constructor called." C_RESET << std::endl;;
}

Dog::~Dog() {
	std::cout << RED "| Dog    | got destroyed." C_RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	_type = other._type;
	std::cout << "| Dog    | copy constructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		_type = rhs._type;
	}
	std::cout << "| Dog    | copy assignment operator called." << std::endl;
	return *this;
}

void Dog::makeSound() const{
	std::cout << "| Dog    | makes \"Woof Woof\"." << std::endl;
}
