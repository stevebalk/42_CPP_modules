#include <iostream>

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

class Zombie {
public:
	void announce(void);

	Zombie(std::string name);
	~Zombie(void);

private:
	std::string _name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
