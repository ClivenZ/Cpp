#include<iostream>
#include<list>
#include<vector>
using namespace std;

void MakeListTest() {
	list<int> l1;
	list<int> l2(4,100);
	list<int> l3(l2.begin(),l2.end());
	list<int> l4(l3);


	//������Ϊ���������乹��l5
	int array[] = {9, 5, 2, 7};
	list<int> l5(array,array+sizeof(array)/sizeof(int));

	//ʹ�õ������ĵ�ʱ��ӡl5
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

	//���������
	for (list<int>::iterator it = ll.begin(); it != ll.end();++it) {
		cout << *it << " ";
	}
	cout << endl;
	//���������
	for (list<int>::reverse_iterator it = ll.rbegin(); it != ll.rend();++it) {
		cout << *it << " ";
	}
	cout << endl;
	//const ���������(C++11)
	auto cit = ll.cbegin();
	cout << typeid(cit).name() << endl;
	//const ���������(C++11)
	auto crit = ll.crbegin();
	cout << typeid(crit).name() << endl;
}
void ListCapacityTest() {
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> ll(array, array + sizeof(array) / sizeof(int));

	//��ӡlist ����Ч�ڵ�ĸ���
	cout << ll.size() << endl;

	//���list �Ƿ�Ϊ��
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

	//��list �еĵ�һ���ڵ��ֵ �� ���һ���ڵ��ֵ ��Ϊ 20��
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
		//erase()ִ�к�it ��ָ��Ľڵ��Ѿ�ɾ������� it ��Ч������һ��ʹ�� it ʱ�������ȸ��丳ֵ
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
	//��ȡ����ĵڶ������
	auto pos = ++L1.begin();
	cout << *pos << endl;
	//��pos��ǰ�����4
	L1.insert(pos, 4);
	Print(L1);
	//��pos��ǰ����4��5
	L1.insert(pos, 4, 5);
	Print(L1);
	//��posǰ�����[v.begin(),v.end())�����еĵ�Ԫ��
	vector<int> v{9,5,2,7};
	L1.insert(pos, v.begin(), v.end());
	Print(L1);


	//ɾ��posλ�õ�Ԫ��
	L1.erase(pos);
	Print(L1);
	//ɾ��list ��[begin,end)������е�����Ԫ��
	L1.erase(L1.begin(), L1.end());
	Print(L1);



}

void Test() {
	int array[] = { 1, 2, 3 };
	list<int> L(array, array + sizeof(array) / sizeof(int));
	Print(L);
	
	//L��Ԫ������Ϊ10���������Ĭ��ֵ���
	L.resize(10);
	Print(L);
	//L��Ԫ������Ϊ20�����������1���
	L.resize(20, 1);
	Print(L);
	//L��Ԫ�ؼ��ٵ�5��
	L.resize(5);
	Print(L);
	//��vector�е�Ԫ��������list
	vector<int> v{ 9,5,2,7 };
	list<int> ll(v.begin(), v.end());
	Print(ll);
	//����L��ll
	L.swap(ll);
	Print(L);
	Print(ll);
	//���ll
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