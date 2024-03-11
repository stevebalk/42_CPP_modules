#include "PrintHeader.hpp"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

void PrintHeader::printH1(const std::string text, const char* color) {
	const char fill_char = '*';
	const size_t width = 80;
	size_t offset_end = (width - text.length()) / 2 - 1;
	size_t offset_start = offset_end + text.length() % 2;

	std::cout << color;
	std::cout << std::endl;
	std::cout << std::setfill(fill_char) << std::setw(width) << "" << std::endl;
	std::cout << "*";
	std::cout << std::setfill(' ') << std::setw(offset_start) << std::right << "";
	std::cout << BOLD;
	std::cout << std::setw(text.length()) << std::left << text;
	std::cout << C_RESET << color;
	std::cout << std::setfill(' ') << std::setw(offset_end) << std::left << "";
	std::cout << "*";
	std::cout << std::endl;
	std::cout << std::setfill(fill_char) << std::setw(width) << "" << std::endl;
	std::cout << C_RESET;
}

void PrintHeader::printH2(const std::string text, const char* color) {
	const char fill_char = '*';
	size_t offset_end = (40 - text.length() - 2) / 2;
	size_t offset_start = offset_end + text.length() % 2;

	std::cout << color;
	std::cout << std::endl;
	std::cout << std::setfill(fill_char) << std::setw(offset_start) << std::right << "";
	std::cout << " ";
	std::cout << BOLD;
	std::cout << std::setw(text.length()) << std::left << text;
	std::cout << C_RESET << color;
	std::cout << " ";
	std::cout << std::setw(offset_end) << std::right << "" << std::endl;
	std::cout << C_RESET;
}

void PrintHeader::printH3(const std::string text, const char* color) {
	const char fill_char = '-';
	size_t offset_end = (20 - text.length() - 2) / 2;
	size_t offset_start = offset_end + text.length() % 2;

	std::cout << color;
	std::cout << std::endl;
	std::cout << std::setfill(fill_char) << std::setw(offset_start) << std::right << "";
	std::cout << " ";
	std::cout << BOLD;
	std::cout << std::setw(text.length()) << std::left << text;
	std::cout << C_RESET << color;
	std::cout << " ";
	std::cout << std::setw(offset_end) << std::right << "" << std::endl;
	std::cout << C_RESET;
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

PrintHeader::PrintHeader() {}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

PrintHeader::~PrintHeader() {}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

PrintHeader::PrintHeader(const PrintHeader &other) {
	(void)other;
}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

PrintHeader &PrintHeader::operator=(const PrintHeader &rhs) {
	(void)rhs;
	return *this;
}
