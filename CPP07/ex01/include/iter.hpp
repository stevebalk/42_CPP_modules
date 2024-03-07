#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename A, typename F>
void iter(A array[], size_t arr_length, F function) {
	for (size_t i = 0; i < arr_length; i++) {
		function(array[i]);
	}
}

template <typename T>
void printArray(T array[], size_t length) {
	std::cout << "[";
	for (size_t i = 0; i < length; i++) {
		std::cout << array[i];
		if (i < length - 1) {
			std::cout << ", ";
		}
	}
	std::cout << "]" << std::endl;
}

#endif // ITER_HPP
