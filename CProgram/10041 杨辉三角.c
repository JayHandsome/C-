/*
【问题描述】打印出杨辉三角形的前n行。
【输入形式】输入一个正整数n(n<20)。
【输出形式】杨辉三角形，每个输出的数后面跟一个空格。
【样例输入】5
【样例输出】
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
【样例说明】输入5时，打印如上图的杨辉三角形。
*/
#include<stdio.h>
int main() {
	int n, i, j;
	int data[20][20];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			if (j == 0) {
				data[i][j] = 1;

			}
			else if (i == j) {
				data[i][j] = 1;
			}
			else {
				data[i][j] = data[i - 1][j - 1] + data[i - 1][j];
			}
			printf("%d ", data[i][j]);
		}
		printf("\n");
	}
	return 0;
}
