#include "Triangular.h"

Triangular::Triangular(int len, int bp) {
	_length = len > 0 ? len : 1;
	_beg_pos = bp > 0 ? bp : 1;
	_next = _beg_pos - 1;

}
Triangular::Triangular(const Triangular &rhs)
	:_length(rhs._length), _beg_pos(rhs._beg_pos), _next(rhs._beg_pos - 1) {
	
}

vector<int> Triangular::_elems;

ostream& operator<<(ostream &os, const Triangular &rhs) {
	os << "(" << rhs.beg_pos() << "," << rhs.length() << ")";
	return os;
}
istream& operator>>(istream &is, Triangular &rhs) {
	char c1, c2;
	int bp, len;
	is >> c1 >> bp >> c2 >> len;
	rhs.set_beg(bp);
	rhs.set_length(len);
	return is;
}