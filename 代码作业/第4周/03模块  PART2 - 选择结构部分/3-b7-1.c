//2452654 郭炫君 电信
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    printf("请输入找零值：\n");
    int y50 = 0, y20 = 0, y10 = 0, y5 = 0, y1 = 0, j5 = 0, j1 = 0, f5 = 0, f2 = 0, f1 = 0;
    double number;
    scanf("%lf", &number);

    if (number > 100 || number < 0.01) {
        printf("输入错误，请重新输入\n");
    }
    else {
        int total = (int)(round(number * 100));

        if (total >= 5000) {
            y50 = total / 5000;
            total %= 5000;
        }
        if (total >= 2000) {
            y20 = total / 2000;
            total %= 2000;
        }
        if (total >= 1000) {
            y10 = total / 1000;
            total %= 1000;
        }
        if (total >= 500) {
            y5 = total / 500;
            total %= 500;
        }
        if (total >= 100) {
            y1 = total / 100;
            total %= 100;
        }
        if (total >= 50) {
            j5 = total / 50;
            total %= 50;
        }
        if (total >= 10) {
            j1 = total / 10;
            total %= 10;
        }
        if (total >= 5) {
            f5 = total / 5;
            total %= 5;
        }
        if (total >= 2) {
            f2 = total / 2;
            total %= 2;
        }
        if (total >= 1) {
            f1 = total / 1;
            total %= 1;
        }

        int count = y50 + y20 + y10 + y5 + y1 + j5 + j1 + f5 + f2 + f1;
        printf("共%d张找零，具体如下：\n", count);
        if (y50 > 0)
            printf("50元 : %d张\n", y50);
        if (y20 > 0)
            printf("20元 : %d张\n", y20);
        if (y10 > 0)
            printf("10元 : %d张\n", y10);
        if (y5 > 0)
            printf("5元  : %d张\n", y5);
        if (y1 > 0)
            printf("1元  : %d张\n", y1);
        if (j5 > 0)
            printf("5角  : %d张\n", j5);
        if (j1 > 0)
            printf("1角  : %d张\n", j1);
        if (f5 > 0)
            printf("5分  : %d张\n", f5);
        if (f2 > 0)
            printf("2分  : %d张\n", f2);
        if (f1 > 0)
            printf("1分  : %d张\n", f1);
    }

    return 0;
}