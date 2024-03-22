#include "Animal.hpp"
#include "Cat.hpp"
#include "Colors.h"
#include "Dog.hpp"

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

int main() {
	{
		printHeader("Animal constructors", BLUE);
		Animal *jade = new Cat();
		Animal *rex = new Dog();
		std::cout << std::endl;
		printHeader("Animal deconstructors", BLUE);
		delete(jade);
		delete(rex);
		std::cout << std::endl;
	}
	{
		printHeader("Cat/Dog constructors", BLUE);
		Cat *ruby = new Cat();
		Dog *bobo = new Dog();
		std::cout << std::endl;
		printHeader("Cat/Dog deconstructors", BLUE);
		delete(ruby);
		delete(bobo);
		std::cout << std::endl;
	}
	{
		printHeader("Copy constructors", BLUE);
		Cat original_cat;
		Dog original_dog;
		original_cat.getBrain()->setIdea("I should sleep", 0);
		std::cout << std::endl;
		Cat copy_cat = original_cat;
		Dog copy_dog = original_dog;
		std::cout << std::endl;
		std::cout << "Original cat idea: " << original_cat.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copycat idea:      " << copy_cat.getBrain()->getIdea(0) << std::endl;
		original_cat.getBrain()->setIdea("FISH FISH FISH!", 0);
		std::cout << "Original cat idea: " << original_cat.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copycat idea:      " << copy_cat.getBrain()->getIdea(0) << std::endl;
		std::cout << std::endl;
	}
	{
		printHeader("Copy assignment operator", BLUE);
		Dog dog1;
		Dog dog2;
		dog1.getBrain()->setIdea("I want food", 0);
		std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
		dog2 = dog1;
		std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;
	}
	{
		printHeader("Animal array", BLUE);
		const size_t array_size = 3 * 2;
		Animal *animals[array_size];
		for (size_t i = 0; i < array_size / 2; i++) {
			animals[i] = new Dog();
			animals[i + array_size / 2] = new Cat();
		}
		std::cout << std::endl;
		for (size_t i = 0; i < array_size; i++) {
			animals[i]->makeSound();
		}
		std::cout << std::endl;
		for (size_t i = 0; i < array_size; i++) {
			delete(animals[i]);
		}
		std::cout << std::endl;
	}
	return 0;
}
