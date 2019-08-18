#pragma once
#include<iostream>

using namespace std;

#if 0
void Test() {
	int* ptr1 = new int;

	int* ptr2 = new int(10);

	int* ptr3 = new int[3];

	delete ptr1;
	delete ptr2;
	delete[] ptr3;
}
#endif
#if 0
class TestT {
public:
	TestT()
		:_data(0)
	{
		cout << "TestT()" << endl;
	}
	~TestT() {
		cout << "~TestT()" << endl;
	}
private:
	int _data;
};
#endif
#if 0
void Test() {
	TestT* t1 = (TestT*)malloc(sizeof(TestT));
	free(t1);

	TestT* t2 = (TestT*)malloc(sizeof(TestT) * 10);
	free(t2);
}
#endif
#if 0
void Test() {
	TestT* t1 = new TestT;
	delete t1;

	TestT* t2 = new TestT[10];
	delete t2;
}
#endif
#if 0
void Test() {
	operator new();
	opr
}
#endif
#if 0

void* __CRTDECL operator new(size_t size) _THROW(_STD bad_alloc){
	void* p;
	while((p = malloc(size) == 0)
		if (_callnewh(size) == 0) {
			static const std::bad_alloc nomem;
			_RAISE(nomem);
		}
	return (p);
}
void operator delete(void* pUserData)
{
	_CrtMemBlockHeader* pHead;
	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
	if (pUserData == NULL)
		return;
		/* get a pointer to memory block header */
		pHead = pHdr(pUserData);
	/* verify block type */
	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
	_free_dbg(pUserData, pHead->nBlockUse);
	__FINALLY
		_munlock(_HEAP_LOCK); /* release other threads */
	__END_TRY_FINALLY
		return;
}
/*
free的实现
*/
#define free(p) _free_dbg(p, _NORMAL_BLOCK)
#endif
#if 1 
//定位 new 表达式
class TestT {
public:
	TestT()
		:_data(0)
	{
		cout << "TestT()" << endl;
	} 
	~TestT()
	{
		cout << "~TestT()" << endl;
	}
private:
	int _data;
};
void Test() {
	TestT* pt = (TestT*)malloc(sizeof(TestT));

	new(pt) TestT;
}
#endif


