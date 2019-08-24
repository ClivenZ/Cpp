#pragma once

#include<iostream>
#include<vector>
using namespace std;

template<class T>
class DefHashF {
public:
	size_t operator()(const T& val) {
		return val;
	}
};
template<class V>
struct HashBucketNode {
	HashBucketNode(const V& data)
		:_pNext(nullptr)
		, _data(data)
	{}
	HashBucketNode<V>* _pNext;
	V _data;
};
template<class V,class HF = DefHashF<T> >
class HashBucket {
	typedef HashBucketNode<T> Node;
	typedef Node* PNode;
public:
	HashBucket(size_t capacity = 3)
		:_size(0)
	{
		_ht.resize(GetNextPrime(capacity), nullptr);
	}
	PNode* Insert(const V& data) {

	}
	PNode* Erase(const V& data) {

	}
	PNode* Find(const V& data) {}
	size_t Size()const {}
	bool Empty()const {}
	void Clear(){}
	bool BucketCount()const {}
	void Swap(HashBucket<V, HF>& ht) {}
	~HashBucket(){}
private:
	size_t HashFunc(const V& data){}
private:
	vector<PNode*> _ht;
	size_t _size;
};