#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(std::string database_file);
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &rhs);

	std::string getDate() const;

	double getExchangeRate(std::string data_line);
	std::pair<double, double> getExchangeValue(std::string data_line);

	class ExceptionNegativeNumber : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class ExceptionNotANumber : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
	std::map<std::string, double> _exchangeData;
	std::string _date;

	void setDate(const std::string &str);
	std::string stripWhitespace(const std::string &str);
	bool isLeapYear(int year);
	bool isValidDate(std::string date);

	std::pair<std::string, double> extractData(std::string line, char delimiter);
	std::map<std::string, double> readDatabase(std::string database_file);

	template <typename T>
	T stot(const std::string &str);
};

#endif // BITCOINEXCHANGE_HPP
