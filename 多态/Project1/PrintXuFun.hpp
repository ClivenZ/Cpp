#pragma once
#include"polymorphism.hpp"

typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTbale[]) {
	//一次取出虚表中的虚函数指针打印并调用
	cout << "functionList addr:" << vTbale << endl;
	for (int i = 0; vTbale[i] != nullptr; ++i) {
		printf("No.%d function addr:0X%x,->",i,vTbale[i]);
		VFPTR f = vTbale[i];
		f();
	}
	cout << endl;
}