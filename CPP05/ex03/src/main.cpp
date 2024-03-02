#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "PrintHeader.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iomanip>
#include <iostream>

void makeFormTests(const std::string test_name, AForm *form, const Bureaucrat &high_grade, const Bureaucrat &low_grade) {
	PrintHeader::printH1(test_name, BLUE);

	std::cout << std::endl;
	std::cout << BOLD "Execute unsigned form with: " << RED "NOT ENOUGH GRADE" C_RESET << std::endl;
	low_grade.executeForm(form);
	std::cout << std::endl;

	std::cout << BOLD "Sign unsigned form with: " << RED "NOT ENOUGH GRADE" C_RESET << std::endl;
	low_grade.signForm(form);
	std::cout << std::endl;

	std::cout << BOLD "Sign unsigned form with: " << GREEN "GRADE OK" C_RESET << std::endl;
	high_grade.signForm(form);
	std::cout << std::endl;

	std::cout << BOLD "Execute signed form with: " << RED "NOT ENOUGH GRADE" C_RESET << std::endl;
	low_grade.executeForm(form);
	std::cout << std::endl;

	std::cout << BOLD "Execute signed form with: " << GREEN "GRADE OK" C_RESET << std::endl;
	high_grade.executeForm(form);
	std::cout << std::endl;

	delete (form);
}

int main(void) {
	PrintHeader::printH1("Create bureaucrat", BLUE);
	Bureaucrat lowBureaucrat("Junior Dave", 150);
	Bureaucrat highBureaucrat("Boss Bob", 1);

	std::cout << std::endl
			  << "Bureaucrats created: "
			  << highBureaucrat << std::endl
			  << lowBureaucrat << std::endl
			  << std::endl;

	PrintHeader::printH1("Create intern", BLUE);
	Intern intern;

	std::cout << std::endl
			  << "Intern created: "
			  << std::endl
			  << std::endl;

	makeFormTests("ShrubberyCreationForm", intern.makeForm("shrubbery creation", "home"), highBureaucrat, lowBureaucrat);
	makeFormTests("RobotomyRequestForm", intern.makeForm("robotomy request", "home"), highBureaucrat, lowBureaucrat);
	makeFormTests("PresidentialPardonForm", intern.makeForm("presidential pardon", "home"), highBureaucrat, lowBureaucrat);
	makeFormTests("UnknownForm", intern.makeForm("unknown form", "home"), highBureaucrat, lowBureaucrat);

	std::cout << std::endl;
	return (0);
}