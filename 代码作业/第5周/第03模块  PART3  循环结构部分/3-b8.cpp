//2452654 郭炫君 电信
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{	
	bool tf = 0;
	int x = 0;
	while (tf == 0) {
		cout << "请输入x的值[-10 ~ +65]" << endl;
		cin >> x;
		if (x < -10 || x>65) {
			cout << "输入非法，请重新输入" << endl;
			tf = 0;
		}
		else
			tf = 1;
	}
	int n = 0;
	double sum = 0;
	double y = 1;
	while (fabs(y) >= 1e-6) {
		sum += y;
		n += 1;
		y = y * x / n;
		tf = 0;
	}
	cout << "e^"<< x << "=" << setprecision(10) << sum << endl;

	return 0;
}