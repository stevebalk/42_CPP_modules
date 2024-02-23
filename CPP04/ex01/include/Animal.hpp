#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
public:
	Animal();
	Animal(const Animal &other);
	virtual ~Animal();

	Animal &operator=(const Animal &rhs);

	virtual void makeSound(void) const;
	const std::string &getType(void) const;

protected:
	std::string _type;
};

#endif // ANIMAL_HPP
