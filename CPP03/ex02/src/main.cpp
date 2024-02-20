#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ClapTrap ct("ClapO");
	ScavTrap st("ScvaO");
	FragTrap ft("FragO");

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
		st.takeDamage(40);
		st.guardgate();
	}

	std::cout << std::endl;

	// FragTrap
	{
		ft.attack("a bad guy");
		ft.beRepaired(4);
		ft.takeDamage(80);
		ft.highFiveGuys();
		ft.takeDamage(80);
		ft.highFiveGuys();
	}

	std::cout << std::endl;
}
