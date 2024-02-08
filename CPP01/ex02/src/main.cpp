#include <iostream>
#include <string>

int main() {
	std::string ibrain = "HI THIS IS BRAIN";
	std::string *stringPTR = &ibrain;
	std::string &stringREF = ibrain;

	std::cout << &ibrain << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << ibrain << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}
