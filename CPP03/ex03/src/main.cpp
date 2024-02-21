#include "DiamondTrap.hpp"

int main() {
	// ClapTrap
	std::cout << std::endl;
	{
		ClapTrap ct("ClapO");
		std::cout << std::endl;
		ct.attack("Barrel");
		ct.beRepaired(2);
		ct.takeDamage(5);
		std::cout << std::endl;
	}

	std::cout << std::endl;

	// ScavTrap
	{
		ScavTrap st("ScvaO");
		std::cout << std::endl;
		st.attack("the air");
		st.beRepaired(20);
		st.takeDamage(40);
		st.guardgate();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// FragTrap
	{
		FragTrap ft("FragO");
		std::cout << std::endl;
		ft.attack("a bad guy");
		ft.beRepaired(4);
		ft.takeDamage(80);
		ft.highFiveGuys();
		ft.takeDamage(80);
		ft.highFiveGuys();
		std::cout << std::endl;
	}

	std::cout << std::endl;

	//DiamondTrap
	{
		DiamondTrap dt("DiamO");
		std::cout << std::endl;
		dt.attack("an angry bear");
		dt.takeDamage(40);
		dt.whoAmI();
		dt.beRepaired(20);
		dt.guardgate();
		std::cout << std::endl;
	}
}
