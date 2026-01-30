//2452654 郭炫君 电信
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

//判断坐标是否有效
bool judge_position(int row, int col)
{
	return row >= 0 && row < 10 && col >= 0 && col < 26;
}

//计算每个格子周围地雷个数
int around_mine(int row, int col, bool mine[10][26])
{
	int count = 0;
	for (int i = -1; i <= 1; i += 1) {
		for (int j = -1; j <= 1; j += 1) {
			if (i == 0 && j == 0)
				continue;
			int new_row = row + i;
			int new_col = col + j;
			if (judge_position(new_row, new_col)&&mine[new_row][new_col]) {
				count += 1;
			}
		}
	}
	return count;
}

//放置随机的地雷
void place_mine(bool mine[10][26])
{
	srand((unsigned int)(time(0)));
	int mineplace = 0;
	while (mineplace < 50) {
		int row = rand() % 10;
		int col = rand() % 26;

		if (!mine[row][col]) {
			mine[row][col] = true;
			mineplace += 1;
		}
	}
}

//将数据填入board中
void fill_board(char board[10][26], bool mine[10][26])
{
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 26; ++j) {
			if (!mine[i][j]) {
				int count = around_mine(i, j, mine);
				board[i][j] = '0' + count;
			}
			else {
				board[i][j] = '*';
			}
		}
	}
}

//打印游戏板
void print_board(char board[10][26])
{
	for (int i = 0; i < 10; i += 1) {
		for (int j = 0; j < 26; j += 1) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	char board[10][26] = {'0'};
	bool mine[10][26] = {false};//是否这一格是地雷
	
	place_mine(mine);
	fill_board(board, mine);
	print_board(board);

	return 0;
}
