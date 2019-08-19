#pragma once
#include<iostream>

using namespace std;
#if 0
double Division(int a,int b) {
	if (b == 0) {
		throw "Division by zero condition!";
	}
	else {
		return ((double)a / (double)b);
	}
}
void Func() {
	int len, time;
	cin >> len >> time;
	cout << Division(len, time) << endl;
}
void Test() {
	try {
		Func();
	}
	catch (const char* errmsg) {
		cout << errmsg << endl;
	}
	catch (...) {
		cout << "unknown exception" << endl;
	}
}
#endif

#if 1
double Division(int a, int b) {
	if (b == 0) {
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void FunC() {
	int* array = new int[10];
	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...) {
		cout << "delete[]" << array << endl;
		delete[] array;
		throw;
	}
	cout << "delete[]" << array << endl;
	delete[] array;
}
void Test() {
	try {
		FunC();
	}
	catch (const char* errmsg) {
		cout << errmsg << endl;
	}
}
#endif






