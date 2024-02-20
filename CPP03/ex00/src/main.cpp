#include "ClapTrap.hpp"

int main() {
	ClapTrap cla4p_tp;
	ClapTrap bob("Bob");
	ClapTrap dave("Dave");

	{
		for (int i = 0; i < 11; i++) {
			cla4p_tp.attack("Barrel");
		}
	}
	{
		std::cout << std::endl;
		for (int i = 0; i < 11; i++) {
			bob.beRepaired(1);
		}
		bob.attack("the air");
		std::cout << std::endl;
		for (int i = 0; i < 3; i++) {
			bob.takeDamage(10);
		}
	}
	std::cout << std::endl;
}