#include "Convert.hpp"
#include "PrintHeader.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		PrintHeader::printH1("Error: Invalid number of arguments", RED);
		return 1;
	}
	Convert::convert(argv[1]);
	return 0;
}
