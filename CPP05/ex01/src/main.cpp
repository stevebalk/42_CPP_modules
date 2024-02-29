#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iomanip>

void printH1(const std::string text) {
	const char fill_char = '*';
	const size_t width = 80;
	size_t offset_end = (width - text.length()) / 2 - 1;
	size_t offset_start = offset_end + text.length() % 2;

	std::cout << std::endl;
	std::cout << std::setfill(fill_char) << std::setw(width) << "" << std::endl;
	std::cout << "*";
	std::cout << std::setfill(' ') << std::setw(offset_start) << std::right << "";
	std::cout << std::setw(text.length()) << std::left << text;
	std::cout << std::setfill(' ') << std::setw(offset_end) << std::left << "";
	std::cout << "*";
	std::cout << std::endl;
	std::cout << std::setfill(fill_char) << std::setw(width) << "" << std::endl;
}

int main(void) {
	// Bureaucrat grade high enough
	{
		printH1("Bureaucrat with high enough grade signs Form");
		Bureaucrat a("Bob", 1);
		Form FormA("A1", 75, 75);

		std::cout << "Created " << a << std::endl;
		std::cout << a << std::endl
				  << "tries to sign: " << FormA.getName()
				  << std::endl
				  << std::endl;
		std::cout << "BEFORE:" << std::endl;
		std::cout << FormA << std::endl;
		a.signForm(FormA);
		std::cout << std::endl;
		std::cout << "AFTER:" << std::endl;
		std::cout << FormA << std::endl;
	}

	// Bureaucrat grade NOT high enough
	{
		printH1("Bureaucrat with NOT high enough grade tries to sign a Form");
		Bureaucrat b("Dave", 150);
		Form FormB("B1", 75, 75);

		std::cout << "Created " << b << std::endl;
		std::cout << b << std::endl
				  << "tries to sign: " << FormB.getName()
				  << std::endl
				  << std::endl;
		std::cout << "BEFORE:" << std::endl;
		std::cout << FormB << std::endl;
		b.signForm(FormB);
		std::cout << std::endl;
		std::cout << "AFTER:" << std::endl;
		std::cout << FormB << std::endl;
	}

	// Form with too high grade
	{
		printH1("Form with too high grade");
		try {
			std::cout << "Trying to create a Form with too high grade Sign:" << std::endl;
			Form tooHigh("TooHigh", 0, 10);
		} catch (const std::exception &e) {
			std::cerr << e.what() << '\n'
					  << std::endl;
		}
	}

	// Form with too low grade
	{
		printH1("Form with too low grade");
		try {
			std::cout << "Trying to create a Form with too low grade Sign:" << std::endl;
			Form tooLow("TooLow", 151, 140);
		} catch (const std::exception &e) {
			std::cerr << e.what() << '\n'
					  << std::endl;
		}
	}

	// Form with to high execution grade
	{
		printH1("Form with to high execution grade");
		try {
			std::cout << "Trying to create a Form with too high grade Execution:" << std::endl;
			Form tooHigh("TooHigh", 10, 0);
		} catch (const std::exception &e) {
			std::cerr << e.what() << '\n'
					  << std::endl;
		}
	}

	// Form with to low execution grade
	{
		printH1("Form with to low execution grade");
		try {
			std::cout << "Trying to create a Form with too low grade Execution:" << std::endl;
			Form tooLow("TooLow", 130, 151);
		} catch (const std::exception &e) {
			std::cerr << e.what() << '\n'
					  << std::endl;
		}
	}
}
