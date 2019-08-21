#include<iostream>
#include<deque>
#include<vector>
using namespace std;

void PrintDeque(const deque<int>& q) {
	for (auto x : q)
		cout << x << " ";
	cout << endl;
}
void MakeDequeTest() {
	deque<int> d1;
	deque<int> d2(5);
	deque<int> d3(5, 5);

	vector<int> v{ 9,5,2,7 };
	deque<int> d4(v.begin(),v.end());
	deque<int> d5(d4);

	PrintDeque(d1);
	PrintDeque(d2);
	PrintDeque(d3);
	PrintDeque(d4);
	PrintDeque(d5);
}
void DequeIteratorTest() {
	int array[] = { 1,2,3,4,5,6,7,8,9 };
	deque<int> d(array, array + sizeof(array) / sizeof(int));
	
	for (auto it = d.cbegin(); it != d.cend(); ++it) 
		cout << *it << " ";
	cout << endl;

	for (auto it = d.crbegin(); it != d.crend(); ++it)
		cout << *it << " ";
	cout << endl;
}
void Test() {
	deque<int> d1{ 3,4,5 };

	d1.push_back(6);
	d1.push_front(2);
	PrintDeque(d1);
	cout << d1.size() << endl;
	cout << d1.front() << endl;
	cout << d1.back() << endl;

	d1.emplace_back(7);
	d1.emplace_front(1);
	PrintDeque(d1);

	d1.insert(d1.begin(), 0);
	PrintDeque(d1);

	d1.pop_front();
	d1.pop_back();
	d1.erase(d1.begin());
	PrintDeque(d1);

	d1.clear();
	PrintDeque(d1);
}




int main() {
	//MakeDequeTest();
	//DequeIteratorTest();
	Test();
	return 0;
}