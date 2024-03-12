#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

struct Data {
	std::string data_str;
	int data_int;
};

class Serializer {
public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(const Serializer &other);
	~Serializer();
	Serializer &operator=(const Serializer &rhs);
};

#endif // SERIALIZER_HPP
