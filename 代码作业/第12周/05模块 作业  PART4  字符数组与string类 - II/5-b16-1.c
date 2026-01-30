//2452654 郭炫君 电信
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char xuehao[10][8];
	char name[10][9];
	int score[10];

	for (int i = 0; i < 10; i += 1) {
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s %s %d", xuehao[i], name[i], &score[i]);
	}
	printf("\n");

	for (int i = 0; i < 9; i += 1) {
		int max = i;
		for (int j = i + 1; j < 10; j += 1) {
			if (score[j] >= 60) {
				if (score[max] < 60 || strcmp(xuehao[j], xuehao[max])>0) {
					max = j;
				}
			}
		}

		if (score[max] >= 60) {
			char temp_xuehao[8];
			char temp_name[9];
			int temp_score;

			strcpy(temp_xuehao, xuehao[i]);
			strcpy(temp_name, name[i]);
			temp_score = score[i];

			strcpy(xuehao[i], xuehao[max]);
			strcpy(name[i], name[max]);
			score[i] = score[max];

			strcpy(xuehao[max], temp_xuehao);
			strcpy(name[max], temp_name);
			score[max] = temp_score;
		}
	}

	printf("及格名单(学号降序):\n");
	for (int i = 0; i < 10; i += 1) {
		if (score[i] >= 60) {
			printf("%s %s %d\n", name[i], xuehao[i], score[i]);
		}
	}

	return 0;
}
