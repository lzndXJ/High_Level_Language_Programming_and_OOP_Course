//2452654 郭炫君 电信
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int array[1000];      //记录每个成绩
	int count[101] = { 0 };//记录每个成绩的个数
	int num = 0;
	int score;
	printf("请输入成绩（最多1000个），负数结束输入\n");
	while (num < 1000) {
		scanf("%d", &score);
		if (score < 0) {
			break;
		}
		array[num] = score;
		num += 1;
	}

	if (num == 0) {
		printf("无有效输入\n");
		return 0;
	}

	printf("输入的数组为:\n");
	for (int i = 0; i < num; i += 1) {
		printf("%d ", array[i]);
		if ((i + 1) % 10 == 0&&(i+1)<num) {
			printf("\n");
		}
		count[array[i]] += 1;//统计人数
	}
	printf("\n");

	printf("分数与人数的对应关系为:\n");
	for (int i = 100; i >= 0; i -= 1) {
		if (count[i] > 0) {
			printf("%d %d\n", i, count[i]);
		}
	}

	return 0;
}