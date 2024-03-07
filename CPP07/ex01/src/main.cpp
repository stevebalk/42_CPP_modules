#include "iter.hpp"
#include <string>

void incrementInt(int &num) {
	num++;
}

void incrementFloat(float &num) {
	num++;
}

void toUpper(std::string &str) {
	int length;

	length = str.length();
	for (int i = 0; i < length; i++)
		str[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
}


void changeEveryCharToZ(char &ch) {
	ch = 'z';
}

void charTest() {
	char char_arr[4] = {'a', 'b', 'c', 'd'};
	std::cout << "Before: ";
	::printArray(char_arr, 4);
	::iter<char>(char_arr, 4, ::changeEveryCharToZ);
	std::cout << "After:  ";
	::printArray(char_arr, 4);
	std::cout << "\n--------------------------\n";
}

void intTest() {
	int int_arr[6] = {0, 1, 2, 3, 4, 5};
	std::cout << "Before: ";
	printArray(int_arr, 6);
	::iter<int>(int_arr, 6, ::incrementInt);
	std::cout << "After:  ";
	printArray(int_arr, 6);
	std::cout << "\n--------------------------\n";
}

void floatTest() {
	float float_arr[6] = {0.1f, 1.1f, 2.1f, 3.1f, 4.1f, 5.1f};
	std::cout << "Before: ";
	::printArray(float_arr, 6);
	::iter<float>(float_arr, 6, ::incrementFloat);
	std::cout << "After:  ";
	::printArray(float_arr, 6);
	std::cout << "\n--------------------------\n";
}

void stringTest() {
	std::string string_arr[3] = {"Hello World", "42 Wolfsburg", "Give me a job please!"};
	std::cout << "Before: ";
	::printArray(string_arr, 3);
	::iter<std::string>(string_arr, 3, ::toUpper);
	std::cout << "After:  ";
	::printArray(string_arr, 3);
	std::cout << "\n--------------------------\n";
}

int main(void) {
	charTest();
	intTest();
	floatTest();
	stringTest();
}
