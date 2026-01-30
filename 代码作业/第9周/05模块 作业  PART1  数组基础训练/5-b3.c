//2452654 郭炫君 电信
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int runnian(int y)
{
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		return 1;
	else
		return 0;
}

int totaldays(int y, int m, int d)
{
	int array[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (runnian(y) == 1)
		array[1] = 29;
	if (m < 1 || m>12)
		return -1;
	if (d<1 || d>array[m - 1])
		return -2;
	int total = 0;
	for (int i = 0; i < m-1; i += 1) {
		total += array[i];
	}
	total += d;
	return total;
}

int main()
{
	int year, month, day;

	printf("请输入年，月，日\n");
	scanf("%d %d %d", &year, &month, &day);

	int result = totaldays(year, month, day);

	if (result == -1) {
		printf("输入错误-月份不正确\n");
	}
	else if (result == -2) {
		printf("输入错误-日与月的关系非法\n");
	}
	else {
		printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, result);
	}

	return 0;

}