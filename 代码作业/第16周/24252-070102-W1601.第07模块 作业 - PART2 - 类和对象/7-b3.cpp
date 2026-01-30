/*2452654 郭炫君 电信*/
#include <iostream>
using namespace std;

/* 1、不允许定义任何类型的全局变量，包括常变量及宏定义等
   2、不允许给出任何形式的全局函数
*/

/* --- 将类的定义补充完整 --- */
class Days {
private:
	int year;
	int month;
	int day;
	//除上面的三个private数据成员外，不再允许添加任何类型的数据成员

	/* 下面可以补充需要的类成员函数的定义（不提供给外界，仅供本类的其它成员函数调用，因此声明为私有，数量不限，允许不定义） */
	
	//判断闰年
	bool  is_leapyear()
	{
		return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	}

	//检查月份是否合法
	bool valid_month()
	{
		return month >= 1 && month <= 12;
	}

	//检查日期是否合法
	bool valid_day()
	{
		if (month == 2) {
			return is_leapyear() ? (day >= 1 && day <= 29) : (day >= 1 && day <= 28);
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			return day >= 1 && day <= 30;
		}
		else {
			return day >= 1 && day <= 31;
		}
	}

public:
	int calc_days()     //计算是当年的第几天
	{
		if (!valid_month())
			return -1;
		if (!valid_day())
			return -1;
		int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (is_leapyear()) {
			daysInMonth[1] = 29;
		}

		int day_of_year = 0;
		for (int i = 0; i < month - 1; ++i) {
				day_of_year += daysInMonth[i];
		}
		day_of_year += day;

		return day_of_year;
	}

	/* 下面可以补充其它需要的类成员函数的定义(体外实现)，数量不限，允许不定义 */
	Days(int y, int m, int d) : year(y), month(m), day(d)
	{
	}

};

/* --- 此处给出类成员函数的体外实现 --- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2024, 3, 18);
		cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 3, 18);
		cout << "应该输出77， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2024, 12, 31);
		cout << "应该输出366，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 12, 31);
		cout << "应该输出365，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2024, 2, 29);
		cout << "应该输出60， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 2, 29);
		cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
	}

	return 0;
}
