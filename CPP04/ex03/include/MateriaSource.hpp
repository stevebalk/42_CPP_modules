#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);

	~MateriaSource();

	MateriaSource &operator=(const MateriaSource &rhs);

	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);

private:
	static const size_t _sources_size = 4;
	AMateria *_sources[_sources_size];

	void initializeSources(void);
};

#endif // MATERIASOURCE_HPP
