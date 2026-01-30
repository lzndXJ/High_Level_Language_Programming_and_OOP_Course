/*2452654 郭炫君 电信*/
#include <iostream>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量（不包括宏定义、全局const变量）
   ---------------------------------------------------------------------
*/

int is_power(int num, int base)
{
    if (num==1)
        return 1;
    else if (num % base != 0)
        return 0;
    else if (num / base == 1)
        return 1;
    return is_power(num / base, base);
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	int n,base;
	int count=0;
	int array[10000];
	cout<<"请输入数据的个数[1..10000]" <<endl;
	cin>>n;
	cout<<"请输入"<<n<<"个正整数"<<endl;
	
	for (int i=0;i<n;i+=1){
		cin>>array[i];
	}
	
	cout<<"请输入基数[2..9]"<<endl;
	cin>>base;
	
	for (int i=0;i<n;i+=1){
		if (is_power(array[i],base)){
			count+=1;
		}
	}
	
	cout << n << "个数中基数" << base << "的幂的个数 : " << count << endl;
    
	return 0;
}

