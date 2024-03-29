#include "Character.hpp"

AMateria *Character::_floor[_floor_size] = { NULL };

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

const std::string &Character::getName() const {
	return _name;
}

void Character::setName(const std::string &name) {
	std::cout << "Renamed \"" << getName() << "\" to \"" << name
			  << "\"" << std::endl;
	_name = name;
}

void Character::InitalizeEmptyInventory() {
	for (size_t i = 0; i < _inventory_size; i++) {
		_inventory[i] = NULL;
	}
}

void Character::deleteInventory() {
	for (size_t i = 0; i < _inventory_size; i++) {
		if (_inventory[i] != NULL) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < static_cast<int>(_inventory_size)) {
		if (_inventory[idx]) {
			std::cout << getName() << ": ";
			_inventory[idx]->use(target);
		} else {
			std::cout << getName() << ": Wants to use inventory slot: " << idx
					  << ", but it's empty." << std::endl;
		}
	} else {
		std::cout << getName() << ": "
				  << "Could not use materia at inventory slot: " << idx
				  << " because it's index is out of bounds" << std::endl
				  << "Must be between 0 and "
				  << (_inventory_size - 1) << "." << std::endl;
	}
}

void Character::equip(AMateria *m) {
	size_t i = 0;

	if (m == NULL) {
		std::cout << getName() << ": "
				  << "Could not equip object. Unknown reference!" << std::endl;
		return;
	}
	while (i < _inventory_size) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			std::cout << getName() << ": "
					  << "Added " << m->getType() << " Materia"
					  << " into inventory slot " << i << std::endl;
			return;
		}
		i++;
	}
	std::cout << getName() << ": "
			  << "Inventory is full, could not add " << m->getType()
			  << " Materia." << std::endl;
	moveItemtoFloor(m);
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < static_cast<int>(_inventory_size)) {
		if (_inventory[idx]) {
			std::cout << getName() << ": ";
			moveItemtoFloor(_inventory[idx]);
			_inventory[idx] = NULL;
		} else {
			std::cout << "No materia at index: " << idx << std::endl;
		}
	} else {
		std::cout << getName() << ": "
				  << "Wrong inventory index. Must be between 0 and "
				  << (_inventory_size - 1) << "." << std::endl;
	}
}

void Character::moveItemtoFloor(AMateria *materia) {
	size_t i = 0;

	if (materia) {
		while (i < _floor_size) {
			if (_floor[i] == NULL) {
				_floor[i] = materia;
				std::cout << "Droped " << _floor[i]->getType()
						  << " Materia on the ground" << std::endl;
				return;
			}
			i++;
		}
		delete (materia);
		std::cout << "Couldn't drop " << materia->getType()
				  << " Materia, because the floor couldn't hold more."
				  << std::endl
				  << "The Materia vanishes into eternity"
				  << std::endl;
	}
}

void Character::lookAtFloor() {
	bool was_something_on_floor = false;

	std::cout << getName() << ": looks at the ground and sees: " << std::endl;
	for (size_t i = 0; i < _floor_size; i++) {
		if (_floor[i]) {
			std::cout << "A " << _floor[i]->getType()
					  << " materia." << std::endl;
			was_something_on_floor = true;
		}
	}
	if (!was_something_on_floor) {
		std::cout << "Nothing." << std::endl;
	}
}

void Character::clearFloor() {
	for (size_t i = 0; i < _floor_size; i++) {
		if (_floor[i]) {
			delete (_floor[i]);
			_floor[i] = NULL;
		}
	}
	std::cout << getName() << ": cleared the floor and threw every materia away"
			  << std::endl;
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

Character::Character() :
		_name("Noname") {
	InitalizeEmptyInventory();
}

Character::Character(const std::string &name) :
		_name(name) {
	InitalizeEmptyInventory();
}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

Character::~Character() {
	deleteInventory();
}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

Character::Character(const Character &other) :
		_name(other._name) {
	std::cout << "Copy Constructor called" << std::endl;
	for (size_t i = 0; i < _inventory_size; i++) {
		if (other._inventory[i]) {
			_inventory[i] = other._inventory[i]->clone();
		} else {
			_inventory[i] = NULL;
		}
	}
}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

Character &Character::operator=(const Character &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		for (size_t i = 0; i < _inventory_size; i++) {
			delete (_inventory[i]);
			if (rhs._inventory[i]) {
				_inventory[i] = rhs._inventory[i]->clone();
			} else {
				_inventory[i] = NULL;
			}
		}
		_name = rhs._name;
	}
	return *this;
}
