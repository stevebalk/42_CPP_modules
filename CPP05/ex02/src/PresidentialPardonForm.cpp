#include "PresidentialPardonForm.hpp"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

void PresidentialPardonForm::executeConcrete() const {
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox"
			  << std::endl;
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
		AForm("PresidentialPardonForm", 25, 5, target) {}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

PresidentialPardonForm::~PresidentialPardonForm() {}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
		AForm(other) {}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
	}
	return *this;
}
