#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "PrintHeader.hpp"

void subjectTests() {
	PrintHeader::printH1("Subject tests", BLUE);
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void BasicTests() {
	PrintHeader::printH1("Basic tests", BLUE);
	ICharacter *bob = new Character("Bob");
	ICharacter *target_dummy = new Character("Target Dummy");
	IMateriaSource *spellbook = new MateriaSource();

	PrintHeader::printH2("Learn new materias", BLUE);
	spellbook->learnMateria(new Ice());
	spellbook->learnMateria(new Cure());
	spellbook->learnMateria(new Ice());
	spellbook->learnMateria(new Cure());
	spellbook->learnMateria(new Cure());
	spellbook->learnMateria(new Cure());

	PrintHeader::printH2("Equip materias", BLUE);
	bob->equip(spellbook->createMateria("ice"));
	bob->equip(spellbook->createMateria("cure"));
	bob->equip(spellbook->createMateria("Don't exist"));
	bob->equip(spellbook->createMateria("ice"));
	bob->equip(spellbook->createMateria("cure"));
	bob->equip(spellbook->createMateria("ice"));
	bob->equip(spellbook->createMateria("cure"));

	PrintHeader::printH2("Use materias", BLUE);
	bob->use(0, *target_dummy);
	bob->use(1, *target_dummy);
	bob->use(2, *target_dummy);
	bob->use(3, *target_dummy);

	PrintHeader::printH2("Floor functions", BLUE);
	bob->lookAtFloor();
	bob->clearFloor();

	delete(bob);
	delete(target_dummy);
	delete(spellbook);
}

void copyTests() {

	PrintHeader::printH1("Copy tests", BLUE);
	Character *bob = new Character("Bob");
	IMateriaSource *spellbook = new MateriaSource();

	PrintHeader::printH2("Learn new materias", BLUE);
	spellbook->learnMateria(new Ice());
	spellbook->learnMateria(new Cure());

	PrintHeader::printH2("Bob", BLUE);
	bob->equip(spellbook->createMateria("ice"));
	bob->equip(spellbook->createMateria("cure"));
	bob->equip(spellbook->createMateria("ice"));

	PrintHeader::printH2("Copybob (Copy operator)", BLUE);
	Character *copybob = new Character(*bob);
	copybob->setName("Copybob");
	copybob->use(0, *bob);
	copybob->use(1, *bob);
	copybob->use(2, *bob);
	copybob->use(3, *bob);
	copybob->unequip(0);
	copybob->unequip(1);
	copybob->unequip(2);
	copybob->use(0, *bob);
	copybob->use(1, *bob);
	copybob->use(2, *bob);

	PrintHeader::printH2("Bob", BLUE);
	bob->use(0, *bob);
	bob->use(1, *bob);
	bob->use(2, *bob);
	bob->clearFloor();

	
	PrintHeader::printH2("Dave (Copy assignmet operator)", BLUE);
	Character *dave = new Character("Dave");
	*dave = *bob;
	dave->setName("Dave");
	bob->unequip(0);
	bob->unequip(1);
	bob->unequip(2);
	bob->clearFloor();
	dave->use(0, *bob);
	dave->use(1, *bob);
	dave->use(2, *bob);
	dave->use(3, *bob);

	delete(dave);
	delete(spellbook);
	delete(bob);
	delete(copybob);
}

void boundaryTests() {

	PrintHeader::printH2("Learn to much materias", BLUE);
	MateriaSource spellbook;
	spellbook.learnMateria(new Ice());
	spellbook.learnMateria(new Ice());
	spellbook.learnMateria(new Ice());
	spellbook.learnMateria(new Ice());
	spellbook.learnMateria(new Ice());

	PrintHeader::printH2("Equip to much materias", BLUE);
	Character bob("bob");
	bob.equip(spellbook.createMateria("ice"));
	bob.equip(spellbook.createMateria("ice"));
	bob.equip(spellbook.createMateria("ice"));
	bob.equip(spellbook.createMateria("ice"));
	bob.equip(spellbook.createMateria("ice"));
	
	PrintHeader::printH2("Use wrong inventory index", BLUE);
	bob.use(-1, bob);
	bob.use(-5656565, bob);
	bob.use(4, bob);
	bob.use(3343434, bob);

	bob.clearFloor();
}

int main() {
	subjectTests();
	BasicTests();
	copyTests();
	boundaryTests();

	return 0;
}
