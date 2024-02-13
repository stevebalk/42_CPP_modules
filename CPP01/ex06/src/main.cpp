#include "Harl.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		return (std::cout << "Usage: ./harlFilter <filterLevel>" << std::endl, 1);
	}
	Harl harl;
	harl.complain(argv[1]);
}
