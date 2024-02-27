#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>

class ICharacter;

class AMateria {
public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria &other);

	virtual ~AMateria();

	AMateria &operator=(const AMateria &rhs);

	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);

protected:
	std::string _type;
};

#endif // AMATERIA_HPP
