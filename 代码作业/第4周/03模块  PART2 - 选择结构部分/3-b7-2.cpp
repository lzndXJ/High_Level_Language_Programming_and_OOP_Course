//2452654 郭炫君 电信
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "请输入找零值：" << endl;
	int y50 = 0, y20 = 0, y10 = 0, y5 = 0, y1 = 0, j5 = 0, j1 = 0, f5 = 0, f2 = 0, f1 = 0;
	double number;
	cin >> number;
	if (number > 100 || number < 0.01) {
		cout << "输入错误，请重新输入" << endl;
	}
	else {
		int total = static_cast<int>(round(number * 100));

		if (total >= 5000) {
			y50 = total / 5000;
			total %= 5000;
		}
		if (total >= 2000) {
			y20 = total / 2000;
			total %= 2000;
		}
		if (total >= 1000) {
			y10 = total / 1000;
			total %= 1000;
		}
		if (total >= 500) {
			y5 = total / 500;
			total %= 500;
		}
		if (total >= 100) {
			y1 = total / 100;
			total %= 100;
		}
		if (total >= 50) {
			j5 = total / 50;
			total %= 50;
		}
		if (total >= 10) {
			j1 = total / 10;
			total %= 10;
		}
		if (total >= 5) {
			f5 = total / 5;
			total %= 5;
		}
		if (total >= 2) {
			f2 = total / 2;
			total %= 2;
		}
		if (total >= 1) {
			f1 = total / 1;
			total %= 1;
		}
		int count = y50 + y20 + y10 + y5 + y1 + j5 + j1 + f5 + f2 + f1;
		cout << "共" << count << "张找零，具体如下：" << endl;
		if (y50 > 0)
			cout << "50元 : " << y50 << "张" << endl;
		if (y20 > 0)
			cout << "20元 : " << y20 << "张" << endl;
		if (y10 > 0)
			cout << "10元 : " << y10 << "张" << endl;
		if (y5 > 0)
			cout << "5元  : " << y5 << "张" << endl;
		if (y1 > 0)
			cout << "1元  : " << y1 << "张" << endl;
		if (j5 > 0)
			cout << "5角  : " << j5 << "张" << endl;
		if (j1 > 0)
			cout << "1角  : " << j1 << "张" << endl;
		if (f5 > 0)
			cout << "5分  : " << f5 << "张" << endl;
		if (f2 > 0)
			cout << "2分  : " << f2 << "张" << endl;
		if (f1 > 0)
			cout << "1分  : " << f1 << "张" << endl;
	}

	return 0;

}