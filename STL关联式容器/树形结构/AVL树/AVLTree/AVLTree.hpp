#pragma once
#include<iostream>

using namespace std;

template<class T>
struct AVLTreeNode {
	AVLTreeNode(const T& data = T())
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _data(data)
		, _bf(0)
	{}
	AVLTreeNode<T>* _pLeft;
	AVLTreeNode<T>* _pRight;
	//AVLTreeNode<T>* _pParent;
	T _data;
	int _bf;
};
template<class T>
class AVLTree {
	typedef AVLTreeNode<T> Node;
	typedef AVLTreeNode<T>* PNode;
public:
	AVLTree()
		:_pRoot(nullptr);
	{}
	~AVLTree()
	{
		_Distroy(_pRoot);
	}
	bool Insert(const T& data) {
		if (_pRoot == nullptr) {
			_pRoot = new Node(data);
			return true;
		}
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		//’“µΩŒª÷√
		while (pCur) {
			pParent = pCur;
			if (pCur->_data > data)
				pCur = pCur->_pLeft;
			else if (pCur->_data < data)
				pCur = pCur->_pRight;
			else
				return false;
		}
		//≤Â»Î
		pCur = new Node(data);
		if (data < pParent->_data) {
			pParent->_pLeft = pCur;
		}
		else {
			pParent->_pRight = pCur;
		}
		
	}
	bool IsBalanceTree(PNode pRoot) {
		
	}
private:
	void _Distroy(Node* pRoot) {
		if (pRoot == nullptr)
			return;
		_Distroy(pRoot->_pLeft);
		_Distroy(pRoot->_pRight);
		delete pRoot;
		pRoot = nullptr;
	}
private:
	PNode _pRoot;
};
void Test() {
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	AVLTree<int> t;
	for (auto e : a)
		t.Insert(e);
}