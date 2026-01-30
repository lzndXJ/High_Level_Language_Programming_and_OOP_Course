//2452654 郭炫君 电信
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include "5-b7.h"

using namespace std;

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
// 静态全局变量
static int delay_time = 0;      // 移动延时(毫秒)
static int show_internal = 0;   // 是否显示内部数组

void print_internal_array()  //打印内部数组
{
    if (!show_internal) //判断是否需要打印内部数组
        return;

    for (int i = 0; i < 3; i += 1) {
        char zhuzi = 'A' + i;
        cout << zhuzi << ":";
        int current_top;
        int current_disks[10];
        if (i == 0) {
            current_top = top_A;
            for (int k = 0; k < 10; k += 1)
                current_disks[k] = disks_A[k];
        }
        else if (i == 1) {
            current_top = top_B;
            for (int k = 0; k < 10; k += 1)
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
                cout << current_disks[j];
            else {
                cout << " " << current_disks[j];
            }
        }
        for (int i = 0; i < space; i++) {
            cout << " ";
        }
    }
    cout << endl;
}

void print_first(char start,char end,int layer,int time)
{
    cct_cls();
    if (show_internal) {
        cout << "从 " << start << " 移动到 " << end << " ，共 " << layer << " 层，延时设置为 " << time << "，显示内部数组值" << endl;
    }
    else {
        cout << "从 " << start << " 移动到 " << end << " ，共 " << layer << " 层，延时设置为 " << time << "，不显示内部数组值" << endl;
    }
    cout << "初始:               ";
    print_internal_array();
}

void print_tower_vertical(char start,char end,int layer,int time,int step_num, int disk, char from, char to)  //竖向打印汉诺塔
{
    cct_cls();

    // 打印标题和步骤信息
    cct_gotoxy(0, 0);
    if (show_internal) {
        cout << "从 " << start << " 移动到 " << end << " ，共 " << layer << " 层，延时设置为 " << time << "，显示内部数组值" << endl;
    }
    else {
        cout << "从 " << start << " 移动到 " << end << " ，共 " << layer << " 层，延时设置为 " << time << "，不显示内部数组值" << endl;
    }

    cout << "第" << setw(4) << step_num << "步(" << setw(2) << disk << "): " << from << "-->" << to << " ";
    print_internal_array();
    cout << endl << endl;

    // 打印柱子
    int  const max_height = 9;
    for (int i = max_height; i >= 0; i-=1) {
        cct_gotoxy(5, max_height - i + 3);
        if (i <= top_A) 
            cout << setw(2) << disks_A[i];
        else 
            cout << " |";

        cct_gotoxy(15, max_height - i + 3);
        if (i <= top_B) 
            cout << setw(2) << disks_B[i];
        else 
            cout << " |";

        cct_gotoxy(25, max_height - i + 3);
        if (i <= top_C) 
            cout << setw(2) << disks_C[i];
        else 
            cout << " |";
    }

    // 打印柱子标签
    cct_gotoxy(5, max_height + 4);
    cout << " A";
    cct_gotoxy(15, max_height + 4);
    cout << " B";
    cct_gotoxy(25, max_height + 4);
    cout << " C";

    // 使用delay_time的特殊值-1表示步进模式
    if (delay_time == -1) {
        cout << endl;
        cout<<"按回车继续...";
        cin.ignore();
    }
    else if (delay_time > 0) {
        Sleep(delay_time);
    }
}

void move_disk(char start,char end,int layer,int time,int disk, char from, char to)
{
    // 移动圆盘
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

    // 更新源柱子栈顶
    if (from == 'A') 
        top_A-=1;
    else if (from == 'B') 
        top_B-=1;
    else 
        top_C-=1;

    step+=1;
    print_tower_vertical(start,end,layer,time,step, disk, from, to);
}

void hanoi(char start, char end, int layer,int time,int n, char src, char tmp, char dst)//前四个变量只是为了打印首行
{
    if (n == 1) {
        move_disk(start, end, layer, time, 1, src, dst);
        return;
    }
    hanoi(start, end, layer, time, n - 1, src, dst, tmp);
    move_disk(start, end, layer, time, n, src, dst);
    hanoi(start, end, layer, time, n - 1, tmp, src, dst);
}

int main()
{
    int layer;
    char start, end;
    int speed;

    // 输入层数
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

    // 输入起始柱
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

    // 输入目标柱
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

    // 输入速度选项
    while (1) {
        cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;           
        cin >> speed;
        if (cin.good()) {
            if (speed >= 0 && speed <= 5) {
                switch (speed) {
                    case 0:
                        delay_time = -1;
                        break;  // 使用-1表示步进模式
                    case 1:
                        delay_time = 1000;
                        break;
                    case 2:
                        delay_time = 500;
                        break;
                    case 3:
                        delay_time = 200;
                        break;
                    case 4:
                        delay_time = 50;
                        break;
                    case 5:
                        delay_time = 0;
                        break;
                }
                break;
            }
            else
                continue;
        }
        cin.clear();
        cin.ignore(1024, '\n');
    }
    cin.ignore(1024, '\n');

    // 输入是否显示内部数组
    while (1) {
        cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
        cin >> show_internal;
        if (cin.good()) {
            if (show_internal == 1 or show_internal == 0)
                break;
            else
                continue;
        }
        cin.clear();
        cin.ignore(1024, '\n');
    }
    cin.ignore(1024, '\n');

    // 初始化起始柱
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

    // 显示初始状态
    print_first(start, end, layer, speed);
    if (delay_time == -1) {
        cout << endl;
        cout << "按回车继续...";
        cin.ignore();
    }
    else if (delay_time > 0) {
        Sleep(delay_time);
    }

    // 计算中间柱
    char tmp = 'A' + 'B' + 'C' - start - end;
    hanoi(start, end, layer, speed, layer, start, tmp, end);

    cct_gotoxy(0, 20);
    system("pause");
    return 0;
}