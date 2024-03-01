#include "Bureaucrat.hpp"
#include "Colors.h"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

const std::string &Bureaucrat::getName() const {
	return _name;
}

size_t Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	try {
		if (_grade == 1) {
			throw Bureaucrat::GradeTooHighException();
		}
		_grade--;
	} catch (const std::string e) {
		std::cout << e << std::endl;
	}
}

void Bureaucrat::decrementGrade() {
	try {
		if (_grade == 150) {
			throw Bureaucrat::GradeTooHighException();
		}
		_grade++;
	} catch (const std::string e) {
		std::cout << e << std::endl;
	}
}

void Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << "✅ " << *this << " signed form \"" << form.getName() << "\""
				  << std::endl;
	} catch (const std::exception &e) {
		std::cout << "❌ " << getName() << BOLD RED " couldn't sign \"" C_RESET << form.getName()
				  << "\" because: " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const{
	try {
		form.execute(*this);
		std::cout << "✅ " << *this << " executed " << form.getName()
				  << " successfully!" << std::endl;
	} catch (std::exception &e) {
		std::cout << "❌ " << getName() << BOLD RED " couldn't execute \"" C_RESET
				  << form.getName() << "\" because: "
				  << e.what() << std::endl;
	}
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

Bureaucrat::Bureaucrat(const std::string &name, const size_t grade) :
		_name(name),
		_grade(grade) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

Bureaucrat::~Bureaucrat() {}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

Bureaucrat::Bureaucrat(const Bureaucrat &other) :
		_name(other._name),
		_grade(other._grade) {}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs) {
		_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}

/********************************************************************/
/*                          EXCEPTIONS                              */
/********************************************************************/

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade to high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade to low";
}
