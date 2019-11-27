#pragma once
#include "num_sequence.h"
class Fibonacci :
	public num_sequence
{
public:
	Fibonacci(int len=1,int beg_pos=1);
	virtual ~Fibonacci();
	/*virtual const char* what_am_i() const {
		return "Fibonacci";
	}*/
protected:
	virtual void gen_elems(int pos) const;
	static vector<int> _elems;
};

//ostream& operator<<(ostream &os, const Fibonacci &ns);