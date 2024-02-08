#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <iostream>

class HumanB {
public:
	HumanB(const std::string &name);

	void attack() const;
	void setWeapon(Weapon &weapon);

private:
	std::string _name;
	Weapon *_weapon;
};

#endif
