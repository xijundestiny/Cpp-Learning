#pragma once
class LessThan
{
public:
	LessThan(int val);
	~LessThan();
	int comp_val() const {
		return _val;
	}
	void comp_val(int nval) {
		_val = nval;
	}
	bool operator()(int value) const {
		return value < _val;
	}
private:
	int _val;
};

