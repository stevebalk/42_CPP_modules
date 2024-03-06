#include "Serializer.hpp"

int main() {
	Data *data = new Data;
	data->data_str = "This is a string";
	data->data_int = 42;
	std::cout << "Original pointer: " << data << std::endl;
	uintptr_t serialized = Serializer::serialize(data);
	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "serialized:       0x" << std::hex << serialized << std::endl;
	std::cout << "Deserialized: " << std::endl;
	std::cout << "\tString: " << deserialized->data_str << std::endl;
	std::cout << "\tInt: " << deserialized->data_int << std::endl;
	delete data;
	return 0;
}
