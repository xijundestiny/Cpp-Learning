#pragma once
#include <iostream>
using namespace std;
template<typename valType>
class BinaryTree;

template <typename valElem>
class BTnode
{
	friend class BinaryTree<valElem>;
public:
	BTnode(const valElem &val);
	virtual ~BTnode();
	void insert_value(const valElem &val);
	void remove_value(const valElem &val,BTnode *& prev);
	static void lchild_leaf(BTnode *leaf,BTnode *subtree);
	void preorder(BTnode *pt,ostream &os) const;
	void inorder(BTnode *pt, ostream &os) const;
	void postorder(BTnode *pt, ostream &os) const;
private:
	valElem _val;
	int _cnt;
	BTnode *_lchild;
	BTnode *_rchild;
};

template<typename valElem>
inline BTnode<valElem>::
BTnode(const valElem &val)
	:_val(val)
{
	_cnt = 1;
	_lchild = _rchild = 0;
}

template <typename valElem>
inline BTnode<valElem>::
~BTnode()
{
}

template<typename valElem>
inline void
BTnode<valElem>::
insert_value(const valElem &val) {
	if (val == _val) {
		_cnt++;
		return;
	}
	if (val < _val) {
		if (!_lchild)
			_lchild = new BTnode(val);
		else
			_lchild->insert_value(val);

	}
	else {
		if (!_rchild)
			_rchild = new BTnode(val);
		else
			_rchild->insert_value(val);
	}
}

template<typename valElem>
void BTnode<valElem>::
lchild_leaf(BTnode *leaf, BTnode *subtree) {
	while (subtree->_lchild)
		subtree = subtree->_lchild;
	subtree->_lchild = leaf;
}

template<typename valElem>
void BTnode<valElem>::
remove_value(const valElem &val, BTnode *& prev) {
	if (val < _val) {
		if (!_lchild)
			return;
		else
			_lchild->remove_value(val, _lchild);
	}
	else if (val > _val) {
		if (!_rchild)
			return;
		else
			_rchild->remove_value(val, _rchild);
	}
	else {
		if (_rchild) {
			prev = _rchild;
			if (_lchild) {
				if (!prev->_lchild)
					prev->_lchild = _lchild;
				else
					BTnode<valElem>::lchild_leaf(_lchild, prev->_lchild);
			}
		}
		else
			prev = _lchild;
		delete this;

	}
}

template<typename valElem>
void BTnode<valElem>::
preorder(BTnode *pt,ostream &os) const {
	if (pt) {
		os << pt->_val << " ";
		if (pt->_lchild)
			preorder(pt->_lchild,os);
		if (pt->_rchild)
			preorder(pt->_rchild,os);
	}
}

template<typename valElem>
void BTnode<valElem>::
inorder(BTnode *pt, ostream &os) const {
	if (pt) {
		if (pt->_lchild)
			inorder(pt->_lchild, os);
		os << pt->_val << " ";
		if (pt->_rchild)
			inorder(pt->_rchild, os);
	}
}

template<typename valElem>
void BTnode<valElem>::
postorder(BTnode *pt, ostream &os) const {
	if (pt) {
		if (pt->_lchild)
			postorder(pt->_lchild, os);
		if (pt->_rchild)
			postorder(pt->_rchild, os);
		os << pt->_val << " ";
	}
}

