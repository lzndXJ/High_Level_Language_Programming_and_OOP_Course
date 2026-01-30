/* 2452654 郭炫君 电信 */ 
#include <iostream>
#include <iomanip>
//不再允许增加任何其他头文件 
using namespace std;

int main()
{
	int b; //除此之外，不允许定义任何其他变量 （包括常变量） 
 	cout<<"请输入一个整数 : ";
 	cin>>b;
	cout << "==================================================" << endl;
	cout << "0         1         2         3         4" << endl;
	cout << "01234567890123456789012345678901234567890123456789" << endl;
	cout << "==================================================" << endl;

	/* 按要求输出b的各种形式 -- Begin */ 
 	cout<<b<<"#"<<endl;
 	
 	cout <<setiosflags(ios::uppercase)<<hex<<b<<"#"<<endl;
 	cout <<resetiosflags(ios::uppercase);
 	
 	cout <<hex<<b<<"#"<<endl;
 	
 	cout <<setiosflags(ios::uppercase)<<hex<<b<<"#"<<endl;
 	cout <<resetiosflags(ios::uppercase) ;
 	
 	cout<<setw(15)<<dec<<b<<",";
 	cout << setiosflags(ios::left);
 	cout << setw(15) << b << '#' <<endl;
 	
 	cout << setiosflags(ios::left);
 	cout << setfill('*') << setw(15) << b << '#'<<endl;
 	
 	cout << setiosflags(ios::right);
 	cout<<setfill(' ');
 	cout<<setw(15)<<b<<"#"<<endl;
 	cout << resetiosflags(ios::right) ;
 	
 	cout<<setiosflags(ios::showpos)<<b<<"#"<<endl;
 	
 	cout << setiosflags(ios::left);
 	cout<<setw(15)<<oct<<b<<",";
 	cout << setiosflags(ios::right);
 	cout<<setw(15)<<oct<<b<<"#"<<endl;
 	
 	cout << setfill('*') << setw(15) <<oct<< b << '#'<<endl;
 	
 	cout<<setfill(' ');
 	cout << setw(15) <<oct<< b << '#'<<endl;
	/* 按要求输出b的各种形式 -- End */ 

	cout << "==================================================" << endl;
	cout << "01234567890123456789012345678901234567890123456789" << endl;
	cout << "0         1         2         3         4" << endl;
	cout << "==================================================" << endl;

	return 0;
}

