#include <vector>
#include <list>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <iterator>
#include <typeinfo>

#include "solution.h" 
#include "pri.h"
#include "Stack.h"
#include "Triangular.h"
#include "LessThan.h"
#include "LibMat.h"
#include "Book.h"
#include "Fibonacci.h"
#include "BTnode.h"
#include "BinaryTree.h"


using namespace std;

inline void display(const vector<int> &vec, ostream &file = cout);
inline void display(const num_sequence &ns, int pos, ostream &os = cout);

enum {
	ns_prin,ns_prin1
};

void sort(vector<int> &vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = i + 1; j < vec.size(); j++) {
			if (vec[j] < vec[i]) {
				int temp;
				temp = vec[j];
				vec[j] = vec[i];
				vec[i] = temp;
			}
		}
	}
}

const vector<int> *run() {
	int a = 1;
	static vector<int> elem;
	elem.push_back(1);
	return &elem;
}

template<typename Iterator>
void find(Iterator first, Iterator last) {
	for (; first != last; first++) {
		cout << *first<<" ";
	}
	cout << endl;
	
}

bool less_than(int v1, int v2) {
	return v1 < v2 ? true : false;
}

bool greater_than(int v1, int v2) {
	return v1 > v2 ? true : false;
}

template<typename InIterator,typename OutIterator,typename elemType,typename Comp>
OutIterator filter(InIterator first, InIterator last, OutIterator out,elemType value,Comp pred) {
	while ((first = find_if(first, last, not1(bind2nd(less<int>(),value)))) != last) {
		*out++ = *first++;
	}
	return out;
}

void print(const LibMat &mat) {
	cout << "in global print(): about to print mat.print()" << endl;
	mat.print();
}

int main(){
	
	vector<int> vec1({6,4,3,1,5,7,1,4,7,8,9});
	BinaryTree<string> bt;
	bt.insert("Piglet");
	bt.insert("Eeyore");
	bt.insert("Roo");
	bt.insert("Tigger");
	bt.insert("Chris");
	bt.insert("Pooh");
	bt.insert("Kanga");
	bt.preorder();
	bt.remove("Piglet");
	bt.preorder();
	bt.remove("Eeyore");
	bt.preorder();
	cout << "run time is " << (double)clock()/CLK_TCK <<"s"<< endl;
	system("pause");
	return 0;
}

inline void display(const vector<int> &vec, ostream &file) {
	for (int i = 0; i < vec.size(); i++) {
		file << vec[i] << " ";
	}
	file << endl;
}

inline void display(const num_sequence &ns,int pos, ostream &os) {
	os << "The element at position " << pos << " for the " << 
		ns.what_am_i() << " sequence is " << ns.elem(pos) << endl;
}

