#include<iostream>
#include<list>

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

int main() {
	MakeListTest();
	return 0;
}