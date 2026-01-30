//2452654 郭炫君 电信
#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";

//根据参数随机生成一个字符
char rand_char(int type)
{
	switch (type) {
		case 0:
			return 'A' + rand() % 26;
		case 1:
			return 'a' + rand() % 26;
		case 2:
			return '0' + rand() % 10;
		case 3:
			return other[rand() % 15];
		default:
			return ' ';
	}
}

void rand_password(char password[], int len, int upper, int lower, int number, int other)
{
	int a = 0;

	for (int i = 0; i < upper; i += 1) {
		password[a++] = rand_char(0);
	}
	for (int i = 0; i < lower; i += 1) {
		password[a++] = rand_char(1);
	}
	for (int i = 0; i < number; i += 1) {
		password[a++] = rand_char(2);
	}
	for (int i = 0; i < other; i += 1) {
		password[a++] = rand_char(3);
	}

	while (a < len) {
		password[a++] = rand_char(rand() % 4);
	}

	//打乱排序
	for (int i = len - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		char temp = password[i];
		password[i] = password[j];
		password[j] = temp;
	}
	password[len] = '\0';
}

int main()
{
	srand((unsigned int)(time(0)));
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	//检查输入正确性
	int len, upper, lower, number, others;
	cin >> len >> upper >> lower >> number >> others;
	if (cin.fail()) {
		cout << "输入非法" << endl;
		return 0;
	}

	if (len < 12 || len>16) {
		cout << "密码长度[" << len << "]不正确" << endl;
		return 0;
	}

	if (upper<2 || upper>len) {
		cout << "大写字母个数[" << upper << "]不正确" << endl;
		return 0;
	}

	if(lower<2 || lower>len) {
		cout << "小写字母个数[" << lower << "]不正确" << endl;
		return 0;
	}

	if (number<2 || number>len) {
		cout << "数字个数[" << number << "]不正确" << endl;
		return 0;
	}

	if (others<2 || others>len) {
		cout << "其它符号个数[" << others << "]不正确" << endl;
		return 0;
	}

	if ((upper + lower + number + others) > len) {
		cout << "所有字符类型之和[" << upper << "+" << lower << "+" << number << "+" << others << "]大于总密码长度["<<len<<"]" << endl;
		return 0;
	}

	cout << len << " " << upper << " " << lower << " " << number << " " << others << endl;

	for (int i = 0; i < 10; i++) {
		char password[17];
		rand_password(password, len, upper, lower, number, others);
		cout << password << endl;
	}

	return 0;
}