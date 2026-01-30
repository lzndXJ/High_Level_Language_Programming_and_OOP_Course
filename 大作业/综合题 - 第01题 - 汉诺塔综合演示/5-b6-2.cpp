/*2452654 郭炫君 电信*/
#include <iostream>
#include <iomanip>
using namespace std;

int tops[3] = { -1, -1, -1 };  // 三根柱子的栈顶指针
int disks[3][10];            // 三根柱子上的圆盘（每柱最多10个）
int step= 0;          // 移动步数计数

void print_tower() //打印每根柱子圆盘
{
    for (int i = 0; i < 3; i += 1) {
        char zhuzi = 'A' + i;
        cout << " " << zhuzi << ":";
        int space = 20 - ((tops[i]+1) * 2); //每个数字 + 空格占2字符
        for (int j = 0; j <= tops[i]; j += 1) {
            if (disks[i][j] == 10) //demo里面10在第一个前面没有空格
                cout << disks[i][j];
            else {
                cout << " " << disks[i][j];
            }
        }
        for (int i = 0; i < space; i++) {
            cout << " ";
        }
    }
    cout << endl;
}

void print_first()
{
    cout << "初始:               ";
    print_tower();
}

//移动圆盘，打印圆盘状态
void move_disk(int disk, char from, char to)
{
    int from_index = from - 'A';
    int to_index = to - 'A';
    disks[to_index][tops[to_index] + 1] = disks[from_index][tops[from_index]];//先赋值，再修改栈顶
    tops[to_index] += 1;
    tops[from_index] -= 1;
    step += 1;
    cout << "第" << setw(4) << step << " 步(" << setw(2) << disk << "): " << from << "-->" << to;
    print_tower();
}
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
        move_disk(1, src, dst);
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    move_disk(n, src, dst);//把最大的圆盘移到目标柱
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
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> layer;
        if (cin.good()) {
            if (layer >= 1 && layer <= 10)
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
    //初始化起始柱,并打印
    int start_index = start - 'A';
    for (int i = 0; i < layer; i += 1) {
        disks[start_index][i] = layer - i;
    }
    tops[start_index] = layer - 1;
    print_first();
    //计算中间柱的值
    char tmp = 'A' + 'B' + 'C' - start - end;
    hanoi(layer, start, tmp, end);

    return 0;
}