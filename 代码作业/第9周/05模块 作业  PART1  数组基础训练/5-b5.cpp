//2452654 郭炫君 电信
#include <iostream>
using namespace std;
int main()
{
	int array[1000];      //记录每个成绩
	int count[101] = { 0 };//记录每个成绩的个数
	int num = 0;
	int score;
	cout<<"请输入成绩（最多1000个），负数结束输入"<<endl;
	while (num < 1000) {
		cin >> score;
		if (score < 0) {
			break;
		}
		array[num] = score;
		num += 1;
	}

	if (num == 0) {
		cout << "无有效输入" << endl;
		return 0;
	}

	cout << "输入的数组为:" << endl;
	for (int i = 0; i < num; i += 1) {
		cout << array[i]<<" ";
		if ((i + 1) % 10 == 0 && (i + 1) < num) {
			cout<<endl;
		}
		count[array[i]] += 1;//统计人数
	}
	cout << endl;

	cout << "分数与名次的对应关系为:" << endl;
	int rank = 1;
	for (int i = 100; i >= 0; i -= 1) {
		if (count[i] > 0) {
			int rank_now = rank;
			while (count[i] > 0) {
				cout << i << " " << rank_now << endl;
				count[i] -= 1;
				rank += 1;
			}
		}
	}

	return 0;
}