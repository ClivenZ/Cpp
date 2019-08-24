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
	AVLTreeNode<T>* _pParent;
	T _data;
	int _bf;
};
template<class T>
class AVLTree {
	typedef AVLTreeNode<T> Node;
	typedef AVLTreeNode<T>* PNode;
public:
	AVLTree()
		:_pRoot(nullptr)
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
		//�ҵ�λ��
		while (pCur) {
			pParent = pCur;
			if (pCur->_data > data)
				pCur = pCur->_pLeft;
			else if (pCur->_data < data)
				pCur = pCur->_pRight;
			else
				return false;
		}
		//����
		pCur = new Node(data);
		if (data < pParent->_data) {
			pParent->_pLeft = pCur;
			pCur->_pParent = pParent;
		}
		else {
			pParent->_pRight = pCur;
			pCur->_pParent = pParent;
		}
		while (pParent) {
			//����pParent��ƽ������
			if (pCur = pParent->_pLeft)
				pParent->_bf--;
			else
				pParent->_bf++;
			//��֤ƽ����
			if (pParent->_bf == 0)
				break;
			else if (pParent->_bf == 1 || pParent->_bf == -1) {
				//���ϵ���
				pCur = pParent;
				pParent = pCur->_pParent;
			}
			else {
				if (pParent->_bf == 2) {
					if (pCur->_bf == 1)
						RotateRL(pParent);
					else
						RotateRL(pParent);
				}
				else {
					if (pCur->_bf == -1)
						RotateRight(pParent);
					else
						RotateLR(pParent);
				}
				pCur = pParent->_pParent;
				pParent = pCur->_pParent;
			}
		}	
		return true;
	}
	//�ҵ���
	void RotateRight(PNode pParent) {
		//pSubL:pParent������
		//pSubLR:pParent���ӵ��Һ���
		PNode pSubL = pParent->_pLeft;
		PNode pSubLR = pSubL->_pRight;
		
		pParent->_pLeft = pSubLR;
		//pSubLR != NULL ����˫��
		if (pSubLR)
			pSubLR->_pParent = pParent;
		
		PNode ppParent = pParent->_pParent;
		pSubL->_pRight = pParent;
		//����pParent��˫��
		pParent->_pParent = pSubL;
		if (ppParent == nullptr) {
			_pRoot = pSubL;
			pSubL->_pParent = nullptr;
		}
		else {
			if (ppParent->_pLeft == pParent)
				ppParent->_pLeft = pSubL;
			else
				ppParent->_pRight = pSubL;
		}
		//����_bf
		pSubL->_bf = 0;
		if (pParent->_pLeft == nullptr && pParent->_pRight != nullptr)
			pParent->_bf = 1;
		else
			pParent->_bf = 0;
	}
	//����
	void RotateLeft(PNode pParent) {
		PNode pSubR = pParent->_pRight;
		PNode pSubRL = pSubR->_pLeft;
		PNode ppParent = pParent->_pParent;

		pParent->_pRight = pSubRL;
		if (pSubRL)
			pSubRL->_pParent = pParent;

		pSubR->_pRight = pParent;
		pParent->_pParent = pSubR;
		if (ppParent == nullptr) {
			_pRoot = pSubR;
			pSubR->_pParent == nullptr;
		}
		else {
			if (ppParent->_pLeft == pParent)
				ppParent->_pLeft = pSubR;
			else
				ppParent->_pRight = pSubR;
		}

		pSubR->_bf = 0;
		if (pParent->_pRight == nullptr && pParent->_pLeft != nullptr)
			pParent->_bf = -1;
		else
			pParent->_bf = 0;

	}
	void RotateLR(PNode pParent) {
		PNode pSubL = pParent->_pLeft;
		PNode pSubLR = pSubL->_pRight;

		int bf = pSubLR->_bf;

		RotateLeft(pParent->_pLeft);
		RotateRight(pParent);

		if (bf == 1)
			pSubL->_bf = -1;
		else if (bf == -1)
			pParent->_bf = 1;
	}
	void RotateRL(PNode pParent) {

	}

	void Inoder() {
		_Inorder(_pRoot);
	}
	int Height(PNode pRoot);
	bool IsBalanceTree(PNode pRoot) {
		if (pRoot == nullptr)
			return true;
		//��������֮��
		int leftHeight = Height(pRoot->_pLeft);
		int rightHeight = Height(pRoot->_pRight);
		int diff = rightHeight - leftHeight;
		//�������֮�����pRoot��_bf�����߾���ֵ����1��������false
		if (diff != pRoot->_bf || (diff > 1 || diff < -1))
			return false;
		//���ҵݹ���֤
		return IsBalanceTree(pRoot->_pLeft) && IsBalanceTree(pRoot->_pRight);
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
	void _Inorder(PNode pRoot) {
		if (pRoot == nullptr)
			return;
		_Inorder(pRoot->_pLeft);
		printf("%s ",pRoot);
		_Inorder(pRoot->_pRight);
	}
private:
	PNode _pRoot;
};
void Test() {
	int a[] = { 20,30,40,60,70 };
	AVLTree<int> t;
	for (auto e : a)
		t.Insert(e);
	t.Insert(10);
}