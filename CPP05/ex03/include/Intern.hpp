#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

class Intern {
public:
	Intern();
	Intern(const Intern &other);
	~Intern();
	Intern &operator=(const Intern &rhs);

	AForm *makeForm(const std::string &formName, const std::string &target);
// private:
// 	AForm *createShrubberyForm(const std::string &target);
// 	AForm *createRequestForm(const std::string &target);
// 	AForm *createPresidentialForm(const std::string &target);
};

#endif // INTERN_HPP
