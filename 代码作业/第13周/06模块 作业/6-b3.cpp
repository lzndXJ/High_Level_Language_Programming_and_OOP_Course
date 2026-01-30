//2452654 郭炫君 电信
#include <iostream>
using namespace std;

unsigned int change(const char* array)
{
	unsigned int decimal = 0;
	const char* p = array;
	while (*p != '\0') {
		decimal = decimal * 2 + (*p - '0');
		p += 1;
	}
	return decimal;
}

int main()
{
	char array[33];
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin >> array;
	cout << change(array) << endl;

	return 0;
}