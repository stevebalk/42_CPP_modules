#include "RobotomyRequestForm.hpp"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

void RobotomyRequestForm::executeConcrete() const {
	srand(static_cast<unsigned>(time(0)));
	int random_number = rand() % 2;

	std::cout << "You hear some drilling noises after the execution of "
			  << getName() << std::endl;
	if (random_number) {
		std::cout << getTarget() << " has successfully been robotomized!"
				  << std::endl;
	} else {
		std::cout << getTarget() << " robotomization failed!"
				  << std::endl;
	}
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
		AForm("RobotomyRequestForm", 72, 45, target) {}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

RobotomyRequestForm::~RobotomyRequestForm() {}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
		AForm(other) {}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
	}
	return *this;
}
