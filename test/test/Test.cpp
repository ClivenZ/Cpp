#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<cstring>


using namespace std;

char* string_del_characters(char* const src, const char* const dest)
{
	int destLen = strlen(dest);
	int hash_table[256] = { 0 };
	char* p = src;
	int index = 0;
	for (int i = 0; i < destLen; i++)
	{
		hash_table[(int)dest[i]] = 1;
	}
	while (*p != '\0')
	{
		if (0 == hash_table[(int)* p])
		{
			src[index++] = *p;
		}
		p++;
	}
	src[index] = '\0';
	return src;
}

int main()
{
	char src[255];
	char dest[255];
	
	char* pResult = string_del_characters(src, dest);
	cout << pResult << endl;
	return 0;
}
