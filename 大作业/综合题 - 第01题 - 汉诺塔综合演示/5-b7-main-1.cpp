/*2453359 电信 李欣洋*/
#include<iostream>
#include<Windows.h>
#include<iomanip>
#include <conio.h>
#include"5-b7.h"
using namespace std;

int topa = 0, topb = 0, topc = 0;//三个栈顶指针
int step_count = 0;//计数器
int arra[10] = { 0 }, arrb[10] = { 0 }, arrc[10] = { 0 };//三个用于储存圆盘的数组
static int choose1 = 0;
static int choose2 = 0;

void innitialization(int floor, char first)
{
    if (first == 'A')
    {
        topa = floor;
        for (int i = 0; i < floor; i++)
        {
            arra[i] = floor - i;
        }
    }
    if (first == 'B')
    {
        topb = floor;
        for (int i = 0; i < floor; i++)
        {
            arrb[i] = floor - i;
        }
    }
    if (first == 'C')
    {
        topc = floor;
        for (int i = 0; i < floor; i++)
        {
            arrc[i] = floor - i;
        }
    }
}

void print_initialization(int floor, char first) {
    cout << "初始:                ";

    if (first == 'A') 
    {
        cout << "A:";
        for (int i = 0; i < floor; i++) 
        {
            cout << setw(2) << arra[i];
        }
        for (int j = 0; j < 10 - floor; j++) 
        {
            cout << "  ";
        }
        cout << " B:                     C:                     ";
    }
    else if (first == 'B') 
    {
        cout << "A:                     B:";
        for (int i = 0; i < floor; i++) 
        {
            cout << setw(2) << arrb[i];
        }
        for (int j = 0; j < 10 - floor; j++) 
        {
            cout << "  ";
        }
        cout << " C:                     ";
    }
    else if (first == 'C') 
    {
        cout << "A:                     B:                     C:";
        for (int i = 0; i < floor; i++) 
        {
            cout << setw(2) << arrc[i];
        }
        for (int j = 0; j < 10 - floor; j++) 
        {
            cout << "  ";
        }
        cout << " ";
    }
}
void print_condition(int move, char from, char to, char the_first, char the_end, int choose1, int choose2, int floor)
{
    cct_gotoxy(1, 1);
    cout << "从" << the_first << "移动到" << the_end << ",共" << floor << "层,延时设置为" << choose1 << ",";
    if (choose2 == 0)
    {
        cout << "不显示内部数组";
    }
    else if (choose2 == 1)
    {
        cout << "显示内部数组";
    }
    cct_gotoxy(1,30);
    cout << "                    ";
    cout << "第" << setw(4) << step_count << " 步("<< setw(2) << move << "): " << from << "-->" << to << " ";

    cout << "A:";
    for (int i = 0; i < topa; i++) 
    {
        cout << setw(2) << arra[i];
    }
    for (int j = 0; j < 10 - topa; j++) 
    {
        cout << "  ";
    }

    cout << " B:";
    for (int k = 0; k < topb; k++) 
    {
        cout << setw(2) << arrb[k];
    }
    for (int l = 0; l < 10 - topb; l++) 
    {
        cout << "  ";
    }

    cout << " C:";
    for (int m = 0; m < topc; m++) 
    {
        cout << setw(2) << arrc[m];
    }
    for (int n = 0; n < 10 - topc; n++) 
    {
        cout << "  ";
    }
    if (choose1 == 0)
    {
        int ch = _getch();
        //cct_cls();
    }
    switch (choose1)
    {
        case 1:
            Sleep(1000);
            //cct_cls();
            break;
        case 2:
            Sleep(500);
            //cct_cls();
            break;
        case 3:
            Sleep(250);
            //cct_cls();
            break;
        case 4:
            Sleep(100);
            //cct_cls();
            break;
        case 5:
            Sleep(10);
            //cct_cls();
            break;
    }
    cct_gotoxy(1, 27);
    cout << "A";
    cct_gotoxy(1, 26);
    cout << "======================";
    cct_gotoxy(1, 25);
    for (int i = 0; i < topa; i++)
    {
        cout << arra[i];
        cct_gotoxy(1, 24-i);
    }
    for (int i = topa; i < 15; i++)
    {
        putchar(' ');
        cct_gotoxy(1, 23-i);
    }
    cct_gotoxy(8, 27);
    cout << "B";
    cct_gotoxy(8, 26);
    cout << "======================";
    cct_gotoxy(8, 25);
    for (int i = 0; i < topb; i++)
    {
        cout << arrb[i];
        cct_gotoxy(8, 24 - i);
    }
    for (int i = topb; i < 15; i++)
    {
        putchar(' ');
        cct_gotoxy(8, 23 - i);
    }
    cct_gotoxy(15, 27);
    cout << "C";
    cct_gotoxy(15, 26);
    cout << "======================";
    cct_gotoxy(15, 25);
    for (int i = 0; i < topc; i++)
    {
        cout << arrc[i];
        cct_gotoxy(15, 24 - i);
    }
    for (int i = topc; i < 15; i++)
    {
        putchar(' ');
        cct_gotoxy(15, 23 - i);
    }
    cct_gotoxy(1, 1);
    cout << "从" << the_first << "移动到" << the_end << ",共" << floor << "层,延时设置为" << choose1 << ",";
    if (choose2 == 0)
    {
        cout << "不显示内部数组";
    }
    else if (choose2 == 1)
    {
        cout << "显示内部数组";
    }
    cct_gotoxy(1, 30);
    cout << "                    ";
    cout << "第" << setw(4) << step_count << " 步(" << setw(2) << move << "): " << from << "-->" << to << " ";
}

