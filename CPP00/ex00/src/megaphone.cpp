#include <cstdlib>
#include <iostream>

std::string string_to_upper(std::string str) {
	int length;

	length = str.length();
	for (int i = 0; i < length; i++)
		str[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
	return (str);
}

int main(int argc, char **argv) {
	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; i < argc; i++)
			std::cout << string_to_upper(argv[i]);
		std::cout << std::endl;
	}
}
