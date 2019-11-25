#pragma once
#include <iostream>
#include <string>
using namespace std;
class LibMat
{
public:
	LibMat();
	virtual ~LibMat();
	virtual void print() const {
		cout << "LibMat::print() --I am a LibMat object!" << endl;
	}
};

