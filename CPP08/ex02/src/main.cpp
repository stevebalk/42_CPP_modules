#include "MutantStack.hpp"
#include "PrintHeader.hpp"
#include <iostream>
#include <list>
#include <iomanip>

void testStandardMemberFuntions() {
	PrintHeader::printH1("Standard member function test");
	MutantStack<int> mstack;

	std::cout << "Is MutantStack empty?: " << std::boolalpha << mstack.empty()  << std::noboolalpha << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(1);
	std::cout << "Pushed " << mstack.top() << " on the stack" << std::endl;
	mstack.push(2);
	std::cout << "Pushed " << mstack.top() << " on the stack" << std::endl;
	mstack.pop();
	std::cout << "Removed top element from the stack.\nNew top element: " << mstack.top() << std::endl;
	std::cout << "Is MutantStack empty?: " << std::boolalpha << mstack.empty()  << std::noboolalpha << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
}

void testMutantStackIterators() {
	PrintHeader::printH1("MutantStack iterator test");
	MutantStack<int> mStack;

	mStack.push(42);
	mStack.push(37);

	std::cout << "Top value: " << mStack.top() << std::endl;

	mStack.pop();

	std::cout << "Size: " << mStack.size() << std::endl;

	mStack.push(20);
	mStack.push(60);
	mStack.push(0);
	mStack.push(77);

	// Normal iterator
	MutantStack<int>::iterator it = mStack.begin();
	MutantStack<int>::iterator end = mStack.end();

	++it;
	--it;
	std::cout << "Normal iterator: ";
	while (it != end) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	// Const iterator
	MutantStack<int>::const_iterator cit = mStack.cbegin();
	MutantStack<int>::const_iterator cend = mStack.cend();

	// *cit = 11; // Wouldn't compile because it's a constant value
	++cit;
	--cit;
	std::cout << "Const iterator: ";
	while (cit != cend) {
		std::cout << *cit << " ";
		++cit;
	}
	std::cout << std::endl;

	// Reverse iterator
	MutantStack<int>::reverse_iterator rit = mStack.rbegin();
	MutantStack<int>::reverse_iterator rend = mStack.rend();

	++rit;
	--rit;
	std::cout << "Reverse iterator: ";
	while (rit != rend) {
		std::cout << *rit << " ";
		++rit;
	}
	std::cout << std::endl;

	// Const reverse iterator
	MutantStack<int>::const_reverse_iterator crit = mStack.crbegin();
	MutantStack<int>::const_reverse_iterator crend = mStack.crend();

	// *crit = 11; // Wouldn't compile because it's a constant value
	++crit;
	--crit;
	std::cout << "Const reverse iterator: ";
	while (crit != crend) {
		std::cout << *crit << " ";
		++crit;
	}
	std::cout << std::endl
			  << std::endl;
}

void testSubject() {
	PrintHeader::printH1("Subject test", BLUE);
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void testSubjectList() {
	PrintHeader::printH1("Subject list test");
	std::list<int> mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}

int main() {
	testSubject();
	testSubjectList();
	testMutantStackIterators();
	testStandardMemberFuntions();
	return 0;
}
