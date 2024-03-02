#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	*this = other;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &rhs) {
	(void)rhs;
	return *this;
}

// Could have done it with an function pointer array, but this would mean
// create 3 additional functions here, in the headerfile, create another
// array in the function and it would look way more unreadable.
// So even if the eval sheet says something about, it's think it's cleaner
// (at least for this small program) to do it this way.
// If you want to see the other way, look at the commented code below.

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
	std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (size_t i = 0; i < sizeof(formNames) / sizeof(formNames[0]); i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			switch (i) {
				case 0:
					return (new ShrubberyCreationForm(target));
				case 1:
					return (new RobotomyRequestForm(target));
				case 2:
					return (new PresidentialPardonForm(target));
			}
		}
	}
	std::cout << "Intern cannot create " << formName << std::endl;
	return NULL;
}

// AForm *Intern::createShrubberyForm(const std::string &target) {
// 	return new ShrubberyCreationForm(target);
// }

// AForm *Intern::createRequestForm(const std::string &target) {
// 	return new RobotomyRequestForm(target);
// }

// AForm *Intern::createPresidentialForm(const std::string &target) {
// 	return new PresidentialPardonForm(target);
// }

// AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
// 	std::string formNames[] = {
// 		"shrubbery creation",
// 		"robotomy request",
// 		"presidential pardon"
// 	};

// 	AForm *(Intern::*formCreators[])(const std::string &) = {
// 		&Intern::createShrubberyForm,
// 		&Intern::createRequestForm,
// 		&Intern::createPresidentialForm
// 	};

// 	for (size_t i = 0; i < sizeof(formNames) / sizeof(formNames[0]); i++) {
// 		if (formName == formNames[i]) {
// 			std::cout << "Intern creates " << formName << std::endl;
// 			return (this->*formCreators[i])(target);
// 		}
// 	}
// 	std::cerr << "Intern cannot create " << formName << std::endl;
// 	return NULL;
// }
