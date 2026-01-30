/*2452654 郭炫君 电信*/

/* 允许按需加入系统的宏定义、需要的头文件等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//定义文件名的最大长度

/* stu_metge 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_merge {
private:
	int  stu_no;					//学号
	char stu_name[MAX_NAME_LEN];  //姓名
	bool round1;
	bool round2;

	friend class stu_list;
	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */

public:
	//本类不允许定义任何的公有数据成员及成员函数
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//第一轮选课的学生名单（不排序、不去重）
	int list_num_1;						//第一轮选课的学生人数

	student list_round_2[MAX_STU_NUM];	//第二轮选课的学生名单（不排序、不去重）
	int list_num_2;						//第二轮选课的学生人数

	stu_merge list_merge[MAX_STU_NUM];	//合并后的学生名单（去重，按升序排列）
	int list_merge_num;					//合并后的学生人数（目前不打印，但可用于内部管理，如果不需要，也不要删除）

	/* 允许按需加入private数据成员和成员函数
	   注意，不允许加入array / set / map / vector等STL容器 */
	void merge_and_sort()
	{
		list_merge_num = 0;
		//添加第一轮名单
		for (int i = 0; i < list_num_1; i++) {
			int no = list_round_1[i].no;
			if (!exist_in_merge(no)) {
				assign_merge(list_merge[list_merge_num], list_round_1[i], true, false);
				list_merge_num += 1;
			}
		}

		//添加第二轮名单
		for (int i = 0; i < list_num_2; i++) {
			int no = list_round_2[i].no;
			int pos = find_in_merge(no);
			if (pos != -1)
				list_merge[pos].round2 = true;
			else {
				assign_merge(list_merge[list_merge_num], list_round_2[i], false, true);
				list_merge_num++;
			}
		}

		//进行冒泡排序
		for (int i = 0; i < list_merge_num - 1; i++) {
			for (int j = 0; j < list_merge_num - i - 1; j++) {
				if (list_merge[j].stu_no > list_merge[j + 1].stu_no) {
					stu_merge temp = list_merge[j];
					list_merge[j] = list_merge[j + 1];
					list_merge[j + 1] = temp;
				}
			}
		}
	}

	bool exist_in_merge(int no) {
		for (int i = 0; i < list_merge_num; i++) {
			if (list_merge[i].stu_no == no)
				return true;
		}
		return false;
	}

	//将学号和姓名复制给合并菜单,并补充是否参加的标记
	void assign_merge(stu_merge& dst, const student& src, bool r1, bool r2)
	{
		dst.stu_no = src.no;//
		strcpy(dst.stu_name, src.name);
		dst.round1 = r1;
		dst.round2 = r2;
	}

	int find_in_merge(int no)
	{
		for (int i = 0; i < list_merge_num; i++) {
			if (list_merge[i].stu_no == no) {
				return i;
			}
		}
		return -1;
	}

public:
	stu_list();										//构造函数，按需完成初始化功能，如果不需要，保留空函数即可
	int read(const char* filename, const int round);	//从文件中读入选课信息，round为1/2，表示选课轮次
	int print(const char* prompt = NULL);				//打印最终的选课名单

	/* 允许按需加入其它public成员函数（提示：合并、去重、排序等）
	   不允许定义公有的数据成员
	   不允许在成员函数中使用array / set / map / vector等STL容器 */

};

/* --- 下面可以给出stu_merge/stu_list两个类的成员函数的体外实现 --- */


/***************************************************************************
  函数名称：
  功    能：从文件中读入选课信息，round为1/2，表示选课轮次
  输入参数：
  返 回 值：
  说    明：构造函数，按需完成初始化功能，如果不需要，保留空函数即可
***************************************************************************/
stu_list::stu_list()
{
	list_num_1 = 0;
	list_num_2 = 0;
	list_merge_num = 0;

	for (int i = 0; i < MAX_STU_NUM; ++i) {
		list_round_1[i].no = 0;
		list_round_2[i].no = 0;
		list_round_1[i].name[0] = '\0';
		list_round_2[i].name[0] = '\0';
	}

	// 初始化 list_merge
	for (int i = 0; i < MAX_STU_NUM; ++i) {
		list_merge[i].stu_no = 0;
		list_merge[i].stu_name[0] = '\0';
		list_merge[i].round1 = false;
		list_merge[i].round2 = false;
	}
}

/***************************************************************************
  函数名称：
  功    能：演示静态链接库的使用，本函数中调用静态链接库中的预置函数
  输入参数：
  返 回 值：
  说    明：本函数不需要修改 
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* 读取第1/2轮的选课名单并打印 */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("第一轮选课名单：", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("第二轮选课名单：", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：打印最终的选课名单
***************************************************************************/
int stu_list::print(const char* prompt)
{
	if (prompt)
		cout << prompt;
	cout << endl;
	merge_and_sort();

	int max_name_len = 0;
	for (int i = 0; i < list_merge_num; ++i) {
		int len = strlen(list_merge[i].stu_name);
		if (len > max_name_len)
			max_name_len = len;
	}

	cout << setiosflags(ios::left);
	cout << setfill('=') << setw(33 +  max_name_len)<<"=" << endl;
	cout <<setfill(' ')<< " 序号  学号     " << setw(max_name_len) << "姓名" << "  第一轮  第二轮" << endl;
	cout << setfill('=') << setw(33 +  max_name_len) <<"="<< endl;
	cout << setfill(' ') ;
	for (int i = 0; i < list_merge_num; i++) {
		cout << " " << setw(4) << i + 1 << "  " << list_merge[i].stu_no << "  "
			<<setw(max_name_len)<<list_merge[i].stu_name<<"  ";

		if (list_merge[i].round1) {
			cout << setw(6) << "Y"<<"  ";
			if (list_merge[i].round2)
				cout << setw(6) << "Y";
			else
				cout << setw(6) << "退课";
		}
		else
			cout << setw(6) << "/" <<"  "<< setw(6) << "补选";
		cout << " " << endl;
	}
	cout << setfill('=') << setw(33 + max_name_len) << "=" << endl;
	
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	gets_s(file1); //cin不能读有空格的文件

	cout << "请输入后一轮选课的数据文件 : ";
	gets_s(file2);

	stu_list list;

	/* 读入数据 */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* 处理数据 */


	/* 打印 */
	list.print("最终选课名单");

	return 0;
}

