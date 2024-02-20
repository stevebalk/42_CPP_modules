#include "FragTrap.hpp"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

void FragTrap::highFiveGuys() {
	if (_energy_points > 0 && _health_points > 0) {
		std::cout << "| FragTrap  | " << _name << " >"
				  << " gives everybody a high five!" << std::endl;
		_energy_points--;
	} else if (_health_points <= 0) {
		std::cout << "| FragTrap  | "
				  << _name << " > " << " couldn't give a highfive because he's dead T_T"
				  << std::endl;
	} else {
		std::cout << "| FragTrap  | " << _name << " > " << " couldn't give a highfive "
				  << " because it's out of energy!" << std::endl;
	}
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

FragTrap::FragTrap() :
		ClapTrap("FR4G-TP") {
	this->_health_points = 100;
	this->_energy_points = 100;
	this->_attack_dmg = 30;

	std::cout << "| FragTrap  | " << _name << " > " << " constructed" << std::endl;
}

FragTrap::FragTrap(std::string name) :
		ClapTrap(name) {
	this->_health_points = 100;
	this->_energy_points = 100;
	this->_attack_dmg = 30;

	std::cout << "| FragTrap  | " << _name << " > " << " constructed" << std::endl;
}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

FragTrap::~FragTrap() {
	std::cout << "| FragTrap  | " << _name << " > " << " got deleted!" << std::endl;
}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/
