#include <Array.hpp>
#include <cstdlib>
#include <iostream>
#include "PrintHeader.hpp"

#define MAX_VAL 750

int subjectTests() {

	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));

	PrintHeader::printH1("Subject tests", BLUE);

	// Fill array with random numbers
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	// Check if the copy is consistent
	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	// Boundaries check
	try {
		numbers[-2] = 0;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	try {
		numbers[MAX_VAL] = 0;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	// Overwrite array with random numbers
	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
	}
	delete[] mirror; //
	return 0;
}

void ownTests() {
	PrintHeader::printH1("Own tests", BLUE);

	// Test empty constructor
	PrintHeader::printH2("Test empty constructor", BLUE);
	Array<int> numbers1;
	std::cout << "Array: " << numbers1 << std::endl;
	std::cout << "Size: " << numbers1.size() << std::endl;
	try {
		numbers1[0] = 42;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	// Test parameterized constructor
	PrintHeader::printH2("Test parameterized constructor", BLUE);
	Array<int> numbers(5);
	for (int i = 0; i < 5; i++) {
		numbers[i] = i;
	}
	std::cout << "Array: " << numbers << std::endl;
	std::cout << "Size: " << numbers.size() << std::endl;

	// Test copy constructor
	PrintHeader::printH2("Test copy constructor", BLUE);
	Array<int> numbers2 = numbers;
	std::cout << "Original address: " << &numbers[0] << std::endl;
	std::cout << "Copy address:     " << &numbers2[0] << std::endl;
	std::cout << "Array:            " << numbers2 << std::endl;
	std::cout << "Size:             " << numbers2.size() << std::endl;

	// Test copy assignment operator
	PrintHeader::printH2("Test copy assignment operator", BLUE);
	Array<int> numbers3;
	numbers3 = numbers;
	std::cout << "Original address: " << &numbers[0] << std::endl;
	std::cout << "Copy address:     " << &numbers3[0] << std::endl;
	std::cout << "Array:            " << numbers3 << std::endl;
	std::cout << "Size:             " << numbers3.size() << std::endl;

	// Test string array
	PrintHeader::printH2("Test string array", BLUE);
	Array<std::string> strings(3);
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "!";
	std::cout << "Array: " << strings << std::endl;
	std::cout << "Size: " << strings.size() << std::endl;

	// Test out of range
	PrintHeader::printH2("Test out of range", BLUE);
	try {
		numbers[5] = 42;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	try {
		numbers[-1] = 42;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
}

int main(int, char **) {
	if (subjectTests() == 0)
		std::cout << "Subject tests passed." << std::endl;
	else
		std::cerr << "Subject tests failed." << std::endl;
	ownTests();
}
