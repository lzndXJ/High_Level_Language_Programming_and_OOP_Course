//2452654 郭炫君 电信
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int y, m, d;
	int ret;
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret = scanf("%d %d", &y, &m);
		if (ret==0 || ret==1) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			printf("输入非法，请重新输入\n");
		}
		else if (y > 2000 && y < 2030 && m >= 1 && m <= 12)
			break;
		else
			printf("输入非法，请重新输入\n");
	}
	while (1) {
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ",y,m);
		ret = scanf("%d", &d);
		if (ret==0) {
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			printf("输入非法，请重新输入\n");
		}
		else if (d >= 0 && d <= 6)
			break;
		else
			printf("输入非法，请重新输入\n");
	}
	int monthdays;
	if (m == 2)
		if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
			monthdays = 29;
		else
			monthdays = 28;
	else if (m == 4 || m == 6 || m == 9 || m == 11)
		monthdays = 30;
	else
		monthdays = 31;
	printf("\n");
	printf("%d年%d月的月历为:\n",y,m);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n" );
	for (int i = 0; i < d; i++) {
		printf("        ");
	}
	int nowdays = 1;
	int weekdays = d;
	while (nowdays <= monthdays) {
		if (nowdays < 10)
			printf(" ");
		printf("  %d    ",nowdays);
		weekdays += 1;
		if (weekdays > 6) {
			printf("\n");
			weekdays = 0;
		}
		nowdays += 1;
	}
	printf("\n");
	return 0;
}