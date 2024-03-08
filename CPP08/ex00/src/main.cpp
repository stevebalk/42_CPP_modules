#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main() {
	std::vector<int> numbers;
	std::vector<int>::iterator it;

	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);

	it = easyfind(numbers, 3);
	if (it != numbers.end())
		std::cout << "Found: " << *it << std::endl;
	else
		std::cout << "Not found" << std::endl;

	it = easyfind(numbers, 42);
	if (it != numbers.end())
		std::cout << "Found: " << *it << std::endl;
	else
		std::cout << "Not found" << std::endl;
	return 0;
}
