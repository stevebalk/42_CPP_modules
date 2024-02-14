#include "Harl.hpp"

const std::string Harl::_complains[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

Harl::Harl() {
	std::cout << "Harl enters the restaurant and takes a seat."
			  << std::endl << std::endl;
}

Harl::~Harl() {
	std::cout << "Harl leaves the restaurant." << std::endl;
}

void Harl::setFilterLevel(std::string level) {
	for (int i = 0; i < 4; i++) {
		if (_complains[i].compare(level) == 0) {
			_filter_level = i;
			return;
		}
	}
	_filter_level = -1;
}

void Harl::debug() {
	std::cout << "[ DEBUG ]" << std::endl
			  << "I love having extra bacon for my "
			  << "7XL-double-cheese-triple-pickle-special- "
			  << "ketchup burger." << std::endl << "I really do!"
			  << std::endl << std::endl;
}

void Harl::info() {
	std::cout << "[ INFO ]" << std::endl
			  << "I cannot believe adding extra bacon costs more money. "
			  << std::endl << "You didn’t put "
			  << "enough bacon in my burger! If you did, I wouldn’t be "
			  << "asking for more! "
			  << std::endl << std::endl;
}

void Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl
			  << "I think I deserve to have some extra bacon for free. "
			  << std::endl << "I’ve been coming for "
			  << "years whereas you started working here since last month."
			  << std::endl << std::endl;
}

void Harl::error() {
	std::cout << "[ ERROR ]" << std::endl
			  << "This is unacceptable! "
			  << "I want to speak to the manager now."
			  << std::endl << std::endl;
}

void Harl::complain(std::string level) {
	setFilterLevel(level);
	switch (_filter_level) {
		case DEBUG:
			this->debug();
			/* fall through */
		case INFO:
			this->info();
			/* fall through */
		case WARNING:
			this->warning();
			/* fall through */
		case ERROR:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
					  << std::endl;
			break;
	}
}
