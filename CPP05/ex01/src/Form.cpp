#include "Form.hpp"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

const std::string &Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

size_t Form::getGradeToSign() const {
	return _gradeToSign;
}

size_t Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > getGradeToSign()) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

Form::Form(const std::string name, int gradeToSign, int gradeToExecute) :
		_name(name),
		_gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute),
		_isSigned(false) {
	if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	} else if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();
	}
}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

Form::~Form() {}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

Form::Form(const Form &other) :
		_gradeToSign(other._gradeToSign),
		_gradeToExecute(other._gradeToExecute),
		_isSigned(other._isSigned) {}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

Form &Form::operator=(const Form &rhs) {
	if (this != &rhs) {
		_isSigned = rhs._isSigned;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, const Form &form) {
	o << "----- Form info -----" << std::endl;
	o << "Form name:            " << form.getName() << std::endl
	  << "Signed:               " << (form.getIsSigned() ? "Yes" : "No") << std::endl
	  << "Lowest sign grade:    " << form.getGradeToSign() << std::endl
	  << "Lowest execute grade: " << form.getGradeToExecute() << std::endl;
	return o;
}

/********************************************************************/
/*                          EXCEPTIONS                              */
/********************************************************************/

const char *Form::GradeTooHighException::what() const throw() {
	return "grade to high!";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "grade to low!";
}
