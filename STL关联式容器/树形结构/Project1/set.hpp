#pragma once
#include"map.hpp"
#include<set>


void SetTest() {
	int array[] = {1,2,3,4,5,6,7,8,9,9,9,9,9,4,4,5,6,7,5};
	set<int> s(array, array + sizeof(array) / sizeof(int));
	cout << s.size() << endl;


	for (auto x : s)
		cout << x << " ";
	cout << endl;
	for (auto it = s.rbegin(); it != s.rend(); ++it)
		cout << *it << " ";
	cout << endl;

	cout << s.count(3) << endl;


}