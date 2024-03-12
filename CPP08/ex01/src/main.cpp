#include "PrintHeader.hpp"
#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

void printSpan(const Span &span) {
	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest  span: " << span.longestSpan() << std::endl;
}

void testsSubject() {
	PrintHeader::printH1("Subject tests", BLUE);
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void testRange() {
	PrintHeader::printH1("Range iterator tests", BLUE);
	unsigned int size = 1000000;
	unsigned int range = 10000;
	std::vector<int> vector_to_add;
	Span sp = Span(size);
	std::cout << "Span with possible size of: " << size << std::endl;

	std::srand(std::time(NULL));
	vector_to_add.reserve(range);

	// Fill vector_to_add with N=range random numbers
	for (size_t i = 0; i < range; i++) {
		vector_to_add.push_back(std::rand());
	}

	// Fill span object with range values
	try {
		for (size_t i = 0; i < size / range; i++) {
			sp.addRange(vector_to_add.begin(), vector_to_add.end());
		}
	} catch (const std::exception &e) {
		std::cout << "Could not add range: " << e.what() << std::endl;
	}

	printSpan(sp);

	// Try to fill span object with more values that it could fit

	PrintHeader::printH2("Exceed span size", BLUE);
	try {
		sp.addRange(vector_to_add.begin(), vector_to_add.end());
	} catch (const std::exception &e) {
		std::cout << "Could not add range: " << e.what() << std::endl;
	}
}

void testBasic() {
	PrintHeader::printH1("Basic tests", BLUE);
	Span sp(5);

	sp.addNumber(-100);
	sp.addNumber(-101);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	printSpan(sp);

	try {
		sp.addNumber(11);
	} catch (const std::exception &e) {
		std::cout << "Could not add number: " << e.what() << std::endl;
	}
}

void testNotEnough() {
	PrintHeader::printH1("Not enough values tests", BLUE);
	// Span no_sp; // Should not compile
	Span sp_empty(0);
	Span sp_one_value(1);

	PrintHeader::printH2("Empty span", BLUE);
	sp_one_value.addNumber(1);
	try {
		sp_empty.addNumber(1);
	} catch (const std::exception &e) {
		std::cout << "Couldn't add number: " << e.what() << std::endl;
	}

	try {
		sp_empty.shortestSpan();
	} catch (const std::exception &e) {
		std::cout << "Couldn't get shortest span: " << e.what() << std::endl;
	}

	try {
		sp_empty.longestSpan();
	} catch (const std::exception &e) {
		std::cout << "Couldn't get longest span: " << e.what() << std::endl;
	}

	try {
		sp_empty[0];
	} catch (const std::exception &e) {
		std::cout << "Couldn't get element: " << e.what() << std::endl;
	}

	PrintHeader::printH2("One value span", BLUE);
	try {
		sp_one_value.shortestSpan();
	} catch (const std::exception &e) {
		std::cout << "Couldn't get longest span: " << e.what() << std::endl;
	}

	try {
		sp_one_value.longestSpan();
	} catch (const std::exception &e) {
		std::cout << "Couldn't get longest span: " << e.what() << std::endl;
	}
}

int main() {
	testsSubject();
	testBasic();
	testNotEnough();
	testRange();

	return 0;
}
