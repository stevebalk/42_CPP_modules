#include "ShrubberyCreationForm.hpp"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

void ShrubberyCreationForm::executeConcrete() const {
	std::string filename = (AForm::getTarget() + "_shrubbery");
	std::ofstream file(filename.c_str());

	if (!file.is_open()) {
		std::cerr << "Unable to open file: " << AForm::getTarget() << std::endl;
		return;
	}
	file << "             '.,                         '.,            \n";
	file << "           'b      *                   'b      *        \n";
	file << "            '$    #.                    '$    #.        \n";
	file << "             $:   #:                     $:   #:        \n";
	file << "             *#  @):                     *#  @):        \n";
	file << "             :@,@):   ,.**:'             :@,@):   ,.**:'\n";
	file << "   ,         :@@*: ..**'       ,         :@@*: ..**'    \n";
	file << "    '#o.    .:(@'.@*              o.    .:(@'.@*        \n";
	file << "       'bq,..:,@@*'   ,*           'bq,..:,@@*'   ,*    \n";
	file << "       ,p$q8,:@)'  .p*'            ,p$q8,:@)'  .p*'     \n";
	file << "      '    '@@Pp@@*'              '    '@@Pp@@*'        \n";
	file << "            Y7'.'                       Y7'.'           \n";
	file << "           :@):.                       :@):.            \n";
	file << "          .:@:'.                      .:@:'.            \n";
	file << "        .::(@:.                     .::(@:.             \n";
	file.close();
	std::cout << "File: " << filename << " created!" << std::endl;
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
		AForm("ShrubberyCreationForm", 145, 137, target) {}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
		AForm(other) {}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
	}
	return *this;
}
