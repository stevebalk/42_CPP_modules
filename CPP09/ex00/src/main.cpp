#include "BitcoinExchange.hpp"

std::string stripWhitespace(const std::string &str) {
	size_t firstNonWhitespace = str.find_first_not_of(" \t\n\r");
	if (firstNonWhitespace == std::string::npos) {
		return str;
	}
	size_t lastNonWhitespace = str.find_last_not_of(" \t\n\r");
	return str.substr(firstNonWhitespace, lastNonWhitespace - firstNonWhitespace + 1);
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./btc <filename>" << std::endl;
		return 1;
	}
	std::ifstream file(argv[1]);
	if (!file) {
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}

	//BitcoinExchange exchange;
	try {
		//exchange = BitcoinExchange("data.csv");
		BitcoinExchange exchange("data.csv");

		std::string line;
		while (std::getline(file, line)) {
			if (stripWhitespace(line).compare("date | value") == 0) {
				continue;
			}
			try {
				std::pair<double, double> value = exchange.getExchangeValue(line); // value.first = amount, value.second = rate
				std::cout << exchange.getDate() << " => " << value.first << " = " << (value.first * value.second) << std::endl;
			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		file.close();
		return (-1);
	}

	file.close();
	return (0);
}
