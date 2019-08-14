#include<iostream>
#include<vector>
using namespace std;

void VecTest() {

	vector<int> first;
	vector<int> second(4, 100);
	vector<int> third(second.begin(), second.end());
	vector<int> fourth(third);

}
//迭代器
void IteratorTest() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	////使用const 迭代器遍历打印
	//vector<int>::const_iterator it = v.cbegin();
	//while (it != v.cend()) {
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

	//使用迭代器遍历打印
	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//用反向迭代器先遍历再打印
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}
void ConstTest(const vector<int>& v) {

	vector<int>::const_iterator cit = v.cbegin();
	while (cit != v.cend()) {
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
}
void SizeTest() {

	vector<int> v;
	size_t s = v.capacity();
	cout << s << endl;
	for (int i = 0; i < 100; ++i) {
		v.push_back(i);
		if (s != v.capacity()) {
			s = v.capacity();
			cout << "capacity is changed!" << s << endl;
		}
	}
}

void ReserveTest() {
	vector<int> v;
	size_t s = v.capacity();
	cout << s << endl;
	cout << v.size() << endl;
	v.reserve(100);
	s = v.capacity();
	cout << s << endl;
	cout << v.size() << endl;
}

void ZSCGTest() {

}



/*OJ
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。
找出那个只出现了一次的元素。
*/

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int i = 0, j = i + 1;
		while (nums.size() != 1 && j < nums.size()) {
			if (nums[i] == nums[j]) {
				nums.erase(nums.begin() + j);
				nums.erase(nums.begin());
				j = i + 1;
			}
			j += 1;
		}
		return nums[0];
	}
};


int main() {
	/*vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	ConstTest(v);*/
	//SizeTest();
	//ReserveTest();
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(1);
	v.push_back(-1);
	v.push_back(3);
	cout << singleNumber(v) << endl;


	return 0;
}