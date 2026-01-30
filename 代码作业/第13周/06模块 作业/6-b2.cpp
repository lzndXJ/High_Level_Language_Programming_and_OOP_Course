//2452654 郭炫君 电信
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool judge(const char* str)
{
	const char* left = str;
	const char* right = str + strlen(str) - 1;

	while (left < right) {
		if (*left != *right) {
			return false;
		}
		left++;
		right--;
	}
	return true;
}
int main()
{
	char str[81];
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(str, 80, stdin);

	char* p = str;
	while (*p != '\0' && *p != '\n') {
		p++;
	}
	*p = '\0';

	cout << (judge(str)?"yes":"no") << endl;
	return 0;
}