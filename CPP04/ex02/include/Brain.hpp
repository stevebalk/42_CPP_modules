#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
public:
	Brain();
	~Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &rhs);

	const std::string &getIdea(size_t index) const;
	void setIdea(const std::string &idea, size_t index);

private:
	std::string ideas[100];
};

#endif // BRAIN_HPP
