#include<iostream>
#include<list>
#include<vector>
using namespace std;

void MakeListTest() {
	list<int> l1;
	list<int> l2(4,100);
	list<int> l3(l2.begin(),l2.end());
	list<int> l4(l3);


	//以数组为迭代器区间构造l5
	int array[] = {9, 5, 2, 7};
	list<int> l5(array,array+sizeof(array)/sizeof(int));

	//使用迭代器的当时打印l5
	for (list<int>::iterator it = l5.begin(); it != l5.end();++it) {
		cout << *it << " ";
	}
	cout << endl;

	for (auto x : l5)
		cout << x << " ";
	cout << endl;
}
void IteratorListTest() {
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> ll(array, array + sizeof(array) / sizeof(int));

	//正向迭代器
	for (list<int>::iterator it = ll.begin(); it != ll.end();++it) {
		cout << *it << " ";
	}
	cout << endl;
	//反向迭代器
	for (list<int>::reverse_iterator it = ll.rbegin(); it != ll.rend();++it) {
		cout << *it << " ";
	}
	cout << endl;
	//const 正向迭代器(C++11)
	auto cit = ll.cbegin();
	cout << typeid(cit).name() << endl;
	//const 反向迭代器(C++11)
	auto crit = ll.crbegin();
	cout << typeid(crit).name() << endl;
}
void ListCapacityTest() {
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> ll(array, array + sizeof(array) / sizeof(int));

	//打印list 中有效节点的个数
	cout << ll.size() << endl;

	//检测list 是否为空
	if (ll.empty())
		cout << "empty()" << endl;
	else
		for (auto a : ll)
			cout << a << " ";
		cout << endl;
}
void ListElementAccessTest() {
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> ll(array, array + sizeof(array) / sizeof(int));

	for (auto a : ll)
		cout << a << " ";
	cout << endl;

	//将list 中的第一个节点的值 和 最后一个节点的值 改为 20；
	ll.front() = 20;
	ll.back() = 20;

	for (auto a : ll)
		cout << a << " ";
	cout << endl;

	const list<int> ll2(array,array+sizeof(array)/sizeof(int));
	const int& ca = ll2.front();

}
void ListIteratorError() {
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> ll(array, array + sizeof(array) / sizeof(int));

	auto it = ll.begin();
	while (it != ll.end()) {
		//erase()执行后，it 所指向的节点已经删除，因此 it 无效，在下一次使用 it 时，必须先给其赋值
		ll.erase(it);
		++it;
	}
}
void Print(list<int>& l) {
	for (auto a : l)
		cout << a << " ";
	cout << endl;
}

class Date {
public:
	Date(int year = 1900, int mouth = 1, int day = 1)
		:_year(year)
		, _mouth(mouth)
		, _day(day)
	{
		cout << "Date(int,int,int):" << this << endl;
	}
	Date(const Date& d)
		:_year(d._year)
		, _mouth(d._mouth)
		, _day(d._day)
	{
		cout << "Date(const Date&):" << this << endl;
	}
	~Date() {

	}
private:
	int _year;
	int _mouth;
	int _day;
};
void ListModifiersTest() {
	int array1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> L(array1, array1 + sizeof(array1) / sizeof(int));

	// push_front / pop_front / push_back / pop_back
	L.push_front(6);
	L.push_back(6);
	Print(L);

	L.pop_front();
	L.pop_back();
	Print(L);

	//emplace_back / emplace_front / empalce
	list<Date> l;
	Date d(2018, 1, 1);
	l.push_back(d);
	l.emplace_back(2012, 12, 12);
	l.emplace_front(2019, 12, 12);

	//insert / erase
	int array[] = { 1, 2, 3};
	list<int> L1(array, array + sizeof(array) / sizeof(int));
	//获取链表的第二个结点
	auto pos = ++L1.begin();
	cout << *pos << endl;
	//在pos的前面插入4
	L1.insert(pos, 4);
	Print(L1);
	//在pos的前插入4个5
	L1.insert(pos, 4, 5);
	Print(L1);
	//在pos前面插入[v.begin(),v.end())区间中的的元素
	vector<int> v{9,5,2,7};
	L1.insert(pos, v.begin(), v.end());
	Print(L1);


	//删除pos位置的元素
	L1.erase(pos);
	Print(L1);
	//删除list 中[begin,end)区间的中的所有元素
	L1.erase(L1.begin(), L1.end());
	Print(L1);



}

void Test() {
	int array[] = { 1, 2, 3 };
	list<int> L(array, array + sizeof(array) / sizeof(int));
	Print(L);
	
	//L的元素增加为10个，多余的默认值填充
	L.resize(10);
	Print(L);
	//L的元素增加为20个，多余的用1填充
	L.resize(20, 1);
	Print(L);
	//L的元素减少到5个
	L.resize(5);
	Print(L);
	//用vector中的元素来构造list
	vector<int> v{ 9,5,2,7 };
	list<int> ll(v.begin(), v.end());
	Print(ll);
	//交换L和ll
	L.swap(ll);
	Print(L);
	Print(ll);
	//清空ll
	Print(ll);

}


int main() {
	//MakeListTest();
	//IteratorListTest();
	//ListCapacityTest();
	//ListElementAccessTest();
	//ListIteratorError();
	//ListModifiersTest();
	//Test();
	return 0;
}