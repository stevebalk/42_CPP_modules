#include <iostream>
#include <string>

#ifndef ZOMBIE_H
#define ZOMBIE_H

class Zombie {
public:
	void announce(void);
	void setName(std::string name);

	Zombie();
	~Zombie(void);

private:
	std::string _name;
};
Zombie *zombieHorde(int N, std::string name);

#endif
