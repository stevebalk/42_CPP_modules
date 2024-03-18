#include <RPN.hpp>

RPN::RPN() {}

RPN::RPN(const RPN &other) {
	if (this != &other) {
		_number_stack = other._number_stack;
	}
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &rhs) {
	_number_stack = rhs._number_stack;
	return *this;
}

void RPN::calculate(const std::string equation) {
	std::stringstream ss(equation);

	int64_t num;

	// ss >> std::skipws >> num;
	// if (ss.fail()) {
	// 	throw InvalidEquation();
	// }
	// _number_stack.push(num);
	while (ss.eof() == false) {
		ss >> num;
		if (ss.fail()) {
			ss.clear();
			std::cout << "Fail" << std::endl;
			char token;
			ss >> std::skipws >> token;
			std::cout << "Char: " << static_cast<int>(token) << std::endl;
			if (token == '+' || token == '-' || token == '*' || token == '/') {
				_token_stack.push(token);
				if (_number_stack.size() >= _token_stack.size()) {
					throw InvalidEquation();
				} else if (_number_stack.size() - 1 == _token_stack.size()) {
					calculateStacks();
				}
			} else {
				throw InvalidEquation();
			}
		} else {
			std::cout << num << std::endl;
			_number_stack.push(num);
		}
	}

	if (_number_stack.size() == 1) {
		std::cout << _number_stack.top() << std::endl;
	} else {
		throw InvalidEquation();
	}
}

void RPN::calculateStacks() {
	for (size_t i = 0; i < _token_stack.size(); i++) {
		int64_t a = _number_stack.top();
		_number_stack.pop();
		int64_t b = _number_stack.top();
		_number_stack.pop();

		switch (_token_stack.top()) {
			case '+':
				_number_stack.push(add(a, b));
			case '-':
				_number_stack.push(subtract(a, b));
			case '*':
				_number_stack.push(multiply(a, b));
			case '/':
				_number_stack.push(divide(a, b));
		}
		_token_stack.pop();
	}
}

template <typename T>
T RPN::add(T a, T b) {
	return (a + b);
}

template <typename T>
T RPN::subtract(T a, T b) {
	return (a - b);
}

template <typename T>
T RPN::multiply(T a, T b) {
	return (a * b);
}

template <typename T>
T RPN::divide(T a, T b) {
	return (a / b);
}

const char *RPN::InvalidEquation::what() const throw() {
	return "Error";
}
