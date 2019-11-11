#include<iostream>
#include<string>
using namespace std;

int Test(string& str1, string& str2) {
	int count = 0;
	int len1 = str1.size();
	int len2 = str2.size();
	int i = 0, j = 0;
	while (i < len1 && j < len2) {
		if (str1[i] == str2[i]) {
			++i;
			++j;
			continue;
		}
		if(str1[i] > )
	}
	return count;
}


int main() {
	
	return 0;
}