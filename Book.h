#pragma once
#include "LibMat.h"
class Book :
	public LibMat
{
public:
	Book(const string &title, const string &author);
	virtual ~Book();
	virtual void print() const {
		cout << "Book::print() -- I am a Book object!" << endl
			<< "My title is : " << _title << endl
			<< "My author is : " << _author << endl;
	}
	const string& title() const {
		return _title;
	}
	const string& author() const {
		return _author;
	}
protected:
	string _title;
	string _author;
};

