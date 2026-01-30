/*2452654 郭炫君 电信*/
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
			char ch    ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
void menu(const HANDLE hout)
{
	cls(hout);
	gotoxy(hout, 0, 0);
	printf("1.用I、J、K、L键控制上下左右(大小写均可，按左箭头光标不允许下移，边界停止)\n");
	printf("2.用I、J、K、L键控制上下左右(大小写均可，按左箭头光标不允许下移，边界回绕)\n");
	printf("3.用箭头键控制上下左右（按大写HPKM不允许移动光标，边界停止）\n");
	printf("4.用箭头键控制上下左右（按大写HPKM不允许移动光标，边界回绕）\n");
	printf("0.退出");
	printf("[请选择0-4]");
}

void move_by_ijkl(const HANDLE hout, int mode) {
	cls(hout);
	init_border(hout);
	int x = MAX_X / 2, y = MAX_Y / 2;
	gotoxy(hout, x, y);
	while (1) {
		int new_x = x, new_y = y;
		int ch = _getch();
		if (ch == 224 || ch == 0) {
			int jiantou = _getch(); // 丢弃第二个键值，输入左箭头时不会下移
			continue;
		}
		switch (tolower(ch)) {
			case 'i':
				new_y -= 1;
				break;
			case 'j':
				new_x -= 1;
				break;
			case 'k':
				new_y += 1;
				break;
			case 'l':
				new_x += 1;
				break;
			case ' ': //空格
				showch(hout, x, y, ' ');
				gotoxy(hout, new_x, new_y);
				break;
			case 'q': //Q
				gotoxy(hout, 0, MAX_Y + 6);
				printf("游戏结束，按回车键返回菜单.");
				while (_getch() != '\r');
				return;

		}
		if (mode == 1) {
			if (new_x > 0 && new_x <= MAX_X && new_y > 0 && new_y <= MAX_Y) {
				x = new_x;
				y = new_y;
			}
		}
		else {
			if (new_x < 1)
				new_x = MAX_X;
			else if (new_x > MAX_X)
				new_x = 1;
			else if (new_y < 1)
				new_y = MAX_Y;
			else if (new_y > MAX_Y)
				new_y = 1;
			x = new_x;
			y = new_y;
		}
		gotoxy(hout, x, y);
	}
}

void move_by_arrow(const HANDLE hout, int mode)
{
	cls(hout);
	init_border(hout);
	int x = MAX_X / 2, y = MAX_Y / 2;
	gotoxy(hout, x, y);
	int new_x = x, new_y = y;
	while (1) {
		int ch = _getch();
		if (ch == 0 || ch == 224) {
			ch = _getch();
			switch (ch) {
				case 72:  // 上箭头
					new_y -= 1;
					break;
				case 80:  //下箭头
					new_y += 1;
					break;
				case 75:  //左箭头
					new_x -= 1;
					break;
				case 77:  //右箭头
					new_x += 1;
					break;
			}
		}
		else if (ch == 'q' || ch == 'Q') {
			gotoxy(hout, 0, MAX_Y + 6);
			printf("游戏结束，按回车键返回菜单.");
			while (_getch() != '\r');
			return;
		}
		else if (ch == ' ')
			showch(hout, x, y, ' ');
		if (mode == 3) {
			if (new_x > 0 && new_x <= MAX_X) {
				x = new_x;
			}
			else
				new_x = x;//防止到达边界后new_x继续增加导致换方向之后光标不动
			if (new_y > 0 && new_y <= MAX_Y) {
				y = new_y;
			}
			else
				new_y = y;
		}
		else {
			if (new_x < 1)
				new_x = MAX_X;
			else if (new_x > MAX_X)
				new_x = 1;
			else if (new_y < 1)
				new_y = MAX_Y;
			else if (new_y > MAX_Y)
				new_y = 1;
			x = new_x;
			y = new_y;
		}
		gotoxy(hout, x, y);
	}
}

int get_mode(const HANDLE hout)
{
	while (1) {
		int ch = _getch();
		if (ch >= '0' && ch <= '4') {
			return ch - '0';
		}
		else
			cls(hout);
		menu(hout);
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));

	while (1) {
		menu(hout);
		int mode = get_mode(hout);
		if (mode == 0)
			break;
		else if (mode == 1 || mode == 2)
			move_by_ijkl(hout, mode);
		else
			move_by_arrow(hout, mode);
	}

	/* 此句的作用是调用系统的cls命令清屏 */
//	cls(hout);

	/* 显示初始的边框及其中的随机字符 */
//	init_border(hout);

	//暂停

	return 0;
}