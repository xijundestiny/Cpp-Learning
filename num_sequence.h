#pragma once
#include <iostream>
#include<vector>
#include<typeinfo>
using namespace std;
class num_sequence
{
public:
	virtual ~num_sequence();
	int elem(int pos) const;
	const char* what_am_i() const {
		return typeid(*this).name();
	}
	int length() const {
		return _length;
	}
	int beg_pos() const {
		return _beg_pos;
	}
	static int max_elems() {
		return _max_elems;
	}
	ostream& print(ostream &os = cout) const;
protected:
	virtual void gen_elems(int pos) const = 0;
	bool check_integrity(int pos,int size) const;
	num_sequence(int len, int bp, vector<int> &re)
		:_length(len), _beg_pos(bp), _relems(re) {}
	const static int _max_elems = 1024;
	int _length;
	int _beg_pos;
	vector<int> &_relems;
};

ostream& operator<<(ostream &os, const num_sequence &ns);

