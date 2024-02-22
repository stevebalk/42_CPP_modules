#include "WrongCat.hpp"
#include "Colors.h"

WrongCat::WrongCat() :
		_type("WrongCat") {
	std::cout << GREEN "| WrongCat    | default constructor called." C_RESET << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << RED "| WrongCat    | got destroyed." C_RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	_type = other._type;
	std::cout << "| WrongCat    | copy constructor called." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
	if (this != &rhs) {
		_type = rhs._type;
	}
	std::cout << "| WrongCat    | copy assignment operator called." << std::endl;
	return *this;
}

void WrongCat::makeSound() const{
	std::cout << "| WrongCat    | makes \"Meow Meow brr brr\"." << std::endl;
}
