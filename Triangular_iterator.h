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
	//������ֵ
	Triangular_iterator& operator=(const Triangular_iterator &rhs);
	int operator*() const;
	//ǰ�ð�++������������������
	Triangular_iterator& operator++() {
		++_index;
		return *this;
	}
	//���ð�++������++֮ǰ�ĸ��������Դ�ֵ��ʽ����
	Triangular_iterator operator++(int) {
		Triangular_iterator temp = *this;
		++_index;
		return temp;
	}
private:
	int _index;
};

