/*2452654 郭炫君 电信*/
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、仅允许hanoi中定义一个静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */

   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
               3、允许定义一个静态局部变量
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int step = 0;
    if (n == 1) {
        step += 1;
        cout << setw(5) << step <<":" << setw(3) << n << "# " << src << "-->" << dst << endl;
        return;
    }
    hanoi(n - 1, src, dst, tmp); 
    step += 1;//把除了最大圆盘以外的圆盘移到中间柱
    cout << setw(5) << step <<":" << setw(3) << n << "# " << src << "-->" << dst << endl;//把最大的圆盘移到目标柱
    hanoi(n - 1, tmp, src, dst);                 //把剩下的圆盘从中间柱移到目标柱
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
    int layer;
    char start, end;
    //输入层数
    while (1) {
        cout << "请输入汉诺塔的层数(1-16)" << endl;
        cin >> layer;
        if (cin.good()) {
            if (layer >= 1 && layer <= 16)
                break;
        }
        cin.clear();
        cin.ignore(1024, '\n');
    }
    cin.ignore(1024, '\n');
    //输入起始柱
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> start;
        if (cin.good()) {
            start = toupper(start);
            if (start >= 'A' && start <= 'C')
                break;
        }
        cin.clear();
        cin.ignore(1024, '\n');
    }
    cin.ignore(1024, '\n');
    //输入目标柱
    while (1) {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> end;
        if (cin.good()) {
            end = toupper(end);
            if (end == start)
                cout << "目标柱(" << start << ")不能与起始柱(" << start << ")相同" << endl;
            else if (end >= 'A' && end <= 'C')
                break;
        }
        cin.clear();
        cin.ignore(1024, '\n');
    }
    cin.ignore(1024, '\n');
    //计算中间柱的值
    char tmp = 'A' + 'B' + 'C' - start - end;
    cout << "移动步骤为:" << endl;
    hanoi(layer, start, tmp, end);

    return 0;
}