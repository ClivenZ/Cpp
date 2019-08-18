#pragma once
#include<cstdio>
#include<cstdlib>

#if 0
int globalVar = 1;
static int staticGlobalVar = 1;
void Test() {
	static int staticVar = 1;
	int localVar = 1;

	int num1[10] = { 1, 2, 3, 4 };
	char char2[] = "abcd";
	char* pChar3 = "abcd";
	int* ptr1 = (int*)malloc(sizeof(int) * 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
	
	free(ptr1);
	free(ptr3);
}
#endif
#if 0
void Test() {
	int* ptr1 = (int*)malloc(sizeof(int));
	free(ptr1);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 10);

	free(ptr3);
}
#endif