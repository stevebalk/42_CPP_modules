#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"
#include <iostream>

class AMateria;

class ICharacter {
public:
	virtual ~ICharacter() {}
	virtual std::string const &getName() const = 0;
	virtual void equip(AMateria *m) = 0;
	virtual void unequip(size_t idx) = 0;
	virtual void use(size_t idx, ICharacter &target) = 0;

	virtual void lookAtFloor(void) = 0;
	virtual void clearFloor(void) = 0;
};

#endif // ICHARACTER_HPP
