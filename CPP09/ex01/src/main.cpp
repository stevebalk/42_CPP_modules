#include "RPN.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: ./rpn <equation>" << std::endl;
		return 1;
	}
	RPN rpn;
	try {
		rpn.calculate(argv[1]);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
