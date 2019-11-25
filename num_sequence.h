#pragma once
#include <iostream>
#include<vector>
using namespace std;
class num_sequence
{
public:
	num_sequence();
	virtual ~num_sequence();
	virtual int elem(int pos) const = 0;
	virtual const char* what_am_i() const = 0;
	static int max_elems() {
		return _max_elems;
	}
	virtual ostream& print(ostream &os = cout) const = 0;
protected:
	virtual void gen_elems(int pos) const = 0;
	bool check_integrity(int pos,int size) const;
	const static int _max_elems = 1024;
};

ostream& operator<<(ostream &os, const num_sequence &ns);

