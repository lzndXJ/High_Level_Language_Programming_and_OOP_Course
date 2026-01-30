//2452654 郭炫君 电信
#include <iostream>
using namespace std;

int main()
{
	char str[3][128];

	cout << "请输入第1行" << endl;
	cin.getline(str[0], 128);
	cout << "请输入第2行" << endl;
	cin.getline(str[1], 128);
	cout << "请输入第3行" << endl;
	cin.getline(str[2], 128);

	int upper = 0, lower = 0, number = 0, space = 0, other = 0;

	for (int i = 0; i < 3; i += 1) {
		for (int j = 0; str[i][j] != '\0'; j += 1) {
			char c = str[i][j];

			if (c >= 'A' && c <= 'Z')
				upper += 1;
			else if (c >= 'a' && c <= 'z')
				lower += 1;
			else if (c >= '0' && c <= '9')
				number += 1;
			else if (c == ' ')
				space += 1;
			else
				other += 1;
		}
	}

	cout << "大写 : " << upper << endl;
	cout << "小写 : " << lower << endl;
	cout << "数字 : " << number << endl;
	cout << "空格 : " << space << endl;
	cout << "其它 : " << other << endl;

	return 0;
}