#include "AForm.hpp"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

const std::string &AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

size_t AForm::getGradeToSign() const {
	return _gradeToSign;
}

size_t AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

const std::string &AForm::getTarget() const {
	return _target;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > getGradeToSign()) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const {
	if (_isSigned == false) {
		throw NotSignedException();
	} else if (_gradeToExecute < executor.getGrade()) {
		throw GradeTooLowException();
	}
	executeConcrete();
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute, const std::string target) :
		_name(name),
		_gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute),
		_isSigned(false),
		_target(target) {
	if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	} else if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();
	}
}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

AForm::~AForm() {}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

AForm::AForm(const AForm &other) :
		_name(other._name),
		_gradeToSign(other._gradeToSign),
		_gradeToExecute(other._gradeToExecute),
		_isSigned(other._isSigned),
		_target(other._target) {}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

AForm &AForm::operator=(const AForm &rhs) {
	if (this != &rhs) {
		_isSigned = rhs._isSigned;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, const AForm &form) {
	o << BOLD "\t ----- Form info -----" C_RESET << std::endl;
	o << BOLD "Form name:            " C_RESET << form.getName() << std::endl
	  << BOLD "Signed:               " C_RESET << (form.getIsSigned() ? "Yes" : "No") << std::endl
	  << BOLD "Lowest sign grade:    " C_RESET << form.getGradeToSign() << std::endl
	  << BOLD "Lowest execute grade: " C_RESET << form.getGradeToExecute() << std::endl;
	return o;
}

/********************************************************************/
/*                          EXCEPTIONS                              */
/********************************************************************/

const char *AForm::GradeTooHighException::what() const throw() {
	return "grade to high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "grade to low!";
}

const char *AForm::NotSignedException::what() const throw() {
	return "Form is not signed";
}
