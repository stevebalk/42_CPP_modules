#include "Zombie.hpp"

Zombie::Zombie() {}

void Zombie::announce() {
	std::cout << _name << ": "
			  << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << _name << " is dead" << std::endl;
}

void Zombie::setName(std::string name) {
	_name = name;
}
