#pragma once
#include<iostream>
using namespace std;

//节点的颜色
enum Color{ RED, BLACK};
//
template<class ValueType>
struct RBTreeNode {
	RBTreeNode(const ValueType& data = ValueType(),Color color = RED)
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_pParent(nullptr)
		,_data(data)
		,_color(color)
	{}
	RBTreeNode<ValueType>* _pLeft;
	RBTreeNode<ValueType>* _pRight;
	RBTreeNode<ValueType>* _pParent;
	ValueType _data;
	Color _color;
};
template<class ValueType>
class RBTree {
public:
	typedef RBTreeNode<ValueType> Node;
	typedef RBTreeNode<ValueType>* PNode;
	RBTree()
		:_pRoot(nullptr)
	{}
	~RBTree() {
		_Distroy();
	}
	bool Insert(const ValueType& data) {

	}
private:
	PNode& GetRoot(){ return _pHead->_pParent}
	PNode LeftMost();
	PNode RightMost();
private:
	void _Distroy(PNode pRoot) {
		if (pRoot == nullptr)
			return;
		_Distroy(pRoot->_pLeft);
		_Distroy(pRoot->_pRight);
		delete pRoot;
		pRoot = nullptr;
	}
private:
	PNode _pHead;
};