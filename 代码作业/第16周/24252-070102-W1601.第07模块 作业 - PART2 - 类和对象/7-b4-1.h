/*2452654 郭炫君 电信*/
#pragma once
#include <cmath>
/* 允许加入需要的头文件、命令空间 */

/* point类的定义及实现，已给出部分内容，按要求补充完成 */
class point {
private:
	int x;
	int y;
	//除上面的两个private数据成员外，不再允许添加任何类型的数据成员
public:
	int getx() const //函数声明后加const，表示不允许在本函数中修改数据成员的值 
	{
		return x;
	}
	int gety() const //函数声明后加const，表示不允许在本函数中修改数据成员的值
	{
		return y;
	}
	/* 可以定义需要的成员函数，数量不限，并以体内方式实现，不允许添加数据成员 */
	//构造函数
	point(int x_val = 0, int y_val = 0) :x(x_val), y(y_val)
	{

	}

	void set(int x_val, int y_val)
	{
		x = x_val;
		y = y_val;
	}
};

/* triangle类的定义及实现，已给出部分内容，按要求补充完成 */
class triangle {
private:
	point p1;
	point p2;
	point p3;
	//除上面的三个private数据成员外，不再允许添加任何类型的数据成员
public:
	/* 根据需要补充相应的语句后完成area函数(形参为空，不准改)，要求：如果三点能构成三角形，则返回面积，否则返回 -1 */
	double area()
	{
		if (is_collinear()) {
			return -1;
		}

		double a = distance(p1, p2);
		double b = distance(p2, p3);
		double c = distance(p1, p3);
		double s = (a + b + c) / 2;

		return sqrt(s*(s-a)*(s-b)*(s-c));
	}
	/* 构造函数（已实现，不准动） */
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
	{
		/* 给p1/p2/p3三个点分别赋x,y坐标值 */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}
	/* 可以定义需要的成员函数，数量不限，并以体内方式实现，不允许添加数据成员 */
	//检查是否共线
	bool is_collinear() const
	{
		int x1 = p1.getx(), y1 = p1.gety();
		int x2 = p2.getx(), y2 = p2.gety();
		int x3 = p3.getx(), y3 = p3.gety();

		return (y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1);
	}

	//计算两点之间距离
	double distance(const point& a, const point& b) const
	{
		return sqrt(pow(a.getx() - b.getx(), 2) + pow(a.gety() - b.gety(), 2));
	}
};
