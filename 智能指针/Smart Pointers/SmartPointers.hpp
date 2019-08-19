#pragma once

#include<iostream>
#include<vector>
#include<memory>
#include<mutex>
using namespace std;

#if 0
template<class T>
class SmartPtr {
public:
	SmartPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}
	~SmartPtr() {
		if (_ptr) {
			delete _ptr;
		}
	}
	T& operator*() {
		return *_ptr;
	}
	T* operator->() {
		return _ptr;
	}
private:
	T* _ptr;
};
void MergeSort(int* a,int n) {
	int* tmp = (int*)malloc(sizeof(int)*n);

	SmartPtr<int> sp(tmp);

	vector<int> v(1000000, 10);

}
struct Date {
	int _year;
	int _mouth;
	int _day;
};
void Test() {
	//try {
	//	int a[5] = { 4,5,2,3,1 };
	//	MergeSort(a, 5);
	//}
	////exception C++异常类
	//catch (const exception& e) {
	//	cout << e.what() << endl;
	//}

	SmartPtr<int> sp1(new int);
	*sp1 = 10;
	cout << *sp1 << endl;
	
	SmartPtr<int> sparray(new Date);

	sparray->_year = 2018;
	sparray->_mouth = 1;
	sparray->_day = 1;

}
#endif


#if 0
class Date {
public:
	Date() {
		cout << "Date()" << endl;
	}
	~Date() {
		cout << "~Date()" << endl;
	}
	
	int _year;
	int _mouth;
	int _day;
};

void Test() {
	auto_ptr<Date> ap(new Date);
	auto_ptr<Date> copy(ap);
	ap->_year = 2018;
}
#endif
#if 0
//模拟实现auto_ptr
template<class T>
class AutoPtr {
public:
	AutoPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}
	~AutoPtr() {
		if (_ptr) {
			delete _ptr;
		}
	}
	AutoPtr(AutoPtr<T>& ap) 
		:_ptr(ap._ptr)
	{
		ap._ptr = NULL;
	}
	AutoPtr<T> operator=(AutoPtr<T>& ap) {
		if (this != &ap) {
			delete _ptr;
			if (_ptr) {
				delete _ptr;
			}
			_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		return *this;
	}
	T& operator*() {
		return *_ptr;
	}
	T* operator->() {
		return _ptr;
	}
private:
	T* _ptr;
};
struct Date {
	int _year;
	int _mouth;
	int _day;
};

template<class T>
class UniquePtr {
public:
	UniquePtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}
	~UniquePtr() {
		if (_ptr) {
			delete _ptr;
		}
	}
	T& operator*() {
		return *_ptr;
	}
	T* operator->() {
		return _ptr;
	}
private:
	//C++98，只(私有)声明不实现
	/*UniquePtr(UniquePtr<T> const&);
	UniquePtr& operator=(UniquePtr<T> const&);*/

	//C++11，防拷贝 delete
	UniquePtr(UniquePtr<T> const&) = delete;
	UniquePtr& operator=(UniquePtr<T> const&) = delete;
private:
	T* _ptr;
};




template<class T>
class SharedPtr {
public:
	SharedPtr(T* ptr = nullptr)
		:_ptr(ptr)
		,_pRefCount(new int(1))
		,_pMutex(new mutex)
	{}
	~SharedPtr() {
		Release();
	}
	SharedPtr(const SharedPtr<T>& sp) 
		:_ptr(sp._ptr)
		,_pRefCount(sp._pRefCount)
		,_pMutex(sp._pMutex)
	{
		AddRefCount();
	}
	SharedPtr<T>& operator=(const SharedPtr<T>& sp) {
		if (_ptr != sp._ptr) {
			Release();

			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;

			AddRefCount();
		}
		return *this;
	}
	T& operator*() {
		return *_ptr;
	}
	T* operator->() {
		return _ptr;
	}
	int UseCount() {
		return *_pRefCount;
	}
	T* Get() {
		return _ptr;
	}
	void AddRefCount() {
		//加锁或者使用加1原子操作
		_pMutex->lock();
		++(*_pRefCount);
		_pMutex->unlock();
	}
private:
	void Release() {
		bool deleteflag = false;
		//引用计数-1,如果减到0，则释放资源
		_pMutex->lock();
		if (--(*_pRefCount) == 0) {
			delete _ptr;
			delete _pRefCount;
			deleteflag = true;
		}
		_pMutex->unlock();

		if (deleteflag == true) {
			delete _pMutex;
		}
	}
private:
	T* _ptr;
	int* _pRefCount; //引用计数
	mutex* _pMutex;	 //互斥锁
};

void Test() {
	/*AutoPtr<Date> ap(new Date);
	AutoPtr<Date> copy(ap);
	ap->_year = 2018;*/

	SharedPtr<int> sp1(new int(10));
	SharedPtr<int> sp2(sp1);
	*sp2 = 20;
	cout << sp1.UseCount() << endl;
	cout << "&sp1 = " << &sp1 << endl;
	cout << sp2.UseCount() << endl;
	cout << "&sp2 = " << &sp2 << endl;

	SharedPtr<int> sp3(new int(10));
	sp2 = sp3;
	cout << sp1.UseCount() << endl;
	cout << "&sp1 = " << &sp1 << endl;
	cout << sp2.UseCount() << endl;
	cout << "&sp1 = " << &sp2 << endl;
	cout << sp3.UseCount() << endl;
	cout << "&sp1 = " << &sp3 << endl;

	sp1 = sp3;
	cout << sp1.UseCount() << endl;
	cout << "&sp1 = " << &sp1 << endl;
	cout << sp2.UseCount() << endl;
	cout << "&sp1 = " << &sp1 << endl;
	cout << sp3.UseCount() << endl;
	cout << "&sp1 = " << &sp1 << endl;

}
#endif

#if 0
struct ListNode {
	int _data;
	shared_ptr<ListNode> _prev;
	shared_ptr<ListNode> _next;

	~ListNode() {
		cout << "~ListNode()" << endl;
	}
};

void Test() {
	shared_ptr<ListNode> node1(new ListNode);
	shared_ptr<ListNode> node2(new ListNode);
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;


	node1->_next = node2;
	node2->_prev = node1;

	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;
}
#endif

#if 0
template<class T>
struct FreeFunc {
	void operator()(T* ptr) {
		cout << "free:" << ptr << endl;
		free(ptr);
	}
};
template<class T>
struct DeleteArrayFunc {
	void operator()(T* ptr) {
		cout << "delete[]" << ptr << endl;
		delete[] ptr;
	}
};

void Test() {
	FreeFunc<int> freeFunc;
	shared_ptr<int> sp1((int*)malloc(4),freeFunc);

	DeleteArrayFunc<int> deleteArrayFunc;
	shared_ptr<int> sp2((int*)malloc(4), deleteArrayFunc);

}
#endif


#include<thread>

template<class Mutex>
class LockGuard {
public:
	LockGuard(Mutex& mtx)
		:_mutex(mtx)
	{}
	~LockGuard() {
		_mutex.unlock();
	}
	LockGuard(const LockGuard<Mutex>&) = delete;
private:
	Mutex& _mutex;
};
mutex mtx;
static int n = 0;
void FunC() {
	for (size_t i = 0; i < 1000000;++i) {
		LockGuard<mutex> lock(mtx);
		++n;
	}
}
void Test() {
	int begin = clock();
	thread t1(FunC);
	thread t2(FunC);

	t1.join();
	t2.join();

	int end = clock();


	cout << n << endl;
	cout << "const time" << end - begin << endl;

}
















