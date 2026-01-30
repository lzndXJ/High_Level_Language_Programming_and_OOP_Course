//2452654 郭炫君 电信
#include <iostream>
#include <limits>
using namespace std;
int zeller(int y, int m)
{
	int c = y / 100;
	y %= 100;
	if (m == 1 || m == 2) {
		if (y == 0)
			c -= 1;
		m += 12;
		y = (y + 99) % 100;

	}
	int w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5;
	while (w < 0)
		w += 7;
	w = w % 7;
	return w;
}

void calendar(int year, int month)
{
	/* 按需添加代码 */
	int monthdays;
	bool runnian = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	if (month == 2)
		monthdays = runnian ? 29 : 28;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		monthdays = 30;
	else
		monthdays = 31;
	cout << endl;
	cout << year << "年" << month << "月" << endl;
	/* 头部分隔线，不算打表 */
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

	/* 按需添加代码 */
	int w = zeller(year, month);
	for (int i = 0; i < w; i++) {
		cout << "        ";
	}
	int nowdays = 1;
	int weekdays = w;
	while (nowdays <= monthdays) {
		if (nowdays < 10)
			cout << " ";
		cout << "  " << nowdays << "    ";
		weekdays += 1;
		if (weekdays > 6) {
			cout << endl;
			weekdays = 0;
		}
		nowdays += 1;
	}
	if (weekdays != 0)
		cout << endl;

	/* 尾部分隔线，不算打表 */
	cout << "======================================================" << endl;
}

int main()
{
	int y, m;
	while (1) {
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> y >> m;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入错误，请重新输入" << endl;
		}
		else if (y < 1900 || y>2100)
			cout << "年份不正确，请重新输入" << endl;
		else if (m < 1 || m>12)
			cout << "月份不正确，请重新输入" << endl;
		else
			break;
	}
	calendar(y, m);
	return 0;
}