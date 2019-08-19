#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace My {
	template<class T>
	class Vector {
	public:
		//Vector的迭代器是一个原生指针
		typedef T* Iterator;
		typedef const T* ConstIterator;
		Vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}
		Vector(int n, const Vector& value = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			Reserve(n);
			while (n--) {
				PushBack(value);
			}
		}
		Vector<T>& operator=(Vector<T> v) {
			Swap(v);
			return *this;
		}
		~Vector() {
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
		void Reserve(size_t n) {
			if (n > Capacity()) {
				size_t size = Size();
				T* tmp = new T[n];
				if (_start) {
					for (size_t i = 0; i < size; ++i)
						tmp[i] = _start[i];
				}
				_start = tmp;
				_finish = _start + size;
				_endOfStorage = _start + n;
			}
		}
		void Resize(size_t n, const T & value = T()) {
			//如果n小于当前的size，则把数据个数缩小到n
			if (n <= Size()) {
				_finish = _start + n;
				return;
			}
			//如果空间不够
			if (n > Capacity()) {
				Reserve(n);
			}
			//将size扩大到n
			Iterator it = _finish;
			Iterator _finish = _start + n;
			while (it != _finish) {
				*it = value;
				++it;
			}
		}
		void PushBack(const T& x) {
			Insert(End(), x);
		}
		void PopBack() {
			Erase(--End());
		}
		void Swap(Vector<T>& v) {
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}
		Iterator Insert(Iterator pos,const T& x) {
			assert(pos <= _finish);
			//如果空间不够
			if (_finish == _endOfStorage) {
				size_t size = Size();
				size_t newCapacity = Capacity() == 0 ? 1 : Capacity() * 2;
				Reserve(newCapacity);
				//重置pos
				pos = _start + size;
			}
			Iterator end = _finish - 1;
			while (end >= pos) {
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		Iterator Erase(Iterator pos) {
			//挪动数据进行删除
			Iterator begin = pos + 1;
			while (begin != _finish) {
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			return pos;
		}
		T& operator[](size_t pos) {
			return _start[pos];
		}
		template<class InputIterator>
		Vector(InputIterator first,InputIterator last) {
			Reserve(last - first);
			while (first!=last) {
				PushBack(*first);
				++first;
			}
		}
		Vector(const Vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			Reserve(v.Capacity());
			Iterator it = Begin();
			ConstIterator vit = v.CBegin();
			while (vit != v.CEnd()) {
				*it++ = *vit++;
			}
			_finish = _start + v.Size();
			_endOfStorage = _start + v.Capacity();
		}
		Iterator Begin() {
			return _start;
		}
		Iterator End() {
			return _finish;
		}
		ConstIterator CBegin()const {
			return _start;
		}
		ConstIterator CEnd()const {
			return _finish;
		}
		size_t Size()const {
			return _finish - _start;
		}
		size_t Capacity()const {
			return _endOfStorage - _start;
		}
	private:
		Iterator _start;
		Iterator _finish;
		Iterator _endOfStorage;
	};
}