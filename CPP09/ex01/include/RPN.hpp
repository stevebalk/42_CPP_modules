#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <exception>
#include <string>
#include <stdint.h>

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
	std::stack<char>    _token_stack;

	void calculateStacks();

	template <typename T>
	T add(T a, T b);

	template <typename T>
	T subtract(T a, T b);

	template <typename T>
	T multiply(T a, T b);

	template <typename T>
	T divide(T a, T b);
};

#endif
