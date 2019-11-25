#include "Book.h"



Book::Book(const string &title,const string &author)
	:_title(title),_author(author)
{
	cout << "Book::Book("<< _title << "," << _author << ") constructor!" << endl;
}


Book::~Book()
{
	cout << "Book::~Book() destructor!" << endl;
}