void move(char from, char to, char the_first, char the_end, int choose1, int choose2, int floor)
{
    int mid = 0;

    if (from == 'A') {
        mid = arra[--topa];
    }
    else if (from == 'B') {
        mid = arrb[--topb];
    }
    else if (from == 'C') {
        mid = arrc[--topc];
    }

    if (to == 'A') {
        arra[topa++] = mid;
    }
    else if (to == 'B') {
        arrb[topb++] = mid;
    }
    else if (to == 'C') {
        arrc[topc++] = mid;
    }
    step_count++;
    print_condition(mid, from, to, the_first, the_end, choose1, choose2,floor);
}

void hanoi(int floor, char first, char tmp, char end, char the_first, char the_end, int choose1, int choose2,int the_floor)
{
    if (floor == 1)
    {
        move(first, end, the_first, the_end, choose1, choose2,the_floor);
    }
    if (floor > 1)
    {
        hanoi(floor - 1, first, end, tmp, the_first, the_end, choose1, choose2,the_floor);
        move(first, end, the_first, the_end, choose1, choose2,the_floor);
        hanoi(floor - 1, tmp, first, end, the_first, the_end, choose1, choose2,the_floor);
    }
}

void print_condition2(int move, char from, char to, char the_first, char the_end, int choose1, int choose2, int floor)
{
    cct_gotoxy(1, 1);
    cout << "从" << the_first << "移动到" << the_end << ",共" << floor << "层,延时设置为" << choose1 << ",";
    if (choose2 == 0)
    {
        cout << "不显示内部数组";
    }
    else if (choose2 == 1)
    {
        cout << "显示内部数组";
    }
    cct_gotoxy(1, 30);
    cout << "                    ";
    cout << "第" << setw(4) << step_count << " 步(" << setw(2) << move << "): " << from << "-->" << to << " ";

    if (choose1 == 0)
    {
        int ch = _getch();
        //cct_cls();
    }
    switch (choose1)
    {
        case 1:
            Sleep(1000);
            //cct_cls();
            break;
        case 2:
            Sleep(500);
            //cct_cls();
            break;
        case 3:
            Sleep(250);
            //cct_cls();
            break;
        case 4:
            Sleep(100);
            //cct_cls();
            break;
        case 5:
            Sleep(10);
            //cct_cls();
            break;
    }
    cct_gotoxy(1, 27);
    cout << "A";
    cct_gotoxy(1, 26);
    cout << "===========";
    cct_gotoxy(1, 25);
    for (int i = 0; i < topa; i++)
    {
        cout << arra[i];
        cct_gotoxy(1, 24 - i);
    }
    for (int i = topa; i < 15; i++)
    {
        putchar(' ');
        cct_gotoxy(1, 23 - i);
    }
    cct_gotoxy(8, 27);
    cout << "B";
    cct_gotoxy(8, 26);
    cout << "===========";
    cct_gotoxy(8, 25);
    for (int i = 0; i < topb; i++)
    {
        cout << arrb[i];
        cct_gotoxy(8, 24 - i);
    }
    for (int i = topb; i < 15; i++)
    {
        putchar(' ');
        cct_gotoxy(8, 23 - i);
    }
    cct_gotoxy(15, 27);
    cout << "C";
    cct_gotoxy(15, 26);
    cout << "===========";
    cct_gotoxy(15, 25);
    for (int i = 0; i < topc; i++)
    {
        cout << arrc[i];
        cct_gotoxy(15, 24 - i);
    }
    for (int i = topc; i < 15; i++)
    {
        putchar(' ');
        cct_gotoxy(15, 23 - i);
    }
    cct_gotoxy(1, 1);
    cout << "从" << the_first << "移动到" << the_end << ",共" << floor << "层,延时设置为" << choose1 << ",";
    if (choose2 == 0)
    {
        cout << "不显示内部数组";
    }
    else if (choose2 == 1)
    {
        cout << "显示内部数组";
    }
    cct_gotoxy(1, 30);
    cout << "                    ";
    cout << "第" << setw(4) << step_count << " 步(" << setw(2) << move << "): " << from << "-->" << to << " ";
}

