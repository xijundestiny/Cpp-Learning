#pragma once
#include "BTnode.h"

template<typename valType>
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(const BinaryTree&);
	~BinaryTree();
	BinaryTree& operator=(const BinaryTree&);
	bool empty() { return _root == 0; }
	void clear() {
		if (_root) {
			clear(_root);
			_root = 0;
		}
	}
	void preorder(ostream &os = cout) {
		os << "the preorder is: ";
		_root->preorder(_root,os);
		os << endl;
	}
	void inorder(ostream &os = cout) {
		os << "the inorder is: ";
		_root->inorder(_root, os);
		os << endl;
	}
	void postorder(ostream &os = cout) {
		os << "the postorder is: ";
		_root->postorder(_root, os);
		os << endl;
	}
	void insert(const valType &elem);
	void remove(const valType &elem);
	void remove_root();
private:
	BTnode<valType> *_root;
	void copy(BTnode<valType> *tar, BTnode<valType> *src);
	void clear(BTnode<valType> *pt);
};

template<typename valType>
inline BinaryTree<valType>::
BinaryTree()
	:_root(0)
{}

template<typename valType>
inline BinaryTree<valType>::
BinaryTree(const BinaryTree &bt) {
	copy(_root, bt._root);
}

template<typename valType>
inline BinaryTree<valType>::
~BinaryTree() {
	clear();
}

template<typename valType>
inline BinaryTree<valType>&
BinaryTree<valType>::
operator=(const BinaryTree &bt) {
	if (this != *bt) {
		clear();
		copy(_root, bt._root);
	}
	return *this;
}

template<typename valType>
inline void BinaryTree<valType>::
insert(const valType &elem) {
	if (!_root) {
		_root = new BTnode<valType>(elem);
	}
	else {
		_root->insert_value(elem);
	}
}

template<typename valType>
inline void
BinaryTree<valType>::
remove(const valType &elem) {
	if (_root) {
		if (_root->_val == elem)
			remove_root();
		else
			_root->remove_value(elem, _root);
	}
}

template<typename valType>
void BinaryTree<valType>::
remove_root() {
	if (!_root)
		return;
	BTnode<valType> *tmp = _root;
	if (_root->_rchild) {
		_root = _root->_rchild;
		if (tmp->_lchild) {
			BTnode<valType> *lc = tmp->_lchild;
			BTnode<valType> *newlc = _root->_lchild;
			if (!newlc)
				_root->_lchild = lc;
			else
				BTnode<valType>::lchild_leaf(lc, newlc);
		}
	}
	else {
		_root = _root->_lchild;
	}
	delete tmp;
}

template<typename valType>
void BinaryTree<valType>::
clear(BTnode<valType> *pt) {
	if (pt) {
		clear(pt->_lchild);
		clear(pt->_rchild);
		delete pt;
	}
}

