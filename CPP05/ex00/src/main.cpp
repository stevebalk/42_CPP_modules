#include "Bureaucrat.hpp"

int main(void) {
	{
		try {
			Bureaucrat toolow("low", 151);
		} catch (std::exception &e) {
			std::cout << "Created below lowest grade:" << std::endl;
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try {
			Bureaucrat toohigh("high", 0);
		} catch (std::exception &e) {
			std::cout << "Created above highest grade:" << std::endl;
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		Bureaucrat a("Bob", 3);
		std::cout << "Created " << a << std::endl;
		Bureaucrat b("Dave", 148);
		std::cout << "Created " << b << std::endl;
		std::cout << std::endl;
		try {
			for (size_t i = 0; i < 3; i++) {
				std::cout << a.getName() << " try to incremented grade to: "
						  << a.getGrade() - 1 << std::endl;
				a.incrementGrade();
				std::cout << "It worked. new grade: "
						  << a.getGrade() << std::endl;
			}
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try {
			for (size_t i = 0; i < 3; i++) {
				std::cout << b.getName() << " try to decrement grade to: "
						  << b.getGrade() + 1 << std::endl;
				b.decrementGrade();
				std::cout << "It worked. New grade: "
						  << b.getGrade() << std::endl;
			}
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}
