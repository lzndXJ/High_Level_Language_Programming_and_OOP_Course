/*2452654 郭炫君 电信*/
#include <iostream> 
using namespace std;
//此处加入需要的头文件及命名空间
 
int main()
{
	/* 这些是输入输出提示的字符串，供大家复制到所需位置，避免细节差异 */ 
	int x1,y1,x2,y2;
	cout<<"请输入第1个点的坐标 : ";
	cin>>x1>>y1;
	cout<<"请输入第2个点的坐标 : ";
	cin>>x2>>y2;
	if(x1==x2){
		if(x1>0)
		cout<<"平行于y轴,在一四象限"<<endl;
		else if (x1<0)
		cout<<"平行于y轴,在二三象限"<<endl;
		else
		cout<<"经过原点"<<endl;
	}
	if(y1==y2){
		if(y1>0)
		cout<<"平行于x轴,在一二象限"<<endl;
		else if(y1<0)
		cout<<"平行于x轴,在三四象限"<<endl;
		else
		cout<<"经过原点"<<endl;
	}	
	double k=static_cast<double>(y2 - y1) / (x2 - x1);
	double b = y1 - k * x1;
	double x_jiao=-b/k;
	double y_jiao=b;
	if (x_jiao > 0 && y_jiao > 0) {
        cout << "在第一象限" << endl;
    } 
	else if (x_jiao < 0 && y_jiao > 0) {
        cout << "在第二象限" << endl;
    } 
	else if (x_jiao < 0 && y_jiao < 0) {
        cout << "在第三象限" << endl;
    } 
	else if (x_jiao > 0 && y_jiao < 0) {
        cout << "在第四象限" << endl;
    } 
	else if (x_jiao == 0 && y_jiao == 0) {
        cout << "经过原点" << endl;
    }

}

