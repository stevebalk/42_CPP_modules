#include "AMateria.hpp"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

std::string const &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter &target) {
	std::cout << "An unknown materia is being used at:"
			  << target.getName() << std::endl;
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

AMateria::AMateria() :
		_type("undefined") {}

AMateria::AMateria(const std::string &type) :
		_type(type) {}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

AMateria::~AMateria() {}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

AMateria::AMateria(const AMateria &other) :
		_type(other._type) {}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

AMateria &AMateria::operator=(const AMateria &rhs) {
	if (this != &rhs) {
		*this = rhs;
	}
	return *this;
}
