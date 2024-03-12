#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "PrintHeader.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iomanip>
#include <iostream>

void gradeTests(const std::string test_name, AForm &form, const Bureaucrat &low_grade, const Bureaucrat &high_grade) {
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
}

int main(void) {
	PrintHeader::printH1("Create bureaucrats with different grades", BLUE);
	Bureaucrat lowlyBureaucrat("Lowly Larry", 146);
	Bureaucrat highBureaucrat("High Harry", 3);

	std::cout << std::endl
			  << "Bureaucrats created:\n"
				 "\t"
			  << lowlyBureaucrat << "\n"
									"\t"
			  << highBureaucrat << std::endl
			  << std::endl;

	ShrubberyCreationForm shrubForm("Forest");
	RobotomyRequestForm roboForm("Robo");
	PresidentialPardonForm presForm("Bob");

	PrintHeader::printH1("Create different forms", BLUE);
	std::cout << std::endl
			  << shrubForm << "\n"
			  << roboForm << "\n"
			  << presForm << "\n";

	gradeTests("ShrubberyCreationForm", shrubForm, lowlyBureaucrat, highBureaucrat);
	gradeTests("RobotomyRequestForm", roboForm, lowlyBureaucrat, highBureaucrat);
	gradeTests("PresidentialPardonForm", presForm, lowlyBureaucrat, highBureaucrat);

	std::cout << std::endl;
	return (0);
}
