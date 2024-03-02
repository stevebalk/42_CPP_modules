#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <exception>
#include <iostream>

class AForm;

class Bureaucrat {
public:
	Bureaucrat(const std::string &name, const size_t grade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &rhs);

	const std::string &getName() const;
	size_t getGrade() const;
	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(AForm *form) const;

	void executeForm(AForm const *form) const;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class NotAValidFormException : public std::exception {
		virtual const char *what() const throw();
	};

private:
	Bureaucrat();
	const std::string _name;
	size_t _grade;
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif // BUREAUCRAT_HPP
