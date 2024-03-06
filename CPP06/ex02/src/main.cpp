#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base *generate(void) {
	int i = std::rand() % 3;
	if (i == 0) {
		std::cout << "Class A generated" << std::endl;
		return new A;
	} else if (i == 1) {
		std::cout << "Class B generated" << std::endl;
		return new B;
	} else {
		std::cout << "Class C generated" << std::endl;
		return new C;
	}
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p)) {
		std::cout << "Type of base pointer is A" << std::endl;
	} else if (dynamic_cast<B *>(p)) {
		std::cout << "Type of base pointer is B" << std::endl;
	} else if (dynamic_cast<C *>(p)) {
		std::cout << "Type of base pointer is C" << std::endl;
	}
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Type of base reference is A" << std::endl;
		return;
	} catch (const std::exception &e) {
	}
	try {
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Type of base reference is B" << std::endl;
		return;
	} catch (const std::exception &e) {
	}
	try {
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Type of base reference is C" << std::endl;
		return;
	} catch (const std::exception &e) {
	}
}

int main() {
	std::srand(time(NULL));
	Base *base = generate();

	identify(base);
	identify(*base);

	delete base;

	return 0;
}
