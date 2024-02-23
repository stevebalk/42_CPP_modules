#include "Brain.hpp"
#include "Colors.h"
#include <string>

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

const std::string &Brain::getIdea(size_t index) const {
	if (index > 99) {
		return ideas[99];
	}
	return ideas[index];
}

void Brain::setIdea(const std::string &idea, size_t index) {
	if (index > 99) {
		ideas[99] = idea;
	} else {
		ideas[index] = idea;
	}
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

Brain::Brain() {
	for (int i = 0; i < 100; i++) {
		ideas[i] = "Random idea";
	}
	std::cout << GREEN "| Brain  | default constructor called." C_RESET << std::endl;
}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

Brain::~Brain() {
	std::cout << RED "| Brain  | got destroyed" C_RESET << std::endl;
}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

Brain::Brain(const Brain &other) {
	for (int i = 0; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}
	std::cout << BRIGHT_BLUE "| Brain  | Copy constructor called." C_RESET << std::endl;
}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

Brain &Brain::operator=(const Brain &rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 100; i++) {
			ideas[i] = rhs.ideas[i];
		}
	}
	std::cout << "| Brain  | Copy assigment operator called." << std::endl;
	return *this;
}
