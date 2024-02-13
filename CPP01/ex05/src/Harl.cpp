#include "Harl.hpp"

Harl::Harl() {
	std::cout << "Harl enters the restaurant and takes a seat."
			  << std::endl << std::endl;
}

Harl::~Harl() {
	std::cout << "Harl leaves the restaurant." << std::endl;
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
	const std::string complains[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void (Harl::*func_ptr[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	for (int i = 0; i < 4; i++) {
		if (complains[i].compare(level) == 0) {
			(this->*func_ptr[i])();
			return;
		}
	}
	std::cout << "Harl is speechless!" << std::endl << std::endl;
}
