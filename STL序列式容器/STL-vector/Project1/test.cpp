#include<iostream>
#include<vector>
using namespace std;

void VecTest() {

	vector<int> first;
	vector<int> second(4, 100);
	vector<int> third(second.begin(), second.end());
	vector<int> fourth(third);

}
//������
void IteratorTest() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	////ʹ��const ������������ӡ
	//vector<int>::const_iterator it = v.cbegin();
	//while (it != v.cend()) {
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

	//ʹ�õ�����������ӡ
	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//�÷���������ȱ����ٴ�ӡ
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



/*OJ
����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ�
�ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
*/
#if 0
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
#endif
//iterator nused
#include<algorithm>

void NusedTest1() {
	int a[] = { 1,2,3,4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	//��find����3����λ�õ�iterator
	vector<int>::iterator pos = find(v.begin(), v.end(),3);
	//ɾ��posλ�õ���
	v.erase(pos);
	
	cout << *pos << endl;
	
	pos = find(v.begin(), v.end(), 3);
	v.insert(pos,30);
	cout << *pos << endl;
}
//������iteratorʧЧ���
void UnTest() {
	int a[] = { 1,2,3,4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	vector<int>::iterator it = v.begin();

	//����
	while (it != v.end()) {
		if (*it % 2 == 0)
			v.erase(it);
		++it;
	}
	//�Ľ�
	while (it != v.end()) {
		if (*it % 2 == 0)
			v.erase(it);
		else
			++it;
	}
}
#include"MyVector.hpp"
using namespace My;
void TestMyVector() {
	//���캯��
	Vector<int> first;
	Vector<int> second(4, 100);
	//��������
	Vector<int> third(second.Begin(), second.End());
	Vector<int> fourth(third);


}


int main() {
	/*vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	ConstTest(v);*/
	//SizeTest();
	//ReserveTest();
	/*vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(1);
	v.push_back(-1);
	v.push_back(3);*/

	//NusedTest1();
	//UnTest();
	TestMyVector();
	return 0;
}