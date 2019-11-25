#ifndef STACK_H
#define STACK_H

#include <vector>
#include <string>
using namespace std;

class Stack {
public:
	bool push(const string&);
	bool pop(string &elem);
	bool peek(string &elem);
	bool empty();
	bool full();
	int size() { 
		return _stack.size(); 
	}
private:
	vector<string> _stack;


};
inline bool 
Stack::empty(){
	return _stack.empty();

}
inline bool
Stack::full() {
	return _stack.size() == _stack.max_size();
}

#endif // !STACK_H

