#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack();
	MutantStack(const MutantStack &other);
	~MutantStack();
	MutantStack &operator=(const MutantStack &rhs);

	typedef typename std::stack<T>::container_type Container;

	typedef typename Container::iterator iterator;
	iterator begin();
	iterator end();

	typedef typename Container::reverse_iterator reverse_iterator;
	reverse_iterator rbegin();
	reverse_iterator rend();

	typedef typename Container::const_iterator const_iterator;
	const_iterator cbegin() const;
	const_iterator cend() const;

	typedef typename Container::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator crbegin() const;
	const_reverse_iterator crend() const;
};

#include "MutantStack.tpp"

#endif // MUTANTSTACK_HPP
