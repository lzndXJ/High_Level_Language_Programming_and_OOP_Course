//2452654 郭炫君 电信
#include <iostream>
using namespace std;

//检验数独的函数
bool judge(int board[9][9])
{
	//检查行
	for (int i = 0; i < 9; i += 1) {
		int valid[10] = { 0 };
		for (int j = 0; j < 9; j += 1) {
			int num = board[i][j];
			if (valid[num] == 1) {
				return false;
			}
			valid[num] = 1;
		}
	}
	//检查列
	for (int i = 0; i < 9; i += 1) {
		int valid[10] = { 0 };
		for (int j = 0; j < 9; j += 1) {
			int num = board[j][i];
			if (valid[num] == 1) {
				return false;
			}
			valid[num] = 1;
		}
	}
	//检查宫格
	for (int box = 0; box < 9; box += 1) {
		int valid[10] = { 0 };
		int start_row = box / 3 * 3;
		int start_col = box % 3 * 3;
		for (int i = start_row; i < 3; i += 1) {
			for (int j = start_col; j < 3; j += 1) {
				int num = board[i][j];
				if (valid[num] == 1)
					return false;
				valid[num] = 1;
			}
		}
	}

	return true;
}

int main()
{
	int board[9][9];
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	for (int i = 0; i < 9; i += 1) {
		for (int j = 0; j < 9; j += 1) {
			while (1) {
				cin >> board[i][j];
				if (cin.fail()) {
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				else if (board[i][j] < 1 || board[i][j] > 9) {
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					continue;
				}

				else {
					break;
				}
			}
		}
	}

	if (!judge(board)) {
		cout << "不是数独的解" << endl;
	}
	else {
		cout << "是数独的解" << endl;
	}

	return 0;
}