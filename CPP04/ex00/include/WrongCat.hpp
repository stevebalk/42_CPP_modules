#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	WrongCat(const WrongCat &other);
	~WrongCat();

	WrongCat &operator=(const WrongCat &rhs);

	void makeSound(void) const;

protected:
	std::string _type;

private:
};

#endif // WRONG_CAT_HPP
