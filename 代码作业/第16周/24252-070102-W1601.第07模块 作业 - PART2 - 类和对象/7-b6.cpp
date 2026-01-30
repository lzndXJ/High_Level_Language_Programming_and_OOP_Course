/*2452654 郭炫君 电信*/
#include <iostream>
#include <conio.h>
#include "7-b6.h"
using namespace std;

/* 给出 Date 类的所有成员函数的体外实现 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

/* 如果有需要的其它全局函数的实现，可以写于此处 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
//无参构造
Date::Date() : year(2000), month(1), day(1) {}

// 三参构造
Date::Date(int y, int m, int d) {
    set(y, m, d);
}

// 单参构造
Date::Date(int days) {
    // 限制天数范围
    if (days < 1)
        days = 1;
    if (days > 73049)
        days = 73049; // 2099.12.31

    year = 1900;
    month = 1;
    day = 1;

    days -= 1;

    while (days > 0) {
        int days_in_year = is_leapyear(year) ? 366 : 365;
        if (days >= days_in_year) {
            days -= days_in_year;
            year++;
        }
        else {
            int days_in_current_month = day_in_month(year, month);
            if (days >= days_in_current_month) {
                days -= days_in_current_month;
                month++;
            }
            else {
                day += days;
                days = 0;
                if (day > days_in_current_month) {
                    day = days_in_current_month;
                }
            }
        }
    }
}

// 设置日期
void Date::set(int y, int m, int d) {
    // 处理年份
    if (y != 0) {
        year = valid_year(y) ? y : 2000;
    }

    // 处理月份
    if (m != 0) {
        month = valid_month(m) ? m : 1;
    }

    // 处理日期
    if (d != 0) {
        day = valid_day(d) ? d : 1;
        // 检查日期是否有效（考虑月份和闰年）
        if (day > day_in_month(year, month)) {
            day = 1;
        }
    }

    // 确保最终日期有效
    normalize();
}

// 获取日期
void Date::get(int& y, int& m, int& d) const {
    y = year;
    m = month;
    d = day;
}

// 显示日期
void Date::show() const {
    cout << year << "." << month << "." << day << endl;
}

//检查年份是否有效
bool Date::valid_year(int y) const {
    return y >= 1900 && y <= 2099;
}

//检查月份是否有效
bool Date::valid_month(int m) const {
    return m >= 1 && m <= 12;
}

//检查日期是否有效（不考虑月份）
bool Date::valid_day(int d) const {
    return d >= 1 && d <= 31;
}

//判断是否为闰年
bool Date::is_leapyear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

//获取某年某月的天数
int Date::day_in_month(int y, int m) const {
    if (m == 2) {
        return is_leapyear(y) ? 29 : 28;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

//将日期转换为从1900.1.1开始的天数
int Date::to_days() const {
    int days = 0;
    for (int y = 1900; y < year; y++) {
        days += is_leapyear(y) ? 366 : 365;
    }
    for (int m = 1; m < month; m++) {
        days += day_in_month(year, m);
    }
    days += day - 1;
    return days;
}

//规范化日期
void Date::normalize() {
    // 确保年份在有效范围内
    if (!valid_year(year)) {
        year = 2000;
    }

    // 确保月份有效
    if (!valid_month(month)) {
        month = 1;
    }

    // 确保日期有效
    int maxDay = day_in_month(year, month);
    if (day < 1 || day > maxDay) {
        day = 1;
    }
}


