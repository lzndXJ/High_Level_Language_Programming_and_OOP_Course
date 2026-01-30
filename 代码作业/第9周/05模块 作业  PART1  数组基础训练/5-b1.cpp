//2452654 郭炫君 电信
#include <iostream>
using namespace std;
int main()
{
	const int maxsize = 20;
	int array[maxsize + 1];
	int count = 0;
	int num;
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	while (count < maxsize) {
		cin >> num;
		if (num <= 0)
			break;
		array[count] = num;
		count += 1;
	}

	if (count == 0) {
		cout << "无有效输入" << endl;
		return 0;
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	cout << "原数组为：" << endl;
	for (int i = 0; i < count; i += 1) {
		cout << array[i] << " ";
	}
	cout << endl;

	cout << "请输入要插入的正整数" << endl;
	int insertnum;
	cin >> insertnum;
	int pos = 0;
	while (pos < count && array[pos] < insertnum) {
		pos += 1;
	}
	for (int i = count; i > pos; i -= 1) {
		array[i] = array[i - 1];
	}
	array[pos] = insertnum;
	count += 1;

	cout << "插入后的数组为：" << endl;
	for (int i = 0; i < count; i += 1) {
		cout << array[i] << " ";
	}
	cout << endl;

	return 0;
}