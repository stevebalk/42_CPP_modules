#include "WrongAnimal.hpp"
#include "Colors.h"

const std::string &WrongAnimal::getType() const {
	return _type;
}

WrongAnimal::WrongAnimal() :
		_type("Generic") {
	std::cout << GREEN "| WrongAnimal | default constructor called." C_RESET << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED "| WrongAnimal | got destroyed." C_RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) :
		_type(other._type) {
	std::cout << "| WrongAnimal | copy constructor called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	std::cout << "| WrongAnimal | copy assignment operator called." << std::endl;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "| WrongAnimal | makes a weird noise." << std::endl;
}
