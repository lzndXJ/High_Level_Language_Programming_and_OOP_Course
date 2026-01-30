//2452654 郭炫君 电信
#include <iostream>
#include <limits>
using namespace std;
int zeller(int y, int m, int d)
{
	int c = y / 100;
	y %= 100;
	if (m == 1 || m == 2) {
		if (y == 0)
			c -= 1;
		m += 12;
		y = (y + 99) % 100;

	}
	int w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	while (w < 0)
		w += 7;
	w = w % 7;
	switch (w) {
		case 0:
			cout << "星期日" << endl;
			break;
		case 1:
			cout << "星期一" << endl;
			break;
		case 2:
			cout << "星期二" << endl;
			break;
		case 3:
			cout << "星期三" << endl;
			break;
		case 4:
			cout << "星期四" << endl;
			break;
		case 5:
			cout << "星期五" << endl;
			break;
		case 6:
			cout << "星期六" << endl;
			break;
	}

	return 0;
}
int main() {
	int y, m, d;
	while (1) {
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> y >> m >> d;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入错误，请重新输入" << endl;
		}
		else if (y < 1900 || y>2100)
			cout << "年份不正确，请重新输入" << endl;
		else if (m < 1 || m>12)
			cout << "月份不正确，请重新输入" << endl;
		else if (m == 2) {
			if ((y % 4 == 0 && y % 100 != 0) || y % 400==0) {
				if (d < 1 || d>29)
					cout << "日不正确，请重新输入" << endl;
				else
					break;
			}
			else {
				if (d < 1 || d>28)
					cout << "日不正确，请重新输入" << endl;
				else
					break;
			}
		}
		else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
			if (d < 1 || d>31)
				cout << "日不正确，请重新输入" << endl;
			else
				break;
		}
		else if (m == 4 || m == 6 || m == 9 || m == 11) {
			if (d < 1 || d>30)
				cout << "日不正确，请重新输入" << endl;
			else
				break;
		}
	}
	zeller(y, m, d);
	return 0;
}