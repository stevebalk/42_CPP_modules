#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cstdio>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

class Convert {
public:
	static void convert(const std::string &str);

private:
	Convert();
	Convert(const Convert &other);
	~Convert();
	Convert &operator=(const Convert &rhs);

	enum eType {
		CHAR,
		INTEGER,
		FLOAT,
		DOUBLE,
		INVALID
	};

	static eType getType(const std::string &str);
	static void convertChar(const std::string &str);
	static void convertInt(const std::string &str);
	static void convertFloat(const std::string &str);
	static void convertDouble(const std::string &str);
	static void convertInvalid(const std::string &str);
	static void printImpossible();
	static bool isInteger(float number);
	static bool isInteger(double number);

	static int const intMax;
	static int const intMin;
	static float const floatMax;
	static float const floatMin;
	static char const charMax;
	static char const charMin;
};

#endif // CONVERT_HPP
