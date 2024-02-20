#include "ScavTrap.hpp"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

void ScavTrap::attack(const std::string &target) {
	if (_energy_points > 0 && _health_points > 0) {
		std::cout << "| ScavTrap  | "
				  << _name << " attacks " << target
				  << " causing " << _attack_dmg << " points of damage!" << std::endl;
	} else if (_health_points <= 0) {
		std::cout << "| ScavTrap  | "
				  << _name << " couldn't attack because he's dead T_T"
				  << std::endl;
	} else {
		std::cout << "| ScavTrap  | " << _name << " couldn't attack " << target
				  << " because it's out of energy!" << std::endl;
	}
}

void ScavTrap::guardgate() {
	std::cout << "| ScavTrap  | " << _name << " is now in gatekeeper mode!" << std::endl;
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

ScavTrap::ScavTrap() :
		ClapTrap("SC4V-TP") {
	this->_health_points = 100;
	this->_energy_points = 50;
	this->_attack_dmg = 20;

	std::cout << "| ScavTrap  | " << _name << " constructed" << std::endl;
}

ScavTrap::ScavTrap(std::string name) :
		ClapTrap(name) {
	this->_health_points = 100;
	this->_energy_points = 50;
	this->_attack_dmg = 20;

	std::cout << "| ScavTrap  | " << _name << " constructed" << std::endl;
}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

ScavTrap::~ScavTrap() {
	std::cout << "| ScavTrap  | " << _name << " got deleted!" << std::endl;
}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/


/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/
