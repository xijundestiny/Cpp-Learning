#include "Triangular_iterator.h"
#include "Triangular.h"


Triangular_iterator::Triangular_iterator(int index):_index(index-1)
{
}


Triangular_iterator::~Triangular_iterator()
{
}
int Triangular_iterator::operator*() const {
	return Triangular::_elems[_index];
}

Triangular_iterator& Triangular_iterator::operator=(const Triangular_iterator &rhs) {
	if (this != &rhs) {
		_index = 5;
	}
	return *this;
}