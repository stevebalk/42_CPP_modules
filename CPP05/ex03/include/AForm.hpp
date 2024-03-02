#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include "PrintHeader.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <fstream>
#include <iostream>

class Bureaucrat;

class AForm {
public:
	AForm(const std::string name, int gradeToSign, int gradeToExecute, const std::string _target);
	AForm(const AForm &other);
	virtual ~AForm();

	AForm &operator=(const AForm &rhs);

	const std::string &getName() const;
	bool getIsSigned() const;
	size_t getGradeToSign() const;
	size_t getGradeToExecute() const;
	const std::string &getTarget() const;

	void beSigned(const Bureaucrat &bureaucrat);
	void execute(Bureaucrat const &executor) const;

	// --------- Exceptions -------------//

	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};

	class NotSignedException : public std::exception {
		virtual const char *what() const throw();
	};

protected:
	virtual void executeConcrete() const = 0;

private:
	AForm();

	const std::string _name;
	const size_t _gradeToSign;
	const size_t _gradeToExecute;
	bool _isSigned;
	const std::string _target;
};

std::ostream &operator<<(std::ostream &o, const AForm &rhs);

#endif // AFORM_HPP
