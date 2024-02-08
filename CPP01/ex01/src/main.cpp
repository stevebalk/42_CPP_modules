#include "Zombie.hpp"

int main(void) {
	int		nb_of_zombies;
	Zombie*	zombie_horde;

	nb_of_zombies = 5;
	zombie_horde = zombieHorde(nb_of_zombies, "test");

	for (int i = 0; i < nb_of_zombies; i++) {
		zombie_horde[i].announce();
	}
	delete[] zombie_horde;
}
