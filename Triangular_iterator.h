#pragma once
class Triangular;
class Triangular_iterator
{
public:
	Triangular_iterator(int index);
	~Triangular_iterator();
	bool operator==(const Triangular_iterator &rhs) const {
		return _index == rhs._index;
	}
	bool operator!=(const Triangular_iterator &rhs) const {
		return !(*this == rhs);
	}
	//拷贝赋值
	Triangular_iterator& operator=(const Triangular_iterator &rhs);
	int operator*() const;
	//前置版++，返回自身，所以引用
	Triangular_iterator& operator++() {
		++_index;
		return *this;
	}
	//后置版++，返回++之前的副本，所以传值方式返回
	Triangular_iterator operator++(int) {
		Triangular_iterator temp = *this;
		++_index;
		return temp;
	}
private:
	int _index;
};

