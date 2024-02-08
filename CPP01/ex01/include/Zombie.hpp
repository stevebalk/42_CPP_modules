#include <iostream>
#include <string>

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

class Zombie {
	public:
		void announce(void);
		void setName(std::string name);

	Zombie();
	~Zombie(void);

	private:
		std::string _name;
};
Zombie* zombieHorde(int N, std::string name);

#endif
