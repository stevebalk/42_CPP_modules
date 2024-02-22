#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat &other);
	~Cat();

	Cat &operator=(const Cat &rhs);

	void makeSound(void) const;

};

#endif // CAT_HPP
