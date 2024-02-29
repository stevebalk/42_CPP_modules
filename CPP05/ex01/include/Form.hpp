#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class Bureaucrat;

class Form {
public:
	Form(const std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form &other);
	~Form();

	Form &operator=(const Form &rhs);

	const std::string &getName() const;
	bool getIsSigned() const;
	size_t getGradeToSign() const;
	size_t getGradeToExecute() const;
	void beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};

private:
	Form();

	const std::string _name;
	const size_t _gradeToSign;
	const size_t _gradeToExecute;
	bool _isSigned;
};

std::ostream &operator<<(std::ostream &o, const Form &rhs);

#endif // FORM_HPP
