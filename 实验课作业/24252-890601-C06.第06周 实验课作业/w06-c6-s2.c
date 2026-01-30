/* 2452654 郭炫君 电信 */ 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//此处加入需要的头文件

const double pi=3.14159 ;
int main()
{
	/* 这些是输入输出提示的字符串，供大家复制到所需位置，避免细节差异 */ 
	int r,x,y,start_angle,end_angle;
	printf("请输入圆心x坐标 [-100..100] : ");
	scanf("%d",&x);
	printf("请输入圆心y坐标 [-100..100] : ");
	scanf("%d",&y);
	printf("请输入圆半径r [1..100] : ");
	scanf("%d",&r);
	printf("请输入起点(旧家)角度 [0..360) : ");
    scanf("%d", &start_angle);
    printf("请输入终点(新家)角度 [0..360) : ");
    scanf("%d", &end_angle);
    double start_rad = (90 - start_angle) * pi / 180;
    double end_rad = (90 - end_angle) * pi / 180;
	double old_x = x + r * cos(start_rad);
    double old_y = y + r * sin(start_rad);
    double new_x = x + r * cos(end_rad);
    double new_y = y + r * sin(end_rad);
	printf("旧家坐标 : (%.2f, %.2f)\n", old_x, old_y);
    printf("新家坐标 : (%.2f, %.2f)\n", new_x, new_y);

	return 0;
}
