#include "DiamondTrap.hpp"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

void DiamondTrap::whoAmI(void) {
	std::cout << "| DiamTrap  | "
			  << "I'm " << this->_name
			  << " and my ClapTrap name is " << this->ClapTrap::_name
			  << "." << std::endl;
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

DiamondTrap::DiamondTrap() :
		ClapTrap(),
		ScavTrap(),
		FragTrap() {
	this->_name = "Generic Diamond Trap";
	this->_health_points = FragTrap::_health_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_dmg = FragTrap::_attack_dmg;
	std::cout << "| DiamTrap  | " << _name << " constructed" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :
		ClapTrap(name + "_clap_name"),
		ScavTrap(name),
		FragTrap(name) {
	this->_name = name;
	this->_health_points = FragTrap::_health_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_dmg = FragTrap::_attack_dmg;
	std::cout << "| DiamTrap  | " << _name << " constructed" << std::endl;
}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

DiamondTrap::~DiamondTrap() {
	std::cout << "| DiamTrap  | " << this->_name << " got deleted!" << std::endl;
}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

DiamondTrap::DiamondTrap(const DiamondTrap &other) :
		ClapTrap(other),
		ScavTrap(other),
		FragTrap(other) {
	this->_name = other._name;
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->_energy_points = other._energy_points;
	this->_health_points = other._health_points;
	std::cout << "| DiamTrap  | " << _name << " Copy constructor called" << std::endl;
}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->ClapTrap::_name = rhs._name + "_clap_name";
		this->_health_points = rhs._health_points;
		this->_energy_points = rhs._energy_points;
	}
	std::cout << "| DiamTrap  | " << _name << " Copy operator called" << std::endl;
	return *this;
}
