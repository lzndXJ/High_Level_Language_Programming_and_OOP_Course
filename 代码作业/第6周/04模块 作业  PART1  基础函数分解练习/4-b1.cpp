/* 2452654 郭炫君 电信*/
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	cout << "请输入[0-100亿)之间的数字:" << endl;
	double number,frac,integer;
	bool flag_of_zero=1;
	cin >> number;
	cout << "大写结果是:" << endl;
	frac = std::modf(number, &integer);
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
	l = static_cast<int>(std::round(frac * 100));
	m = static_cast<int>(l / 10);
	n = static_cast<int>((l - m * 10));//见3-b3-2
	if (b > 0 || c>0 || d >0 || e > 0 || f > 0 || g > 0 || h > 0 || i > 0 || j > 0 || k > 0) {
		int yi = b*10+c;     //先处理亿位
		if (yi > 0) {
			int shi = b;
			if (shi > 0) {               //亿位的十位
				daxie(static_cast<int>(shi), flag_of_zero);
				cout << "拾";
			}
			yi -= shi * 10;
			if (yi > 0) {                   //亿位的个位
				daxie(static_cast<int>(yi), flag_of_zero);
			}
			cout << "亿";
		}

		int wan = d*1000+e*100+f*10+g;  //处理万位
		if (wan > 0) {
			int qian = wan / 1000;  //万位的千位
			if (qian > 0) {
				daxie(qian, flag_of_zero);
				cout << "仟";
			}
			else if (c > 0) {     //亿位大于0
				daxie(qian, flag_of_zero);
				flag_of_zero = 0;
			}
			wan %= 1000;

			int bai = wan / 100;  //万位的百位
			if (bai > 0) {
				daxie(bai, flag_of_zero);
				cout << "佰";
				flag_of_zero = 1;
			}
			else if (flag_of_zero &&qian>0&& wan % 1000 != 0) {
				daxie(bai, flag_of_zero);
				flag_of_zero = 0;
			}
			wan %= 100;

			int shi = wan / 10;  //万位的十位
			if (shi > 0) {
				daxie(shi, flag_of_zero);
				cout << "拾";
				flag_of_zero = 1;
			}
			else if (bai>0&&flag_of_zero && wan % 100 != 0) {
				daxie(shi, flag_of_zero);
				flag_of_zero = 0;
			}
			wan %= 10;

			if (wan > 0) {        //万位的个位
				daxie(wan, flag_of_zero);
				flag_of_zero = 1;
			}                       //如果个位是0，只有万位全为0才输出零，但在千位就会输出
			cout << "万";
		}

		int yuan = h * 1000 + i * 100 + j * 10 + k;
		int qian = h; //处理元位
		if (qian > 0) {           //元位的千位
			daxie(qian, flag_of_zero);
			flag_of_zero = 1;
			cout << "仟";
		}
		else if ((yi!=0 || wan!=0) && flag_of_zero && yuan != 0) {
			daxie(qian, flag_of_zero);
			flag_of_zero = 0;
		}

		int bai = i;   //元位的百位
		if (bai > 0) {
			daxie(bai, flag_of_zero);
			flag_of_zero = 1;
			cout << "佰";
		}
		else if (qian>0&&flag_of_zero && yuan % 1000 != 0) {
			daxie(bai, flag_of_zero);
			flag_of_zero = 0;
		}

		int shi = j;  //元位的十位
		if (shi > 0) {
			daxie(shi, flag_of_zero);
			flag_of_zero = 1;
			cout << "拾";
		}
		else if (bai>0&&flag_of_zero && yuan % 100 != 0) {
			daxie(shi, flag_of_zero);
			flag_of_zero = 0;
		}

		if (k > 0) {     //元位的个位
			daxie(k, flag_of_zero);
		}
		cout << "圆";
	}
	else if (frac==0){
		daxie(0, flag_of_zero); //全为0输出零元
		cout << "圆";
	}
		
	if (frac > 0) {
		flag_of_zero = 1;
		int jiao = m;
		int fen = n;
		if (jiao > 0) {
			daxie(jiao, flag_of_zero);
			cout << "角";
		}
		else if (fen > 0 && integer > 0)
			daxie(jiao, flag_of_zero);
		if (fen > 0) {
			daxie(fen, flag_of_zero);
			cout << "分";
		}
		else {
			cout << "整";
		}

	}
	else
		cout << "整";
	cout << endl;

	/* 按需完成 */
	return 0;
}
