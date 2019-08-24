#pragma once
#include<iostream>
#include<vector>
using namespace std;

//位置标记
enum State {EMPYT, EXITS, DELETE};
//整形转化
template<class T>
class DefHashF {
public:
	size_t operator()(const T& val) {
		return val;
	}
};
//key 为字符串整形，需要将其转化为整形
class Str2Int {
public:
	size_t operator()(const string& s) {
		const char* str = s.c_str();
		unsigned int seed = 131;
		unsigned int hash = 0;
		while (&str) {
			hash = hash * seed + (*str++);
		}
		return (hash & 0x7FFFFFFF);
	}
};
template<class K,class V,class HF>
class HashTable {
	struct Elem {
		pair<K, V> _val;
		State _state;
	};
public:
	HashTable(size_t capacity = 3)
		:_ht(capacity)
		,_size(0)
	{
		for (size_t i = 0; i < capacity; ++i)
			_ht[i]._state = EMPYT;
	}
	bool Insert(const pair<K, V>& val) {
		//检查哈希表底层空间是否足够
		//CheckCapacity();
		size_t hashAddr = HashFunc(key);
		while (_ht[hashAddr]._state != EMPTY) {
			if (_ht[hashAddr]._state == EXITS && _ht[hashAddr]._val.first == key)
				return false;
			hashAddr++;
			if (hashAddr == _ht.capacity())
				hashAddr = 0;
		}
		_ht[hashAddr]._state = EXITS;
		_ht[hashAddr]._val = val;
		_size++;
		return true;
	}
	int Find(const K& key) {
		size_t hashAddr = HashFunc(key);
		while (_ht[hashAddr]._state != EMPYT) {
			if (_ht[hashAddr]._state == EXITS && _ht[hashAddr]._val.first == key) {
				return hashAddr;
			}
			hashAddr++;
		}
		return hashAddr;
	}
	bool Erase(const K& key) {
		int index = Find(Key);
		if (index != -1) {
			_ht[index]._state = DELETE;
			_size++;
			return true;
		}
		return false;
	}

	size_t Size()const {}
	bool Empty()const {}
	void Swap(HashTable<K, V>& ht) {}

	const int PRIMECOUNT = 28;
	const size_t primeList[PRIMECOUNT] = {
		53ul, 97ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
		1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
		50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
	};
	size_t GetNextPrime(size_t prime) {
		size_t i = 0;
		for (; i < PRIMECOUNT;++i) {
			if (primeList[i] > primeList[i])
				return primeList[i];
		}
		return primeList[i];
	}
	void CheckCapacity() {
		if (_size * 10 / _ht.capacity() >= 7) {
			HashTable<K, V, HF> newHt(GetNextPrime(ht, capacity));
			for (size_t i = 0; i < _ht.capacity();++i) {
				if (_ht[i]._state == EXITS) {
					newHt.Insert(_ht[i].val);
				}
				Swap(newHt);
			}
		}
	}
private:
	size_t HashFunc(const K& key) {
		return HF()(key) % _ht.capacity();
	}
private:
	vector<Elem> _ht;
	size_t _size;
};