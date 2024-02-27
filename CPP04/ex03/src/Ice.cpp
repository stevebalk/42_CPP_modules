#include "Ice.hpp"

Ice::Ice() :
		AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice &other) :
		AMateria(other._type) {}

Ice Ice::operator=(const Ice &rhs) {
	if (this != &rhs) {
		_type = rhs._type;
	}
	return *this;
}

AMateria *Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter &target) {
	std::cout << "* shots an ice bolt at " << target.getName()
			  << " *" << std::endl;
}
