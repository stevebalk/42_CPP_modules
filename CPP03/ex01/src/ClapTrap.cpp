#include "ClapTrap.hpp"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

void ClapTrap::attack(const std::string &target) {
	if (_energy_points > 0 && _health_points > 0) {
		std::cout << "Claptrap " << _name << " attacks " << target
				  << ", causing " << _attack_dmg << " points of damage!"
				  << std::endl;
		_energy_points--;
	} else if (_health_points <= 0) {
		std::cout << "ClapTrap " << _name << " doesn't clap anymore T_T"
				  << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " could not attack " << target
				  << " because it's out of energy!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_health_points > 0) {
		_health_points -= amount;
		std::cout << "ClapTrap " << _name << " got hit for " << amount << "! Current hitpoints: "
				  << _health_points << std::endl;
		if (_health_points <= 0) {
			std::cout << "ClapTrap " << _name << " got deadly wounded! Oh no!" << std::endl;
		}
	} else {
		std::cout << "ClapTrap " << _name << "s lifeless body got hit again and again." << std::endl;
		std::cout << "Does it feel good to smack this poor little guy over and over you monster?";
		std::cout << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energy_points > 0 && _health_points > 0) {
		std::cout << "Claptrap " << _name << " repairs himself for " << amount
				  << " healthpoints! Current hitpoints: " << _health_points << std::endl;
		_energy_points--;
		_health_points += amount;
	} else if (_health_points <= 0) {
		std::cout << "ClapTrap " << _name << " doesn't clap anymore T_T"
				  << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " could not repair, because it's out of energy!"
				  << std::endl;
	}
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

ClapTrap::ClapTrap() :
		_name("CL4P-TP"),
		_health_points(10),
		_energy_points(10),
		_attack_dmg(0) {
	std::cout << _name << " says: Hello World! I'm the original!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
		_name(name),
		_health_points(10),
		_energy_points(10),
		_attack_dmg(0) {
	std::cout << _name << " says: Hello World!" << std::endl;
}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

ClapTrap::~ClapTrap() {
	std::cout << _name << " says: Bye cruel world!" << std::endl;
}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

ClapTrap::ClapTrap(const ClapTrap &other) :
		_name(other._name),
		_health_points(other._health_points),
		_energy_points(other._energy_points),
		_attack_dmg(other._attack_dmg) {
}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		_name = other._name;
		_health_points = other._health_points;
		_energy_points = other._energy_points;
		_attack_dmg = other._attack_dmg;
	}
	return *this;
}
