/*2452654 郭炫君 电信*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
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
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int step = 0;
    if (n == 1) {
        step += 1;
        printf("%5d:%3d# %c-->%c\n", step, n, src, dst);
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    step += 1;//把除了最大圆盘以外的圆盘移到中间柱
    printf("%5d:%3d# %c-->%c\n", step, n, src, dst);//把最大的圆盘移到目标柱
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
        printf("请输入汉诺塔的层数(1-16)\n");
        if (scanf("%d", &layer) == 1) {
            if (layer >= 1 && layer <= 16)
                break;
        }
        while (getchar() != '\n');//清空缓冲区
    }
    while (getchar() != '\n');
    //输入起始柱
    while (1) {
        printf("请输入起始柱(A-C)\n");
        if (scanf("%c", &start)==1) {
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
        if (scanf("%c", &end)==1) {
            end = (end >= 'a' && end <= 'z') ? end - 'a' + 'A' : end;
            if (end == start)
                printf("目标柱(%c)不能与起始柱(%c)相同\n", start, start);
            else if (end >= 'A' && end <= 'C')
                break;
        }
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    //计算中间柱的值
    char tmp = 'A' + 'B' + 'C' - start - end;
    printf("移动步骤为:\n");
    hanoi(layer, start, tmp, end);
    return 0;
}