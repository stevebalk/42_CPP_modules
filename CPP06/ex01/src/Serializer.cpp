#include "Serializer.hpp"

/********************************************************************/
/*                          MEMBER FUNCTIONS                        */
/********************************************************************/

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

/********************************************************************/
/*                          CONSTRUCTOR                             */
/********************************************************************/

Serializer::Serializer() {}

/********************************************************************/
/*                          DECONSTRUCTOR                           */
/********************************************************************/

Serializer::~Serializer() {}

/********************************************************************/
/*                          COPY CONSTRUCTOR                        */
/********************************************************************/

Serializer::Serializer(Serializer const &src) {
	*this = src;
}

/********************************************************************/
/*                          OPERATOR OVERLOAD                       */
/********************************************************************/

Serializer &Serializer::operator=(Serializer const &rhs) {
	(void)rhs;
	return (*this);
}
