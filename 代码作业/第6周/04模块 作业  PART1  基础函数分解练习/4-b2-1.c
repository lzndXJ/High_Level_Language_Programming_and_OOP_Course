//2452654 郭炫君 电信
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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
			printf("星期日\n");
			break;
		case 1:
			printf("星期一\n");
			break;
		case 2:
			printf("星期二\n");
			break;
		case 3:
			printf("星期三\n");
			break;
		case 4:
			printf("星期四\n");
			break;
		case 5:
			printf("星期五\n");
			break;
		case 6:
			printf("星期六\n");
			break;
	}

	return 0;
}
int main() {
	int y, m, d;
	while (1) {
		printf("请输入年[1900-2100]、月、日：\n");
		if (scanf("%d %d %d", &y, &m, &d) != 3) {
			while (getchar() != '\n'); 
			printf("输入错误，请重新输入\n");
			continue;
		}
		else if (y < 1900 || y>2100)
			printf("年份不正确，请重新输入\n");
		else if (m < 1 || m>12)
			printf("月份不正确，请重新输入\n");
		else if (m == 2) {
			if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
				if (d < 1 || d>29)
					printf("日不正确，请重新输入\n");
				else
					break;
			}
			else {
				if (d < 1 || d>28)
					printf("日不正确，请重新输入\n"); 
				else
					break;
			}
		}
		else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
			if (d < 1 || d>31)
				printf("日不正确，请重新输入\n");
			else
				break;
		}
		else if (m == 4 || m == 6 || m == 9 || m == 11) {
			if (d < 1 || d>30)
				printf("日不正确，请重新输入\n");
			else
				break;
		}
	}
	zeller(y, m, d);
	return 0;
}