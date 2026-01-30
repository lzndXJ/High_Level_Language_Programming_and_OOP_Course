//2452654 郭炫君 电信
#include <iostream>
using namespace std;

bool validate(char password[], int len, int min_upper, int min_lower, int min_number, int min_others)
{
	const char other[] = "!@#$%^&*-_=+,.?";
	int upper = 0, lower = 0, number = 0, others = 0;

	for (int i = 0; i < len; i += 1) {
		char c = password[i];
		if (c >= 'A' && c <= 'Z') {
			upper++;
		}
		else if (c >= 'a' && c <= 'z') {
			lower++;
		}
		else if (c >= '0' && c <= '9') {
			number++;
		}
		else {
			bool found = false;
			for (int j = 0; j < 15; j += 1) {
				if (c == other[j]) {
					found = true;
					break;
				}
			}
			if (found) {
				others += 1;
			}
			else {
				return false;
			}
		}
	}
	return (upper >= min_upper) && (lower >= min_lower) &&
		(number >= min_number) && (others >= min_others);
}

int main()
{
	cin.ignore(INT_MAX, '\n');//忽略首行
	int len, min_upper, min_lower, min_number, min_others;
	cin >> len >> min_upper >> min_lower >> min_number >> min_others;

	bool judge = true;
	char password[17];

	for (int i = 0; i < 10; i += 1) {
		cin >> password;
		if (!validate(password, len, min_upper, min_lower, min_number, min_others)){
			judge = false;
		}
	}

	cout << (judge ? "正确" : "错误") << endl;
	return 0;
}