#ifndef PRI_H
#define PRI_H


#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <stack>

using namespace std;
extern int abc;
template <typename T>
void prin(const vector<T> &vec);

void prin_t(const vector<int> vec, void(*prin_ptr)(const vector<int> &vec));

void prin1(const vector<int> &vec);

#endif // !PRI_H

