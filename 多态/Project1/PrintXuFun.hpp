#pragma once
#include"polymorphism.hpp"

typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTbale[]) {
	//һ��ȡ������е��麯��ָ���ӡ������
	cout << "functionList addr:" << vTbale << endl;
	for (int i = 0; vTbale[i] != nullptr; ++i) {
		printf("No.%d function addr:0X%x,->",i,vTbale[i]);
		VFPTR f = vTbale[i];
		f();
	}
	cout << endl;
}