#include <iostream>
#include <cstdlib>

using namespace std;

#if 0
//�����ռ�Ķ���
namespace A {
	int Add(int left,int right) {
		return left + right;
	}
}
namespace B {
	int Add(int left,int right) {
		return left + right;
	}
}
//�����ռ��Ƕ��
namespace C {
	int Add(int left, int right) {
		return left + right;
	}
	namespace D {
		int Sub(int left,int right) {
			return left + right;
		}
	}
}
using namespace B;
using namespace std;

void TestFun1(int a = 10) {
	cout << a << endl;
}

//ȫȱʡ����
void TestFun2(int a = 1,int b = 2,int c = 3) {
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}
//��ȱʡ����
void TestFun2(int a, int b = 2, int c = 3) {
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}
#endif 

#if 0
//��������
int Add(int a,int b) {
	return a + b;
}
double Add(double a, double b) {
	return a + b;
}

short Sub(short a,short b) {
	return a + b;
}
int Sub(short a,short b) {
	return a + b;
}
#endif

#if 0
//����
void TestFun2() {
	int a = 10;
	int& ra = a;
	cout << a << endl;
	cout << ra << endl;
	cout << &a << endl;
	cout << &ra << endl;
}
//������
void TestFun() {
	const int a = 10;
	//int& ra = a;
	const int& ra = a;
}
//������Ϊ����
void Swap(int& a,int& b) {
	int temp = a;
	a = b;
	b = temp;
}
//������Ϊ����ֵ
int& TesrFun1(int& a) {
	a += 10;
	return a;
}
//����
int& Add(int a,int b) {
	int c = a + b;
	return c;
}
int main() {
	int& ret = Add(1,2);
	Add(3, 4);
	cout << ret << endl;
	system("pause");
	return 0;
}
#endif
#if 0
//auto
int Test() {
	return 10;
}

int main() {
	
	int a = 10;
	auto b = a;
	auto c = 'a';
	auto d = Test();
	
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	system("pause");
	return 0;
}
#endif

int main() {
	//����һ������
	int array[] = {1,2,3,4,5,6,7,8,9};
	for (auto e : array)
		cout << e << "";
	cout << endl;
	system("pause");
	return 0;
}



