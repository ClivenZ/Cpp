#pragma once
#include<iostream>
using namespace std;
namespace My {
	template<class T>
	struct ListNode{
		ListNode(const T& val = T())
			:_pPre(nullptr)
			, _pNext(nullptr)
			, _val(nullptr)
		{}
		ListNode<T>* _pPre;
		ListNode<T>* _pNext;
		T _val;
	};
	//正向迭代器
	template<class T, class Ref, class Ptr>
	class ListIterator {
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;
	public:
		ListIterator(PNode pNode = nullptr)
			:_pNode(pNode)
		{}
		ListIterator(const Self& l)
			:_pNode(l._pNode) 
		{}
		T* operator*() {
			return _pNode->_val;
		}
		T* operator->() {
			return &(operator*());
		}
		Self& operator++() {
			_pNode = _pNode->_pNext;
			return *this;
		}
		Self& operator++(int) {
			Self temp(*this);
			_pNode = _pNode->_pNext;
			return temp;
		}
		bool operator==(const Self& l) {
			return _pNode == l._pNode;
		}
		bool operator!=(const Self& l) {
			return _pNode != l._pNode;
		}
		PNode _pNode;
	};
	//反向迭代器
	template<class T,class Ref,class Ptr,class Iterator>
	class ListReverseIterator {
		typedef ListReverseIterator<T, Ref, Ptr, iterator> Self;
	public:
		ListReverseIterator(const Iterator& it)
			:_it(it)
		{}
		ListReverseIterator(const Self& l)
			:_it(l._it)
		{}
		Ref operator*() {
			Iterator temp = _it;
			return *(--temp);
		}
		Ref operator->() {
			return &operator*();
		}
		Self& operator++() {
			--_it;
			return *this;
		}
		Self operator++() {
			Iterator temp(_it);
			--_it;
			return temp;
		}
		Self& operator--() {
			++_it;
			return *this;
		}
		Self operator--() {
			iterator temp(_it);
			++_it;
			return temp;
		}
		bool operator!=(const Self& s) {
			return _it != s._it;
		}
		bool operator==(const Self& s) {
			return _it == s._it;
		}
	private:
		Iterator _it;
	};
	template<class T>
	class List {
		typedef ListIterator<T, T&, T*> Iterator;
		typedef ListIterator<T, const T&, const T*> ConstIterator;
		typedef ListReverseIterator<T, T&, T*, Iterator> ReverseIterator;
		typedef ListReverseIterator<T, const T&, const T*, const Iterator> ConstReveresIterator;
	public:
		//构造
		List() {
			CreateHead();
		}
		List(int n ,const T& value = T()) {
			CreateHead();
			for (int i = 0; i < n;++i) {
				PushBack(value);
			}
		}
		template<class Iterator>
		List(Iterator first,Iterator last) {
			CreateHead();
			while (first!=last) {
				PushBack(*first);
				++first;
			}
		}
		List(const List<T>& l) {
			CreateHead();
			List<T> temp(l.CBegin(), l.CEnd());
			this->Swap(temp);
		}
		List<T>& operator=(const List<T>& l) {
			if (this != &l) {
				List<T> temp(l);
				this->Swap(temp);
			}
			return *this;
		}
		~List() {
			Clear();
			delete _PHead;
			_PHead = nullptr;
		}
		/*    List Itreator   */
		Iterator Begin() {
			return Iterator(_PHead->_pNext);
		}
		Iterator End() {
			return Iterator(_PHead);
		}
		ReverseIterator RBegin() {
			return ReverseIterator(End());
		}
		ReverseIterator REnd() {
			return ReverseIterator(Begin());
		}
		ConstIterator CBegin() {
			return ConstIterator(_PHead->_pNext);
		}
		ConstIterator CEnd() {
			return ConstIterator(_PHead);
		}
		ConstReveresIterator CRBegin() {
			return ConstReveresIterator(CEnd());
		}
		ConstReveresIterator CREnd() {
			return ConstReveresIterator(CBegin());
		}
		/*    List Capacity   */
		size_t Size()const {
			size_t count = 0;
			PNode pCur = _PHead->_pNext;
			while (pCur != _PHead) {
				++count;
				pCur = pCur->_pNext;
			}
			return count;
		}
		bool Empty() {
			return _PHead->_pNext == _PHead;
		}
		void Resize(size_t newSize,const T& val = T()) {
			size_t oldSize = Size();
			if (oldSize <= newSize) {
				for (size_t i = oldSize; i < newSize; ++i)
					PushBack(val);
			}
			else {
				for (size_t i = newSize; i < oldSize; ++i)
					PopBack(val);
			}
		}
		/*    List Access   */
		T& Front() {
			return _PHead->_pNext->_val;
		}
		const T& Front()const {
			return _PHead->_pNext->_val;
		}
		T& Back() {
			return _PHead->_pPre->_val;
		}
		const T& Back() const {
			return _PHead->_pPre->_val;
		}
		/*    List Modify   */
		void PushBack(const T& val) {
			PNode pNewNdoe = new Node(val);

			pNewNdoe->_pNext = _PHead;
			pNewNdoe->_pPre = _PHead->_pPre;

			_PHead->_pPre = pNewNdoe;
			pNewNdoe->_pPre->_pNext = pNewNdoe;
		}
		void PopBack() {
			PNode pDel = _PHead->_pPre;
			if (pDel != _PHead) {
				_PHead->_pPre = pDel->_pPre;
				pDel->_pPre->_pNext = _PHead;
				delete pDel;
			}
		}
		void PushFront(const T& val) {
			PNode pNewNode = new Node(val);

			pNewNode->_pNext = _PHead->_pNext;
			pNewNode->_pPre = _PHead;

			_PHead->_pNext = pNewNode;
			pNewNode->_pNext->_pPre = pNewNode;
		}
		void PopFront() {
			PNode PDel = _PHead->_pNext;
			if (PDel != _PHead) {
				_PHead->_pNext = PDel->_pNext;
				PDel->_pNext->_pPre = _PHead;
				delete PDel;
			}
		}
		Iterator Inerst(Iterator pos,const T& val) {
			PNode pNewNode = new Node(val);
			PNode pCur = pos._pNode;

			pNewNode->_pPre = pCur->_pPre;
			pNewNode->_pNext = pCur;
			pNewNode->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;
			return iterator(pNewNode);
		}
		Iterator Erase(Iterator pos) {
			PNode pDel = pos._pNode;
			PNode pRet = pDel->_pNext;

			pDel->_pPre->_pNext = pDel->_pNext;
			pDel->_pNext->_pPre = pDel->_pPre;
			delete pDel;

			return Iterator(pRet);
		}
		void Clear() {
			PNode pCur = _PHead->_pNext;
			while (pCur != _PHead) {
				_PHead->_pNext = pCur->_pNext;
				delete pCur;
				pCur = _PHead->_pNext;
			}
			_PHead->_pNext = _PHead;
			_PHead->_pPre = _PHead;
		}
		void Swap(List<T>& l) {
			swap(_PHead,l._PHead);
		}
	private:
		void CreateHead() {
			_PHead = new Node;
			_PHead->_pPre = _PHead;
			_PHead->_pNext = _PHead;
		}
	private:
		PNode _PHead;
	};
}