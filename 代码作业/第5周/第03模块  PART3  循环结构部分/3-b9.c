//2452654 ¹ùìÅ¾ı µçĞÅ
#include <stdio.h>
#include <math.h>
int main()
{
	int i, j,result;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= i; j++) {
			result = i * j;
			printf("%dx%d=%d", j, i, result);

			if (result < 10)
				printf("   ");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("\n");


	return 0;
}