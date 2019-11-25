#include <vector>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		int num = 0;
		int i = 1;
		while (1) {
			if (ugly(i))
				num++;
			if (num == index)
				return i;
			i++;
		}
	}
	bool ugly(int number) {
		while (number % 2 == 0)
			number /= 2;
		while (number % 3 == 0)
			number /= 3;
		while (number % 5 == 0)
			number /= 5;
		return (number == 1) ? true : false;
	}
};