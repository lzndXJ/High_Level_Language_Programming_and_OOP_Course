//2452654 郭炫君 电信
#include <iostream>
using namespace std;
int main()
{
	const int n = 100;
	bool array[n + 1] = {};  //第一个不用
	for (int person = 1; person <= n; person += 1) {
		for (int light = person; light <= n; light += person) {
			array[light] = !array[light];
		}
	}

	bool first = true;
	for(int i=1;i<=n;i+=1){
		if (array[i]) {
			if (!first) {
				cout << " ";
			}
			cout << i ;
			first = false;
		}
	}
	cout << endl;

	return 0;
}