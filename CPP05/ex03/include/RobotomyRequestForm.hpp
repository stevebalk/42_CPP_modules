#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

	void executeConcrete() const;

private:
	RobotomyRequestForm();
};

#endif // ROBOTOMYREQUESTFORM_HPP