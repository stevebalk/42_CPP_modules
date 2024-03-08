#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array {
public:
	Array() {
		_array = new T();
		_size = 0;
	}

	Array(size_t size) {
		_array = new T[size];
		_size = size;
	}

	Array(const Array &other) {
		_array = new T[other._size];
		_size = other._size;
		for (size_t i = 0; i < other._size; i++) {
			_array[i] = other._array[i];
		}
	}

	~Array() {
		delete[] (_array);
	}

	Array &operator=(const Array &rhs) {
		if (this != &rhs) {
			delete[] (_array);
			_size = rhs._size;
			_array = new T[rhs._size];
			for (size_t i = 0; i < rhs._size; i++) {
				_array[i] = rhs._array[i];
			}
		}
		return *this;
	}

	T &operator[](size_t n) const {
		if (n >= _size) {
			throw std::out_of_range("Index out of range");
		}
		return _array[n];
	}

	size_t size() const {
		return _size;
	}

private:
	T *_array;
	size_t _size;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &arr) {
	os << "[";
	for (size_t i = 0; i < arr.size(); i++) {
		os << arr[i];
		if (i < arr.size() - 1) {
			os << ", ";
		}
	}
	os << "]";
	return os;
}

#endif // ARRAY_HPP
