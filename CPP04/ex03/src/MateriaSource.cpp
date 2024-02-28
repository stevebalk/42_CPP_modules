#include "MateriaSource.hpp"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

void MateriaSource::learnMateria(AMateria *m) {
	for (size_t i = 0; i < _sources_size; i++) {
		if (_sources[i] == NULL) {
			std::cout << "Learned " << m->getType() << "." << std::endl;
			_sources[i] = m->clone();
			delete (m);
			return;
		}
	}
	delete (m);
	std::cout << "Couldn't learn materia because materia source is full"
			  << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (size_t i = 0; i < _sources_size; i++) {
		if (_sources[i] && _sources[i]->getType() == type) {
			return _sources[i]->clone();
		}
	}
	return NULL;
}

void MateriaSource::initializeSources() {
	for (size_t i = 0; i < _sources_size; i++) {
		_sources[i] = NULL;
	}
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

MateriaSource::MateriaSource() {
	initializeSources();
}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

MateriaSource::~MateriaSource() {
	for (size_t i = 0; i < _sources_size; i++) {
		if (_sources[i]) {
			delete (_sources[i]);
		}
	}
}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

MateriaSource::MateriaSource(const MateriaSource &other) {
	for (size_t i = 0; i < _sources_size; i++) {
		if (other._sources[i]) {
			_sources[i] = other._sources[i]->clone();
		} else {
			_sources[i] = NULL;
		}
	}
}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
	if (this != &rhs) {
		for (size_t i = 0; i < _sources_size; i++) {
			if (_sources[i]) {
				delete (_sources[i]);
			}
			if (rhs._sources[i]) {
				_sources[i] = rhs._sources[i]->clone();
			} else {
				_sources[i] = NULL;
			}
		}
	}
	return *this;
}
