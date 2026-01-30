//2452654 郭炫君 电信
#include <iostream>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int max(int a, int b, int c)
{
	return max(max(a, b), c);
}

int max(int a, int b, int c, int d)
{
	return max(max(a, b, c), d);
}

int main()
{
	int num;
	int a = 0, b = 0, c = 0, d = 0;
	while (1) {
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num;
		if (num < 2 || num > 4) {
			cout << "个数输入错误" << endl;
			return 0;
		}
		else if (cin.good() == 0) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else {
			if (num == 2) {
				cin >> a >> b;
				if (cin.good() == 0 || a<0 || b<0) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else {
					cout << "max=" << max(a, b) << endl;
					return 0;
				}
			}
			else if(num == 3) {
				cin >> a >> b >> c;
				if (cin.good() == 0 || a<0 || b<0 || c<0) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else {
					cout << "max=" << max(a, b, c) << endl;
					return 0;
				}
			}
			else {
				cin >> a >> b >> c >> d;
				if (cin.good() == 0 || a < 0 || b < 0 || c < 0 || d < 0) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else {
					cout << "max=" << max(a, b, c, d) << endl;
					return 0;
				}
			}
		}
	}


	return 0;
}