void move2(char from, char to, char the_first, char the_end, int choose1, int choose2,int floor)
{
    int mid = 0;

    if (from == 'A') {
        mid = arra[--topa];
    }
    else if (from == 'B') {
        mid = arrb[--topb];
    }
    else if (from == 'C') {
        mid = arrc[--topc];
    }

    if (to == 'A') {
        arra[topa++] = mid;
    }
    else if (to == 'B') {
        arrb[topb++] = mid;
    }
    else if (to == 'C') {
        arrc[topc++] = mid;
    }
    step_count++;
    print_condition2(mid, from, to, the_first, the_end, choose1, choose2,floor);
}

void hanoi2(int floor, char first, char tmp, char end, char the_first, char the_end, int choose1, int choose2,int the_floor)
{
    if (floor == 1)
    {
        move2(first, end, the_first, the_end, choose1, choose2,the_floor);
    }
    if (floor > 1)
    {
        hanoi2(floor - 1, first, end, tmp, the_first, the_end, choose1, choose2,the_floor);
        move2(first, end, the_first, the_end, choose1, choose2,the_floor);
        hanoi2(floor - 1, tmp, first, end, the_first, the_end, choose1, choose2,the_floor);
    }
}

int main()
{
    int floor = 0;
    char first, end, tmp = 0;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> floor;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (floor < 1 || floor>16)
        {
            cin.ignore(1024, '\n');
        }
        if (floor >= 1 && floor <= 16)
        {
            cin.ignore(1024, '\n');
            break;
        }
    }
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> first;
        if (first == 'a')
        {
            first = 'A';
        }
        if (first == 'b')
        {
            first = 'B';
        }
        if (first == 'c')
        {
            first = 'C';
        }
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (first == 'A' || first == 'B' || first == 'C')
        {
            cin.ignore(1024, '\n');
            break;
        }
        if (first != 'A' && first != 'B' && first != 'C')
        {
            cin.clear();
            cin.ignore(1024, '\n');
        }
    }
    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> end;
        if (end == 'a')
        {
            end = 'A';
        }
        if (end == 'b')
        {
            end = 'B';
        }
        if (end == 'c')
        {
            end = 'C';
        }
        if (end == first)
        {
            cout << "目标柱" << "(" << end << ")" << "不能与" << "起始柱" << "(" << first << ")相同" << endl;
            cin.ignore(1024, '\n');
            continue;
        }
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (end == 'A' || end == 'B' || end == 'C')
        {
            cin.ignore(1024, '\n');
            break;
        }
        if (end != 'A' && end && 'B' && end != 'C')
        {
            cin.clear();
            cin.ignore(1024, '\n');
        }
    }
    innitialization(floor, first);
    if (first != 'A' && end != 'A')
    {
        tmp = 'A';
    }
    if (first != 'B' && end != 'B')
    {
        tmp = 'B';
    }
    if (first != 'C' && end != 'C')
    {
        tmp = 'C';
    }
    cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
    cin >> choose1;
    cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
    cin >> choose2;
    cct_cls();
    cct_gotoxy(1,30);
    cout << "                    ";
    if (choose2 == 1)
    {
        print_initialization(floor, first);
        if (choose1 == 0)
        {
            int ch = _getch();
        }
        switch (choose1)
        {
            case 1:
                Sleep(1000);
                break;
            case 2:
                Sleep(500);
                break;
            case 3:
                Sleep(250);
                break;
            case 4:
                Sleep(100);
                break;
            case 5:
                Sleep(10);
                break;
        }
        cct_cls();
        hanoi(floor, first, tmp, end,first,end,choose1,choose2,floor);
    }
    else if (choose2 == 0)
    {
        if (choose1 == 0)
        {
            int ch = _getch();
        }
        switch (choose1)
        {
            case 1:
                Sleep(1000);
                break;
            case 2:
                Sleep(500);
                break;
            case 3:
                Sleep(250);
                break;
            case 4:
                Sleep(100);
                break;
            case 5:
                Sleep(10);
                break;
        }
        cct_cls();
        hanoi2(floor, first, tmp, end, first, end, choose1, choose2,floor);
    }
    cct_gotoxy(35, 35);
    system("pause");
    return 0;
}

