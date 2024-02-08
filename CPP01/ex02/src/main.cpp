#include <iostream>
#include <string>

int main() {
	std::string ibrain = "HI THIS IS BRAIN";
	std::string *str_pointer = &ibrain;
	std::string &str_reference = ibrain;

	std::cout << &ibrain << std::endl;
	std::cout << str_pointer << std::endl;
	std::cout << &str_reference << std::endl;

	std::cout << ibrain << std::endl;
	std::cout << *str_pointer << std::endl;
	std::cout << str_reference << std::endl;
}
