#ifndef PRINTHEADER_HPP
#define PRINTHEADER_HPP

#include "Colors.h"
#include <iomanip>
#include <iostream>

class PrintHeader {
public:
	static void printH1(const std::string text, const char *color = BLUE);
	static void printH2(const std::string text, const char *color = BLUE);
	static void printH3(const std::string text, const char *color = BLUE);

private:
	PrintHeader();
	PrintHeader(const PrintHeader &other);
	~PrintHeader();
	PrintHeader &operator=(const PrintHeader &rhs);
};

#endif // PRINTHEADER_HPP
