#include "AMateria.hpp"

std::string const &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter &target) {
	std::cout << "An unknown materia is being used at:"
			  << target.getName() << std::endl;
}

AMateria::AMateria() :
		_type("undefined") {}

AMateria::AMateria(const std::string &type) :
		_type(type) {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria &other) :
		_type(other._type) {}

AMateria &AMateria::operator=(const AMateria &rhs) {
	if (this != &rhs) {
		*this = rhs;
	}
	return *this;
}
