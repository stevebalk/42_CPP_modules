#include "ScavTrap.hpp"

ScavTrap::ScavTrap() :
		ClapTrap("SC4V-TP") {
	this->_health_points = 100;
	this->_energy_points = 50;
	this->_attack_dmg = 20;

	std::cout << "I'm a scavtrap!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) :
		ClapTrap(name) {
	this->_health_points = 100;
	this->_energy_points = 50;
	this->_attack_dmg = 20;

	std::cout << "I'm a scavtrap!" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	std::cout << "ScavTrap " << _name << " attacks " << target
			  << " causing " << _attack_dmg << " of damage!" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " got deleted!" << std::endl;
}

void ScavTrap::guardgate() {
	std::cout << "ScavTrap: " << _name << " is now in gatekeeper mode!" << std::endl;
}
