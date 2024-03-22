#ifndef RPN_HPP
#define RPN_HPP

#include <stdint.h>
#include <exception>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN {
public:
	RPN();
	RPN(const RPN &other);
	~RPN();

	RPN &operator=(const RPN &rhs);

	void calculate(const std::string equation);

	class InvalidEquation : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
	std::stack<int64_t> _number_stack;

	void calculateStacks();
	bool isNumber(const std::string &str);

	template <typename T>
	T stot(const std::string &str);
};

#endif
