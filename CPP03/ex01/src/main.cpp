#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap ct("ClapO");
	ScavTrap st("ScvaO");

	// ClapTrap
	std::cout << std::endl;
	{
		ct.attack("Barrel");
		ct.beRepaired(2);
		ct.takeDamage(5);
	}

	std::cout << std::endl;

	// ScavTrap
	{
		st.attack("the air");
		st.beRepaired(20);
		st.takeDamage(80);
		st.guardgate();
		st.takeDamage(40);
		st.attack("whatever");
	}

	std::cout << std::endl;

}
