#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "PrintHeader.hpp"

void subjectTests() {
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
	me->unequip(0);
	me->unequip(1);
	me->use(0, *bob);
	me->lookAtFloor();
	me->clearFloor();

	delete bob;
	delete me;
	delete src;

	PrintHeader::printH1("Test", BLUE);
	PrintHeader::printH1("Testi", BLUE);
	std::cout << std::endl;
	PrintHeader::printH2("Test", BLUE);
	PrintHeader::printH2("Testissss", BLUE);
	std::cout << std::endl;
	PrintHeader::printH3("Test", BLUE);

}

int main() {
	subjectTests();

	return 0;
}
