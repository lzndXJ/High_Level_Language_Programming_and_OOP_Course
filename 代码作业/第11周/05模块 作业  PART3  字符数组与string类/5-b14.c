//2452654 郭炫君 电信
/*2452647 施程皓宇 2453359 李欣洋 2451884 左柳坤 2450464 欧健恒 2453624 王钲达*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//判断坐标是否正确
int judge(int i, int j)
{
	return i >= 0 && i < 10 && j >= 0 && j < 26;
}

//计算一个坐标周围地雷个数
int count_mines(char board[10][26], int i, int j)
{
	int count = 0;
	for (int i1 = -1; i1 <= 1; i1 += 1) {
		for (int j1 = -1; j1 <= 1; j1 += 1) {
			if (i1 == 0 && j1 == 0)
				continue;
			int new_i = i + i1;
			int new_j = j + j1;
			if (judge(new_i, new_j) && board[new_i][new_j] == '*') {
				count += 1;
			}
		}
	}
	return count;
}

int main()
{
	char board[10][26];
	int mines = 0;

	for (int i = 0; i < 10; i += 1) {
		char c;
		int col = 0;
		while (col < 26) {
			c = getchar();
			if (c == ' ' || c == '\n')
				continue;
			board[i][col] = c;
			if (c == '*') 
				mines += 1;
			col += 1;
		}
	}

	if (mines != 50) {
		printf("错误1\n");
		return 0;
	}

	for (int i = 0; i < 10; i += 1) {
		for (int j = 0; j < 26; j += 1) {
			char c = board[i][j];
			if (c != '*') {
				int expect = c - '0';
				int actual = count_mines(board, i, j);
				if (expect != actual) {
					printf("错误2\n");
					return 0;
				}
			}
		}
	}

	printf("正确\n");
	return 0;
}

