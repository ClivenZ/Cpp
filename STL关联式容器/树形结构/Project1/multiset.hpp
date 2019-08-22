#pragma once
#include"map.hpp"
#include<set>

void MultisetTest() {
	int array[] = { 1,2,3,4,5,6,7,8,9,4,5,6 };

	multiset<int> s(array, array + sizeof(array) / sizeof(int));
	for (auto x : s)
		cout << x << " ";
	cout << endl;
}