//2452654 郭炫君 电信
#include <iostream>
#include <iomanip>
using namespace std;

//蔡勒公式
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

//获取每个月的天数
int day_in_month(int year, int month)
{
	const int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 29;
	return daysPerMonth[month - 1];
}

//打印年历
void printcalendar(int year, int perline)
{
	//打印标题
	cout << year << "年的日历:" << endl << endl;;

	//按指定行数打印
	for (int startmonth = 1; startmonth <= 12; startmonth += perline) {
		//打印月份标题
		for (int m = startmonth; m < startmonth + perline && m <=12; m++) {
			cout << resetiosflags(ios::left);      //月份格式特殊需求
			cout << "           " << setw(2)<<m << "月            ";
			cout << "     ";
		}
		cout << endl;

		//打印星期标题
		for (int m = startmonth; m < startmonth + perline && m <=12; m++) {
			cout << "Sun Mon Tue Wed Thu Fri Sat     ";
		}
		cout << endl;

		//计算这组月份最大行数
		int maxline = 0;
		for (int m = startmonth; m < startmonth + perline && m <= 12; m++) {
			int firstday = zeller(year, m);
			int days = day_in_month(year, m);
			int line = (days + firstday + 6) / 7;
			if (line > maxline)
				maxline = line;
		}

		//按行打印日历
		for (int line = 0; line < maxline; line += 1) {
			for (int m = startmonth; m < startmonth + perline && m <= 12; m += 1) {
				int firstday = zeller(year, m);
				int days = day_in_month(year, m);

				//计算这一行起始日
				int startday = line * 7 - firstday + 1;//firstday相当于偏移量

				//打印该行日历
				for (int d = 0; d < 7; d += 1) {
					int current_day = startday + d;
					if (current_day<1 || current_day>days) {
						cout << "    ";
					}
					else {
						//Sleep(50);(检验延时)
						cout << setiosflags(ios::left) << setw(4) << current_day;
					}
				}
				//月份中间的空格
				cout << "    ";
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int year;
	cout << "请输入年份[1900-2100]" << endl;
	cin >> year;

	int perline;
	while (1) {
		cout << "请输入每行打印的月份数[1/2/3/4/6/12]" << endl;
		cin >> perline;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}

		else if (perline == 1 || perline == 2 || perline == 3 || perline == 4 || perline == 6 || perline == 12) {
			break;
		}
		else {
			continue;
		}
	}

	printcalendar(year, perline);
}