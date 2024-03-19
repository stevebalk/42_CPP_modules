#include <RPN.hpp>

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

bool RPN::isNumber(const std::string &str) {
	std::stringstream ss(str);
	int64_t f;
	ss >> f;
	// Check if the entire string was consumed and if there's no error
	return (ss.eof() && !ss.fail());
}

void RPN::calculate(const std::string equation) {
	std::stringstream ss(equation);
	std::string token;

	while (std::getline(ss, token, ' ')) {
		if (isNumber(token)) {
			_number_stack.push(stot<int64_t>(token));
		} else {
			if (token.size() != 1 || (token[0] != '+' && token[0] == '-' && token[0] == '*' && token[0] == '/')) {
				throw InvalidEquation();
			}
			if (_number_stack.size() < 2) {
				throw InvalidEquation();
			}

			int64_t num2 = _number_stack.top();
			_number_stack.pop();
			int64_t num1 = _number_stack.top();
			_number_stack.pop();

			if (token == "+")
				_number_stack.push(num1 + num2);
			else if (token == "-")
				_number_stack.push(num1 - num2);
			else if (token == "*")
				_number_stack.push(num1 * num2);
			else if (token == "/") {
				if (num2 == 0)
					throw std::runtime_error("Error: zero division");
				else
					_number_stack.push(num1 / num2);
			}
		}
	}
	if (_number_stack.size() != 1)
		throw InvalidEquation();

	int64_t result = _number_stack.top();
	_number_stack.pop();
	std::cout << result << std::endl;
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

RPN::RPN() {}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

RPN::~RPN() {}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

RPN::RPN(const RPN &other) {
	*this = other;
}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

RPN &RPN::operator=(const RPN &rhs) {
	if (this != &rhs) {
		_number_stack = rhs._number_stack;
	}
	return *this;
}

/********************************************************************/
/*                          EXCEPTIONS                              */
/********************************************************************/

const char *RPN::InvalidEquation::what() const throw() {
	return "Error";
}

/********************************************************************/
/*                          TEMPLATES                               */
/********************************************************************/

// Reads the string and tries to convert it to T
template <typename T>
T RPN::stot(const std::string &str) {
	std::stringstream ss(str);
	T f;
	if (!(ss >> f)) {
		throw RPN::InvalidEquation();
	}
	std::string remaining;
	if (ss >> remaining) {
		throw RPN::InvalidEquation();
	}
	return f;
}
