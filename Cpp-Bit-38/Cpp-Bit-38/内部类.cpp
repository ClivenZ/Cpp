#include <iostream>
#include <cstdlib>

using namespace std;

class A {
	// B �� A ���ڲ��࣬�൱�� B �� A ����Ԫ��
	class B {
	public:
		void DisPlay(A& a) {
			//�ⲿ�����ͨ˽�г�Աֻ��ͨ���ⲿ��������
			cout << a._a << endl;
			//�ⲿ��ľ�̬˽�г�Ա����ͨ���ⲿ�������ʣ�Ҳ����ֱ�ӷ���
			cout << _s << endl;
			cout << a._s << endl;
		}
	private:
		int _b;
	};
	void DisPlay() {
		//�ⲿ������ڲ���û���κεķ���Ȩ�ޣ����ܷ����ڲ����˽�г�Ա
		//cout << b._b << endl;
		
	}
private:
	int _a;
	static int _s;
};

int main() {

	system("pause");
	return 0;
}