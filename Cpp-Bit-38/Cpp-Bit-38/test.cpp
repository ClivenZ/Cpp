#include <iostream>

using namespace std;

int& Add(int a, int b) {
	int c = a + b;
	return c;
}
int main() {
	int& ret = Add(1, 2);
	Add(3, 4);
	cout << "Add(1,2) is :" << ret << endl;
	printf("%d\n", sizeof(int*));
	system("pause");
	return 0;
}

