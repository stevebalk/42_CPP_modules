#ifndef PRINTHEADER_HPP
#define PRINTHEADER_HPP

#include <iostream>
#include <iomanip>
#include "Colors.h"

class PrintHeader {
public:
	static void printH1(const std::string text, const char* color);
	static void printH2(const std::string text, const char* color);
	static void printH3(const std::string text, const char* color);

private:
	PrintHeader();
	PrintHeader(const PrintHeader &other);
	~PrintHeader();
	PrintHeader &operator=(const PrintHeader &rhs);
};

#endif // PRINTHEADER_HPP
