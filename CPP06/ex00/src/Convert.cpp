#include "Convert.hpp"
#include "Colors.h"

int const Convert::intMax = std::numeric_limits<int>::max();
int const Convert::intMin = std::numeric_limits<int>::min();
float const Convert::floatMax = std::numeric_limits<float>::max();
float const Convert::floatMin = std::numeric_limits<float>::min();
char const Convert::charMax = std::numeric_limits<char>::max();
char const Convert::charMin = std::numeric_limits<char>::min();

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

bool Convert::isInteger(float number) {
	return number == static_cast<int>(number);
}

bool Convert::isInteger(double number) {
	return number == static_cast<int>(number);
}

void Convert::convert(const std::string &str) {
	std::cout << "Convert: " << BOLD "" << str  << C_RESET "" << std::endl;
	eType type = getType(str);
	switch (type) {
		case CHAR:
			convertChar(str);
			break;
		case INTEGER:
			convertInt(str);
			break;
		case FLOAT:
			convertFloat(str);
			break;
		case DOUBLE:
			convertDouble(str);
			break;
		case INVALID:
			convertInvalid(str);
			break;
	}
}

void Convert::convertInvalid(const std::string &str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "nanf" || str == "nan") {
		std::cout << "float: " << std::numeric_limits<float>::quiet_NaN() << "f" << std::endl;
		std::cout << "double: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
	} else if (str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff") {
		std::cout << "float: " << std::numeric_limits<float>::infinity << "f" << std::endl;
		std::cout << "double: " << std::numeric_limits<double>::infinity << std::endl;
	} else {
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

Convert::eType Convert::getType(const std::string &str) {
	std::istringstream iss(str);

	if (str.length() == 1 && !isdigit(str[0])) {
		return CHAR;
	}
	int pre_dot;
	if (iss >> pre_dot) {
		if (iss.eof()) {
			return INTEGER;
		}
		char dot;
		if (iss >> dot && dot == '.' && iss.peek() != EOF) {
			int after_dot;
			if (iss >> after_dot) {
				if (iss.eof()) {
					return DOUBLE;
				} else {
					char f;
					iss >> f;
					if (f == 'f' && iss.peek() == EOF) {
						return FLOAT;
					}
				}
			}
		}
	}
	return INVALID;
}

void Convert::convertChar(const std::string &str) {
	std::istringstream iss(str);
	char c;

	if (iss >> c) {
		std::cout << "char: ";
		if (isprint(c)) {
			std::cout << "'" << c << "'" << std::endl;
		} else {
			std::cout << "Non displayable" << std::endl;
		}
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	} else {
		printImpossible();
	}
}

void Convert::convertInt(const std::string &str) {
	std::istringstream iss(str);
	int i;

	if (iss >> i) {
		std::cout << "char: ";
		if (i >= charMin && i <= charMax) {
			if (isprint(i)) {
				std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
			} else {
				std::cout << "Non displayable" << std::endl;
			}
		} else {
			std::cout << "impossible" << std::endl;
		}
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
	} else {
		printImpossible();
	}
}

void Convert::convertFloat(const std::string &str) {
	std::istringstream iss(str);
	float f;

	if (iss >> f) {
		std::cout << "char: ";
		if (f >= charMin && f <= charMax) {
			if (isprint(f)) {
				std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
			} else {
				std::cout << "Non displayable" << std::endl;
			}
		} else {
			std::cout << "impossible" << std::endl;
		}
		std::cout << "int: ";
		if (f >= intMin && f <= intMax) {
			std::cout << static_cast<int>(f) << std::endl;
		} else {
			std::cout << "impossible" << std::endl;
		}
		if (isInteger(f)) {
			std::cout << "float: " << f << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
		} else {
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(f) << std::endl;
		}
	} else {
		printImpossible();
	}
}

void Convert::convertDouble(const std::string &str) {
	std::istringstream iss(str);
	double d;

	if (iss >> d) {
		std::cout << "char: ";
		if (d >= charMin && d <= charMax) {
			if (isprint(d)) {
				std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
			} else {
				std::cout << "Non displayable" << std::endl;
			}
		} else {
			std::cout << "impossible" << std::endl;
		}
		std::cout << "int: ";
		if (d >= intMin && d <= intMax) {
			std::cout << static_cast<int>(d) << std::endl;
		} else {
			std::cout << "impossible" << std::endl;
		}
		if (isInteger(d)) {
			std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
			std::cout << "double: " << d << ".0" << std::endl;
		} else {
			std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
		}
	} else {
		printImpossible();
	}
}

void Convert::printImpossible() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

Convert::Convert() {}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

Convert::~Convert() {}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

Convert::Convert(const Convert &other) {
	(void)other;
}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

Convert &Convert::operator=(const Convert &rhs) {
	(void)rhs;
	return *this;
}
