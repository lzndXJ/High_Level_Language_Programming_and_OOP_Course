//2452654 郭炫君 电信
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf("请输入[0-100亿)之间的数字:\n");
	double number;
	scanf("%lf", &number);
	printf("大写结果是:\n");
	long long integer = (long long)number;                  //提取整数
	int frac = (int)((number - integer) * 100 + 0.5);      //提取小数
	if (integer == 0 && frac == 0) {                  //先处理整数部分
		printf("零圆");
	}
	else if (integer > 0) {
		long long yi = integer / 100000000;     //先处理亿位
		if (yi > 0) {
			long long shi = yi / 10;
			if (shi > 0) {               //亿位的十位
				switch (shi) {
					case 1: 
						printf("壹"); 
						break;
					case 2: 
						printf("贰"); 
						break;
					case 3: 
						printf("叁");
						break;
					case 4: 
						printf("肆"); 
						break;
					case 5:
						printf("伍");
						break;
					case 6:
						printf("陆"); 
						break;
					case 7:
						printf("柒"); 
						break;
					case 8: 
						printf("捌");
						break;
					case 9:
						printf("玖");
						break;
				}
				printf("拾");
			}
			yi -= shi * 10;
			if (yi > 0) {                   //亿位的个位
				switch (yi) {
					case 1:
						printf("壹");
						break;
					case 2:
						printf("贰");
						break;
					case 3:
						printf("叁");
						break;
					case 4:
						printf("肆");
						break;
					case 5:
						printf("伍");
						break;
					case 6:
						printf("陆");
						break;
					case 7:
						printf("柒");
						break;
					case 8:
						printf("捌");
						break;
					case 9:
						printf("玖");
						break;
				}
			}
			printf("亿");
		}
		int integer1 = integer % 100000000;

		int wan = integer1 / 10000;  //处理万位
		if (wan > 0) {
			int qian = wan / 1000;  //万位的千位
			if (qian > 0) {
				switch (qian) {
					case 1:
						printf("壹");
						break;
					case 2:
						printf("贰");
						break;
					case 3:
						printf("叁");
						break;
					case 4:
						printf("肆");
						break;
					case 5:
						printf("伍");
						break;
					case 6:
						printf("陆");
						break;
					case 7:
						printf("柒");
						break;
					case 8:
						printf("捌");
						break;
					case 9:
						printf("玖");
						break;
				}
				printf("仟");
			}
			else if (integer / 100000000 > 0) {
				printf("零");
			}
			wan %= 1000;

			int bai = wan / 100;  //万位的百位
			if (bai > 0) {
				switch (bai) {
					case 1:
						printf("壹");
						break;
					case 2:
						printf("贰");
						break;
					case 3:
						printf("叁");
						break;
					case 4:
						printf("肆");
						break;
					case 5:
						printf("伍");
						break;
					case 6:
						printf("陆");
						break;
					case 7:
						printf("柒");
						break;
					case 8:
						printf("捌");
						break;
					case 9:
						printf("玖");
						break;
				}
				printf("佰");
			}
			else if (qian > 0 && wan % 1000 != 0)
				printf("零");
			wan %= 100;

			int shi = wan / 10;  //万位的十位
			if (shi > 0) {
				switch (shi) {
					case 1:
						printf("壹");
						break;
					case 2:
						printf("贰");
						break;
					case 3:
						printf("叁");
						break;
					case 4:
						printf("肆");
						break;
					case 5:
						printf("伍");
						break;
					case 6:
						printf("陆");
						break;
					case 7:
						printf("柒");
						break;
					case 8:
						printf("捌");
						break;
					case 9:
						printf("玖");
						break;
				}
				printf("拾");
			}
			else if (bai > 0 && wan % 100 != 0) {
				printf("零");
			}
			wan %= 10;

			if (wan > 0) {        //万位的个位
				switch (wan) {
					case 1:
						printf("壹");
						break;
					case 2:
						printf("贰");
						break;
					case 3:
						printf("叁");
						break;
					case 4:
						printf("肆");
						break;
					case 5:
						printf("伍");
						break;
					case 6:
						printf("陆");
						break;
					case 7:
						printf("柒");
						break;
					case 8:
						printf("捌");
						break;
					case 9:
						printf("玖");
						break;
				}
			}                       //如果个位是0，只有万位全为0才输出零，但在千位就会输出
			printf("万");
		}
		int integer2 = integer1 % 10000;

		int qian = integer2 / 1000; //处理元位
		if (qian > 0) {           //元位的千位
			switch (qian) {
				case 1:
					printf("壹");
					break;
				case 2:
					printf("贰");
					break;
				case 3:
					printf("叁");
					break;
				case 4:
					printf("肆");
					break;
				case 5:
					printf("伍");
					break;
				case 6:
					printf("陆");
					break;
				case 7:
					printf("柒");
					break;
				case 8:
					printf("捌");
					break;
				case 9:
					printf("玖");
					break;
			}
			printf("仟");
		}
		else if (integer / 10000 > 0 && integer % 10000 != 0) {
			printf("零");
		}
		integer2 %= 1000;

		int bai = integer2 / 100;   //元位的百位
		if (bai > 0) {
			switch (bai) {
				case 1:
					printf("壹");
					break;
				case 2:
					printf("贰");
					break;
				case 3:
					printf("叁");
					break;
				case 4:
					printf("肆");
					break;
				case 5:
					printf("伍");
					break;
				case 6:
					printf("陆");
					break;
				case 7:
					printf("柒");
					break;
				case 8:
					printf("捌");
					break;
				case 9:
					printf("玖");
					break;
			}
			printf("佰");
		}
		else if (qian > 0 && integer % 1000 != 0) {
			printf("零");
		}
		integer2 %= 100;

		int shi = integer2 / 10;  //元位的十位
		if (shi > 0) {
			switch (shi) {
				case 1:
					printf("壹");
					break;
				case 2:
					printf("贰");
					break;
				case 3:
					printf("叁");
					break;
				case 4:
					printf("肆");
					break;
				case 5:
					printf("伍");
					break;
				case 6:
					printf("陆");
					break;
				case 7:
					printf("柒");
					break;
				case 8:
					printf("捌");
					break;
				case 9:
					printf("玖");
					break;
			}
			 printf("拾");
		}
		else if (bai > 0 && integer % 100 != 0) {
			printf("零");
		}
		integer2 %= 10;

		if (integer2 > 0) {     //元位的个位
			switch (integer2) {
				case 1:
					printf("壹");
					break;
				case 2:
					printf("贰");
					break;
				case 3:
					printf("叁");
					break;
				case 4:
					printf("肆");
					break;
				case 5:
					printf("伍");
					break;
				case 6:
					printf("陆");
					break;
				case 7:
					printf("柒");
					break;
				case 8:
					printf("捌");
					break;
				case 9:
					printf("玖");
					break;
			}
		}
		printf("圆");
	}
	if (frac > 0) {
		int jiao = frac / 10;
		int fen = frac % 10;
		if (jiao > 0) {
			switch (jiao) {
				case 1:
					printf("壹");
					break;
				case 2:
					printf("贰");
					break;
				case 3:
					printf("叁");
					break;
				case 4:
					printf("肆");
					break;
				case 5:
					printf("伍");
					break;
				case 6:
					printf("陆");
					break;
				case 7:
					printf("柒");
					break;
				case 8:
					printf("捌");
					break;
				case 9:
					printf("玖");
					break;
			}
			printf("角");
		}
		else if (fen > 0 && integer > 0)
			printf("零");
		if (fen > 0) {
			switch (fen) {
				case 1:
					printf("壹");
					break;
				case 2:
					printf("贰");
					break;
				case 3:
					printf("叁");
					break;
				case 4:
					printf("肆");
					break;
				case 5:
					printf("伍");
					break;
				case 6:
					printf("陆");
					break;
				case 7:
					printf("柒");
					break;
				case 8:
					printf("捌");
					break;
				case 9:
					printf("玖");
					break;
			}
			printf("分");
		}
		else {
			printf("整");
		}

	}
	else
		printf("整");
	printf("\n");

	return 0;
}