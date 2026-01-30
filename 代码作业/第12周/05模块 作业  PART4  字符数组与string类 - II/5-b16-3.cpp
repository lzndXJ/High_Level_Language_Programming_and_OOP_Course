//2452654 郭炫君 电信
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string xuehao[10];
	string name[10];
	int score[10];

	for (int i = 0; i < 10; i += 1) {
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> xuehao[i] >> name[i] >> score[i];
	}
	cout << endl;

	for (int i = 0; i < 9; i += 1) {
		int min = i;
		for (int j = i + 1; j < 10; j += 1) {
			if (xuehao[min] > xuehao[j]) {
				min = j;
			}
		}

		string temp_xuehao;
		string temp_name;
		int temp_score;

		temp_xuehao = xuehao[i];
		temp_name = name[i];
		temp_score = score[i];

		xuehao[i] = xuehao[min];
		name[i] = name[min];
		score[i] = score[min];

		xuehao[min] = temp_xuehao;
		name[min]= temp_name;
		score[min] = temp_score;
	}

	cout << "全部学生(学号升序):" << endl;
	for (int i = 0; i < 10; i += 1) {
		cout << name[i] << " " << xuehao[i] << " " << score[i] << endl;
	}
	return 0;
}