//2452654 郭炫君 电信
#include <iostream>
#include <limits> 

using namespace std;

int main() {
	int y, m, d;
	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : " ;
		cin >> y >> m;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入非法，请重新输入" << endl;
		}
		else if (y > 2000 && y < 2030 && m >= 1 && m <= 12) 
			break;
		else
			cout << "输入非法，请重新输入" << endl;	
	}
	while (1) {
		cout << "请输入"<<y<<"年"<<m<<"月1日的星期(0-6表示星期日-星期六) : " ;
		cin >> d;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入非法，请重新输入" << endl;
		}
		else if (d>=0 && d<=6) 
			break;
		else
			cout << "输入非法，请重新输入" << endl;	
	}
	int monthdays;
	bool runnian = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
	if (m == 2)
		monthdays = runnian ? 29 : 28;
	else if (m == 4 || m == 6 || m == 9 || m == 11)
		monthdays = 30;
	else
		monthdays = 31;
	cout << endl;
	cout << y << "年" << m << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	for (int i = 0; i < d; i++) {
		cout << "        ";
	}
	int nowdays = 1;
	int weekdays = d;
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
	cout << endl;
	return 0;
}