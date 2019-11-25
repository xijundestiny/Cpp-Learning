#include "pri.h"

int abc;

template<typename T>
void prin(const vector<T> &vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
	T b = 2;
	cout << "b=" << b << endl;
}

void prin1(const vector<int> &vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
	abc = 1;
	cout << "abc=" << abc << endl;
}


void prin_t(const vector<int> vec, void(*prin_ptr)(const vector<int> &vec)) {
	prin_ptr(vec);
}