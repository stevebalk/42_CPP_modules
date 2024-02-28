#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
public:
	Character();
	Character(const std::string &name);
	Character(const Character &other);

	~Character();

	Character &operator=(const Character &rhs);

	std::string const &getName() const;
	void setName(const std::string &name);
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
	void lookAtFloor(void);
	void clearFloor(void);

private:
	static const size_t _inventory_size = 4;
	static const size_t _floor_size = 100;

	std::string _name;
	AMateria *_inventory[_inventory_size];
	static AMateria *_floor[_floor_size];

	void InitalizeEmptyInventory();
	void deleteInventory();
	void moveItemtoFloor(AMateria *materia);
};

#endif // CHARACTER_HPP
