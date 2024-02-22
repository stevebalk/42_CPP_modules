#include "Animal.hpp"
#include "Cat.hpp"
#include "Colors.h"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void printHeader(const std::string &string, const std::string &color) {
	size_t offset_end = (78 - string.length()) / 2;
	size_t offset_start = offset_end + string.length() % 2;

	std::cout << color;
	for (size_t i = 0; i < 80; i++) {
		std::cout << "*";
	}
	std::cout << std::endl;
	std::cout << "*";
	for (size_t i = 0; i < offset_start; i++) {
		std::cout << " ";
	}
	std::cout << string;
	for (size_t i = 0; i < offset_end; i++) {
		std::cout << " ";
	}
	std::cout << "*" << std::endl;
	for (size_t i = 0; i < 80; i++) {
		std::cout << "*";
	}
	std::cout << std::endl;
	std::cout << C_RESET;
}

void wrongAnimalClassTests() {
	printHeader("Wrong Animal tests", BLUE);
	{
		std::cout << BOLD "WrongAnimal" C_RESET << std::endl;
		const WrongAnimal *animal = new WrongAnimal();
		std::cout << "| WrongCat    | type: " << animal->getType() << std::endl;
		animal->makeSound();
		delete animal;
		std::cout << std::endl;
	}
	{
		std::cout << BOLD "WrongCat by WrongCat class" C_RESET << std::endl;
		const WrongCat *cat = new WrongCat();
		std::cout << "| WrongCat    | type: " << cat->getType() << std::endl;
		cat->makeSound();
		delete cat;
		std::cout << std::endl;
	}
	{
		std::cout << BOLD "WrongCat by WrongAnimal parent class" C_RESET << std::endl;
		const WrongAnimal *cat = new WrongCat();
		std::cout << "| WrongCat    | type: " << cat->getType() << std::endl;
		cat->makeSound();
		delete cat;
		std::cout << std::endl;
	}
}

void correctAnimalClassTests() {
	printHeader("Correct Animal tests", BLUE);
	{
		std::cout << BOLD "Animal" C_RESET << std::endl;
		const Animal *animal = new Animal();
		std::cout << "| Animal | type: " << animal->getType() << std::endl;
		animal->makeSound();
		delete animal;
		std::cout << std::endl;
	}
	{
		std::cout << BOLD "Cat by cat class" C_RESET << std::endl;
		const Cat *cat = new Cat();
		std::cout << "| Cat    | type: " << cat->getType() << std::endl;
		cat->makeSound();
		delete cat;
		std::cout << std::endl;
	}
	{
		std::cout << BOLD "Cat by animal parent class" C_RESET << std::endl;
		const Animal *cat = new Cat();
		std::cout << "| Animal | type: " << cat->getType() << std::endl;
		cat->makeSound();
		delete cat;
		std::cout << std::endl;
	}
	{
		std::cout << BOLD "Dog by dog class" C_RESET << std::endl;
		const Dog *dog = new Dog();
		std::cout << "| Dog    | type: " << dog->getType() << std::endl;
		dog->makeSound();
		delete dog;
		std::cout << std::endl;
	}
	{
		std::cout << BOLD "Dog by animal parent class" C_RESET << std::endl;
		const Animal *dog = new Dog();
		std::cout << "| Animal | type: " << dog->getType() << std::endl;
		dog->makeSound();
		delete dog;
		std::cout << std::endl;
	}
}

void subjectTests(void) {
	printHeader("Subject tests", BLUE);
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete j;
	delete i;
	delete meta;
	std::cout << std::endl;
}

int main() {
	wrongAnimalClassTests();
	correctAnimalClassTests();
	subjectTests();

	return 0;
}
