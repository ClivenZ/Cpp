#pragma once

#include<iostream>
#include<queue>
#include<stack>
using namespace std;


template<class T>
struct BSTNode {
	BSTNode(const T& data = T)
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_data(data)
	{}
	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
	T _data;
};
template<class T>
class BSTree {
	typedef BSTNode<T> Node;
	typedef Node* PNode;
public:
	BSTree()
		:_pRoot(nullptr)
	{}
	~BSTree() {
		_Distory(_pRoot);
	}
	PNode Find(const T& data) {
		PNode pCur = _pRoot;
		while (pCur) {
			if (pCur->_data == data)
				return _pRoot;
			else if (pCur->_data < data)
				pCur = _pRoot->_pLeft;
			else if (pCur->_data > data)
				pCur = _pRoot->_pRight;
		}
		return nullptr;
	}
	bool Insert(const T& data) {
		//����
		if (_pRoot == nullptr) {
			_pRoot = new Node(data);
			return true;
		}
		//����Ϊ�գ��ҵ�λ��
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		while (pCur) {
			pParent = pCur;
			if (pCur->_data > data) {
				pCur = pCur->_pLeft;
			}
			else if (pCur->_data < data) {
				pCur = pCur->_pRight;
			}
			else {
				return false;
			}
		}
		//����
		pCur = new Node(data);
		if (data < pParent->_data) {
			pParent->_pLeft = pCur;
		}
		else {
			pParent->_pRight = pCur;
		}
		return true;
	}
	bool Erase(const T& data) {
		if (_pRoot == nullptr)
			return false;
		PNode pCur = _pRoot;
		PNode pParent = nullptr;
		//Ѱ�Ҹý��
		while (pCur) {
			if (pCur->_data > data) {
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else if(pCur->_data < data) {
				pParent = pCur;
				pCur = pCur->_pRight;
			}
			else 
				break;
		}
		if (pCur == nullptr)
			return false;
		//����ҵ��󣬷��������
		//1��Ҫɾ���Ľ��ֻ������
		//2��Ҫɾ���Ľ��ֻ���Һ���
		//3��Ҫɾ���Ľ�����Һ��Ӷ���
		if (pCur->_pLeft == nullptr) {
			pParent->_pLeft = pCur->_pLeft;
			delete pCur;
		}
		else if (pCur->_pRight == nullptr) {
			pParent->_pRight = pCur->_pRight;
			delete pCur;
		}
		else {

		}
		return true;
	}
	//ǰ���С��������
	void Preorder() {
		_Postorder(_pRoot);
	}
	void Inorder() {
		_Inorder(_pRoot);
	}
	void Postorder() {
		_Postorder(_pRoot);
	}
	//ǰ���С���������ǵݹ�
	void PreorderNor() {
		_PreorderNor(_pRoot);
	}
	void InorderNor() {
		_InorderNor(_pRoot);
	}
	void PostorderNor() {
		_PostorderNor(_pRoot);
	}
	//�������
	void LevelOrder() {
		_LevelOrder(_pRoot);
	}
private:
	//ǰ���С���ݹ����
	void _Preorder(PNode pRoot) {
		if (pRoot == nullptr)
			return;
		printf("%s",pRoot->_data);
		_Preorder(pRoot->_pLeft);
		_Preorder(pRoot->_pRight);
	}
	void _Inorder(PNode pRoot) {
		if (pRoot == nullptr)
			return;
		_Inorder(pRoot->_pLeft);
		printf("%s", pRoot->_data);
		_Inorder(pRoot->_pRight);
	}
	void _Postorder(PNode pRoot) {
		if (pRoot == nullptr)
			return;
		_Postorder(pRoot->_pLeft);
		_Postorder(pRoot->_pRight);
		printf("%s", pRoot->_data);
	}
	//ǰ���С���ǵݹ����
	void _PreorderNor(PNode pRoot) {
		stack<PNode> s;
		PNode pCur;
		PNode pTop;
		pCur = pRoot;
		if (pCur == nullptr)
			return;
		while (!s.empty()) {
			while (pCur != nullptr) {
				printf("%s",pCur->_data);
				s.push(pCur);
				pCur = pCur->_pLeft;
			}
			pTop = s.top;
			s.pop();

			pCur = pTop->_pRight;
		}
	}
	void _InorderNor(PNode pRoot) {
		stack<PNode> s;
		PNode pCur;
		pCur = pRoot;
		if (pRoot == nullptr)
			return;
		while (!s.empty()) {
			while (pCur != nullptr) {
				s.push(pCur);
				pCur = pCur->_pLeft;
			}
			pCur = s.top();
			s.pop();
			printf("%s",pCur->_data);
			pCur = pCur->_pRight;
		}
	}
	void _PostorderNor(PNode pRoot) {
		stack<PNode> s;
		PNode pCur;
		PNode pTop;
		PNode pLast;
		pCur == pRoot;
		if (pCur == nullptr)
			return;
		while (!s.empty()) {
			while (pCur != nullptr) {
				s.push(pCur);
				pCur = pCur->_pLeft;
			}
			pTop = s.top();
			if (pTop->_pRight == nullptr || pTop->_pRight == pLast ) {
				s.pop();
				printf("%s",pTop->_data);
				pLast = pTop;
			}
			else {
				pCur = pTop->_pRight;
			}
		}
	}
	//�������
	void _LevelOrder(PNode pRoot) {
		queue<PNode> q;
		PNode* front;
		if (pRoot == nullptr)
			return;
		q.push(pRoot);
		while (!q.empty()) {
			front = q.front();
			q.pop();
			if (front->_pLeft)
				q.push(front->_pLeft);
			if (front->_pRight)
				q.push(front->_pRight);
			printf("%s",front->_data);
		}
	}
private:
	void _Distory(Node* pRoot) {
		_Distory(pRoot->_pLeft);
		_Distory(pRoot->_pRight);
		delete pRoot;
		pRoot = nullptr;
	}
private:
	PNode _pRoot;
};
void Test1()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> t;
	for (auto e : a)
		t.Insert(e);
	
}