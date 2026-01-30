/*2452654 郭炫君 电信*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 三根柱子的栈顶指针
int top_A = -1;
int top_B = -1;
int top_C = -1;
// 三根柱子上的圆盘（每柱最多10个）
int disks_A[10];
int disks_B[10];
int disks_C[10];
// 移动步数计数
int step = 0; 

void print_tower() //打印每根柱子圆盘
{
    for (int i = 0; i < 3; i += 1) {
        char zhuzi = 'A' + i;
        printf(" %c:", zhuzi);
        int current_top;
        int current_disks[10];
        if (i == 0) {
            current_top = top_A;
            for (int k = 0; k < 10; k += 1)
                current_disks[k] = disks_A[k];
        }
        else if (i == 1) {
            current_top = top_B;
            for (int k = 0; k < 10; k+=1) 
                current_disks[k] = disks_B[k];
        }
        else {
            current_top = top_C;
            for (int k = 0; k < 10; k += 1)
                current_disks[k] = disks_C[k];
        }
        int space = 20 - ((current_top + 1) * 2); //每个数字 + 空格占2字符
        for (int j = 0; j <= current_top; j += 1) {
            if (current_disks[j] == 10) //demo里面10在第一个前面没有空格
                printf("%d", current_disks[j]);
            else {
                printf(" %d", current_disks[j]);
            }
        }
        for (int i = 0; i < space; i++) {
            printf(" ");
        }
    }
    printf("\n");
}

void print_first()
{
    printf("初始:               ");
    print_tower();
}

//移动圆盘，打印圆盘状态
void move_disk(int disk, char from, char to)
{
    //移动员盘
    if (to == 'A') {
        disks_A[top_A + 1] = (from == 'A') ? disks_A[top_A] : (from == 'B') ? disks_B[top_B] : disks_C[top_C];
        top_A+=1;
    }
    else if (to == 'B') {
        disks_B[top_B + 1] = (from == 'A') ? disks_A[top_A] : (from == 'B') ? disks_B[top_B] : disks_C[top_C];
        top_B+=1;
    }
    else {
        disks_C[top_C + 1] = (from == 'A') ? disks_A[top_A] : (from == 'B') ? disks_B[top_B] : disks_C[top_C];
        top_C+=1;
    }

    //更新栈顶
    if (from == 'A')
        top_A -= 1;
    else if (from == 'B')
        top_B -= 1;
    else
        top_C-=1;

    step += 1;
    printf("第%4d 步(%2d): %c-->%c", step, disk, from, to);
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
        printf("请输入汉诺塔的层数(1-10)\n");
        if (scanf("%d", &layer) == 1) {
            if (layer >= 1 && layer <= 10)
                break;
        }
        while (getchar() != '\n');//清空缓冲区
    }
    while (getchar() != '\n');
    //输入起始柱
    while (1) {
        printf("请输入起始柱(A-C)\n");
        if (scanf("%c", &start) == 1) {
            start = (start >= 'a' && start <= 'z') ? start - 'a' + 'A' : start;
            if (start >= 'A' && start <= 'C')
                break;
        }
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    //输入目标柱
    while (1) {
        printf("请输入目标柱(A-C)\n");
        if (scanf("%c", &end) == 1) {
            end = (end >= 'a' && end <= 'z') ? end - 'a' + 'A' : end;
            if (end == start)
                printf("目标柱(%c)不能与起始柱(%c)相同\n", start, start);
            else if (end >= 'A' && end <= 'C')
                break;
        }
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    //初始化起始柱,并打印
    if (start == 'A') {
        for (int i = 0; i < layer; i++)
            disks_A[i] = layer - i;
        top_A = layer - 1;
    }
    else if (start == 'B') {
        for (int i = 0; i < layer; i++)
            disks_B[i] = layer - i;
        top_B = layer - 1;
    }
    else {
        for (int i = 0; i < layer; i++)
            disks_C[i] = layer - i;
        top_C = layer - 1;
    }
    print_first();
    //计算中间柱的值
    char tmp = 'A' + 'B' + 'C' - start - end;
    hanoi(layer, start, tmp, end);

    return 0;
}