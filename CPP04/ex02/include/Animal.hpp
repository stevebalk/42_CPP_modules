#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
public:
	virtual ~Animal();

	virtual void makeSound(void) const;
	const std::string &getType(void) const;

protected:
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &rhs);
	std::string _type;
};

#endif // ANIMAL_HPP
