/*2452654 郭炫君 电信*/
#include <iostream>
#include <string>
#include <cmath>
//可按需增加需要的头文件
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/
void daxie(int num, bool flag_of_zero)
{
    if (num == 0) {
		if (flag_of_zero) {
			char a[3] = {chnstr[0],chnstr[1],'\0'};
			result += a;
		}
    }
    else {
		char a[3] = { chnstr[2 * num],chnstr[2 * num + 1],'\0' };
        result += a;
    }
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
    /* --允许添加需要的内容 --*/
	double number, frac, integer;
	bool flag_of_zero = 1;
	while (1) {
		cout << "请输入[0-100亿)之间的数字:" << endl;
		cin >> number;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else if(number<0 || number>10000000000){
			continue;
		}
		else {
			break;
		}
	}
	cout << "大写结果是:" << endl;
	frac = modf(number, &integer);
	int b, c, d, e, f, g, h, i, j, k, l, m, n;
	b = static_cast<int>(integer / 1e9);
	integer -= b * 1e9;
	c = static_cast<int>(integer / 1e8);
	integer -= c * 1e8;
	d = static_cast<int>(integer / 1e7);
	integer -= d * 1e7;
	e = static_cast<int>(integer / 1e6);
	integer -= e * 1e6;
	f = static_cast<int>(integer / 1e5);
	integer -= f * 1e5;
	g = static_cast<int>(integer / 1e4);
	integer -= g * 1e4;
	h = static_cast<int>(integer / 1e3);
	integer -= h * 1e3;
	i = static_cast<int>(integer / 1e2);
	integer -= i * 1e2;
	j = static_cast<int>(integer / 1e1);
	integer -= j * 1e1;
	k = static_cast<int>(integer / 1e0);
	integer -= k * 1e0;
	l = static_cast<int>(round(frac * 100));
	m = static_cast<int>(l / 10);
	n = static_cast<int>((l - m * 10));//见3-b3-2
	if (b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0 || k > 0) {
		int yi = b * 10 + c;     //先处理亿位
		if (yi > 0) {
			int shi = b;
			if (shi > 0) {               //亿位的十位
				daxie(static_cast<int>(shi), flag_of_zero);
				result+= "拾";
			}
			yi -= shi * 10;
			if (yi > 0) {                   //亿位的个位
				daxie(static_cast<int>(yi), flag_of_zero);
			}
			result += "亿";
		}

		int wan = d * 1000 + e * 100 + f * 10 + g;  //处理万位
		if (wan > 0) {
			int qian = wan / 1000;  //万位的千位
			if (qian > 0) {
				daxie(qian, flag_of_zero);
				result += "仟";
			}
			else if (c > 0) {     //亿位大于0
				daxie(qian, flag_of_zero);
				flag_of_zero = 0;
			}
			wan %= 1000;

			int bai = wan / 100;  //万位的百位
			if (bai > 0) {
				daxie(bai, flag_of_zero);
				result += "佰";
				flag_of_zero = 1;
			}
			else if (flag_of_zero && qian > 0 && wan % 1000 != 0) {
				daxie(bai, flag_of_zero);
				flag_of_zero = 0;
			}
			wan %= 100;

			int shi = wan / 10;  //万位的十位
			if (shi > 0) {
				daxie(shi, flag_of_zero);
				result += "拾";
				flag_of_zero = 1;
			}
			else if (bai > 0 && flag_of_zero && wan % 100 != 0) {
				daxie(shi, flag_of_zero);
				flag_of_zero = 0;
			}
			wan %= 10;

			if (wan > 0) {        //万位的个位
				daxie(wan, flag_of_zero);
				flag_of_zero = 1;
			}                       //如果个位是0，只有万位全为0才输出零，但在千位就会输出
			result += "万";
		}

		int yuan = h * 1000 + i * 100 + j * 10 + k;
		int qian = h; //处理元位
		if (qian > 0) {           //元位的千位
			daxie(qian, flag_of_zero);
			flag_of_zero = 1;
			result += "仟";
		}
		else if (((b * 10 + c) != 0 || (d * 1000 + e * 100 + f * 10 + g) != 0) && flag_of_zero && yuan != 0) {
			daxie(qian, flag_of_zero);
			flag_of_zero = 0;
		}

		int bai = i;   //元位的百位
		if (bai > 0) {
			daxie(bai, flag_of_zero);
			flag_of_zero = 1;
			result +=  "佰";
		}
		else if (qian > 0 && flag_of_zero && yuan % 1000 != 0) {
			daxie(bai, flag_of_zero);
			flag_of_zero = 0;
		}

		int shi = j;  //元位的十位
		if (shi > 0) {
			daxie(shi, flag_of_zero);
			flag_of_zero = 1;
			result += "拾";
		}
		else if (bai > 0 && flag_of_zero && yuan % 100 != 0) {
			daxie(shi, flag_of_zero);
			flag_of_zero = 0;
		}

		if (k > 0) {     //元位的个位
			daxie(k, flag_of_zero);
		}
		result += "圆";
	}
	else if (frac == 0) {
		daxie(0, flag_of_zero); //全为0输出零元
		result += "圆";
	}

	if (frac > 0) {
		flag_of_zero = 1;
		int jiao = m;
		int fen = n;
		if (jiao > 0) {
			daxie(jiao, flag_of_zero);
			result += "角";
			flag_of_zero = 1;
		}
		else if (jiao==0&& fen > 0 && (b > 0 || c > 0 || d > 0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0 || k > 0))
			daxie(0,1);
		if (fen > 0) {
			daxie(fen, flag_of_zero);
			result += "分";
		}
		else {
			result += "整";
		}

	}
	else
		result += "整";

    cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}