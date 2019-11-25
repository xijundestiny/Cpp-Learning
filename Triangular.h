#ifndef TRIANGULAR_H
#define TRIANGULAR_H

#include <vector>
#include <iostream>
#include "Triangular_iterator.h"
using namespace std;
class Triangular {
	friend class Triangular_iterator;
public:
	Triangular(int len = 1,int bp=1);
	Triangular(const Triangular &rhs);
	~Triangular() {

	}
	Triangular& copy(const Triangular &rhs) {
		if (this != &rhs) {
			_length = rhs._length;
			_beg_pos = rhs._beg_pos;
			_next = rhs._beg_pos - 1;
		}
		return *this;
	}
	int length() const {
		return _length;
	}
	int beg_pos() const {
		return _beg_pos;
	}
	void set_length(int len) {
		_length = len;
	}
	void set_beg(int beg) {
		_beg_pos = beg;
	}
	void initial_size() {
		cout << _elems.size() << " " << _initial_size << endl;
	}
	static void value() {
		vector<int> vec1({ 6,4,3,1,5,7,1,4,7,8,9 });
		_elems.insert(_elems.begin(),vec1.begin(),vec1.end());
		cout << _elems[0] << endl;
	}
	typedef Triangular_iterator iterator;
	Triangular_iterator begin() const {
		return Triangular_iterator(_beg_pos);
	}
	Triangular_iterator end() const {
		return Triangular_iterator(_beg_pos+_length);
	}
private:
	int _length;
	int _beg_pos;
	int _next;
	static vector<int> _elems;
	static const int _initial_size=8;
};

ostream& operator<<(ostream &os, const Triangular &rhs);
istream& operator>>(istream &is, Triangular &rhs);
#endif // !TRIANGULAR_H

