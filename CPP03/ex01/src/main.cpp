#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap cl4p_tp;
	ScavTrap sc4p_tp;
	ScavTrap imARealBoy("Pinocchio");

	std::cout << std::endl;
	cl4p_tp.attack("Barrel");
	std::cout << std::endl;
	sc4p_tp.attack("the air");
	std::cout << std::endl;
	sc4p_tp.takeDamage(6);
	std::cout << std::endl;
	imARealBoy.guardgate();
	std::cout << std::endl;
}
