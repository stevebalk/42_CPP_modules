#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	virtual ~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &rhs);

	void makeSound(void) const;
	const std::string &getType(void) const;

protected:
	std::string _type;

};

#endif // WRONG_ANIMAL_HPP
