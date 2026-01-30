//2452654 郭炫君 电信
#include <iostream>
using namespace std;
int main()
{
	int y, m, d;
	cout << "请输入年，月，日" << endl;
	cin >> y >> m >> d;
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
		switch (m) {
			case 1:
				if (d < 1 || d>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
					<< d << "天" << endl;
				break;
			case 2:
				if (d < 1 || d>29)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
					<< d + 31 << "天" << endl;
				break;
			case 3:
				if (d < 1 || d>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
					<< d + 60 << "天" << endl;
				break;
			case 4:
				if (d < 1 || d>30)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
					<< d + 91 << "天" << endl;
				break;
			case 5:
				if (d < 1 || d>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
					<< d + 121 << "天" << endl;
				break;
			case 6:
				if (d < 1 || d>30)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
					<< d + 152 << "天" << endl;
				break;
			case 7:
				if (d < 1 || d>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
					<< d + 182 << "天" << endl;
				break;
			case 8:
				if (d < 1 || d>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
					<< d + 213 << "天" << endl;
				break;
			case 9:
				if (d < 1 || d>30)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
					<< d + 244 << "天" << endl;
				break;
			case 10:
				if (d < 1 || d>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
					<< d + 274 << "天" << endl;
				break;
			case 11:
				if (d < 1 || d>30)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
					<< d + 305 << "天" << endl;
				break;
			case 12:
				if (d < 1 || d>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
					<< d + 335 << "天" << endl;
				break;
			default:
				cout << "输入错误-月份不正确" << endl;
				break;

		}
	}
	else {
		switch (m) {
			case 1:
				if (d < 1 || d>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
							<< d << "天" << endl;
				break;
			case 2:
				if (d < 1 || d>28)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
							<< d + 31 << "天" << endl;
				break;
			case 3:
				if (d < 1 || d>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
							<< d + 59 << "天" << endl;
				break;
			case 4:
				if (d < 1 || d>30)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
							<< d + 90 << "天" << endl;
				break;
			case 5:
				if (d < 1 || d>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
							<< d + 120 << "天" << endl;
				break;
			case 6:
				if (d < 1 || d>30)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
							<< d + 151 << "天" << endl;
				break;
			case 7:
				if (d < 1 || d>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
							<< d + 181 << "天" << endl;
				break;
			case 8:
				if (d < 1 || d>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
							<< d + 212 << "天" << endl;
				break;
			case 9:
				if (d < 1 || d>30)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
							<< d + 243 << "天" << endl;
				break;
			case 10:
				if (d < 1 || d>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
							<< d + 273 << "天" << endl;
				break;
			case 11:
				if (d < 1 || d>30)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
							<< d + 304 << "天" << endl;
				break;
			case 12:
				if (d < 1 || d>31)
					cout << "输入错误-日与月的关系非法" << endl;
				else
					cout << y << "-" << m << "-" << d << "是" << y << "年的第"
							<< d + 334 << "天" << endl;
				break;
			default:
				cout << "输入错误-月份不正确" << endl;
				break;

		}
	}

	return 0;
}