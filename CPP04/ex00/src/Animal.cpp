#include "Animal.hpp"
#include "Colors.h"

const std::string &Animal::getType() const {
	return _type;
}

Animal::Animal() :
		_type("Generic") {
	std::cout << GREEN "| Animal | default constructor called." C_RESET << std::endl;
}

Animal::~Animal() {
	std::cout << RED "| Animal | got destroyed." C_RESET << std::endl;
}

Animal::Animal(const Animal &other) :
		_type(other._type) {
	std::cout << "| Animal | copy constructor called." << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	std::cout << "| Animal | copy assignment operator called." << std::endl;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "| Animal | makes a weird noise." << std::endl;
}
