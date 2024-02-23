#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria {
protected:
	AMateria();
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &rhs);

public:
	virtual ~AMateria();
	AMateria(std::string const & type);
	
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif