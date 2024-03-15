#include "BitcoinExchange.hpp"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

std::string BitcoinExchange::getDate() const {
	return _date;
}

void BitcoinExchange::setDate(const std::string &str) {
	_date = str;
}

std::string BitcoinExchange::stripWhitespace(const std::string &str) {
	size_t firstNonWhitespace = str.find_first_not_of(" \t\n\r");
	if (firstNonWhitespace == std::string::npos) {
		return str;
	}
	size_t lastNonWhitespace = str.find_last_not_of(" \t\n\r");
	return str.substr(firstNonWhitespace, lastNonWhitespace - firstNonWhitespace + 1);
}

bool BitcoinExchange::isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(std::string date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}
	try {
		int year = stot<int>(date.substr(0, 4));
		int month = stot<int>(date.substr(5, 2));
		int day = stot<int>(date.substr(8, 2));

		if (year < 0 || month < 1 || month > 12 || day < 1)
			return false;
		static const int daysInMonth[] = { 31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		return day <= daysInMonth[month - 1];
	} catch (const std::exception &e) {
		return false;
	}
	return true;
}

std::pair<std::string, double> BitcoinExchange::extractData(std::string line, char delimiter) {
	size_t delimiter_position = line.find(delimiter);

	if (delimiter_position == std::string::npos) {
		throw std::runtime_error("Error: Format delimiter Error");
	}
	std::string date = stripWhitespace(line.substr(0, delimiter_position));
	std::string value = stripWhitespace(line.substr(delimiter_position + 1));

	if (!isValidDate(date)) {
		throw std::runtime_error("Error: bad input => " + date);
	}
	setDate(date);

	double value_num;
	try {
		value_num = stot<double>(value);
	} catch (const std::exception &e) {
		throw ExceptionNotANumber();
	}
	if (value_num < 0) {
		throw ExceptionNegativeNumber();
	}
	return std::make_pair(date, value_num);
}

std::map<std::string, double> BitcoinExchange::readDatabase(std::string database_file) {
	std::map<std::string, double> db_content;

	std::fstream file;
	file.open(database_file.c_str());
	if (file.fail()) {
		throw std::runtime_error("Error: Could not open database file \"" + database_file + "\"");
	}

	std::string line;
	while (std::getline(file, line)) {
		if (stripWhitespace(line).compare("date,exchange_rate") == 0) {
			continue;
		}
		try {
			std::pair<std::string, double> value = extractData(line, ',');
			db_content[value.first] = value.second;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return (db_content);
}

double BitcoinExchange::getExchangeRate(std::string data_line) {
	std::pair<std::string, double> value = extractData(data_line, '|');

	std::map<std::string, double>::iterator upper = _exchangeData.upper_bound(value.first);
	if (upper != _exchangeData.begin()) {
		--upper;
	} else {
		throw std::runtime_error("Error: no date found that is less or equal to the target date");
	}

	return upper->second;
}

std::pair<double, double> BitcoinExchange::getExchangeValue(std::string data_line) {
	double rate = getExchangeRate(data_line);

	std::pair<std::string, double> value = extractData(data_line, '|');

	if (value.second > 1000) {
		throw std::runtime_error("Error: too large a number");
	}

	return std::make_pair(value.second, rate);
}

/********************************************************************/
/*                          TEMPLATE                                */
/********************************************************************/

// Reads the string and tries to convert it to T
template <typename T>
T BitcoinExchange::stot(const std::string &str) {
	std::stringstream ss(str);
	T f;
	if (!(ss >> f)) {
		throw BitcoinExchange::ExceptionNotANumber();
	}
	std::string remaining;
	if (ss >> remaining) {
		throw BitcoinExchange::ExceptionNotANumber();
	}
	return f;
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

BitcoinExchange::BitcoinExchange() {
	_exchangeData = readDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(std::string database_file) {
	_exchangeData = readDatabase(database_file);
}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

BitcoinExchange::~BitcoinExchange() {}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	if (this != &other) {
		_exchangeData = other._exchangeData;
	}
	*this = other;
}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	_exchangeData = rhs._exchangeData;
	return *this;
}

/********************************************************************/
/*                          EXCEPTIONS                              */
/********************************************************************/

const char *BitcoinExchange::ExceptionNotANumber::what() const throw() {
	return ("Error: not a (valid) number");
}

const char *BitcoinExchange::ExceptionNegativeNumber::what() const throw() {
	return ("Error: not a positive number");
}
