/*
【问题描述】已知矩阵A(m*n)和B(n*p)，求C=A*B。
【输入形式】第一行三个整数为m,n,p（m,n,p均小于10），从第二行开始为m行n列A矩阵，然后为n行p列的B矩阵。
所有数据之间均由一个空格分隔。
【输出形式】输出m行p列的C矩阵，所有数据之间均由一个空格分隔，输出的每一个数据后面跟一个空格。
【样例输入】2 3 4
1 0 3
3 4 0
1 0 2 1
2 3 4 5
2 1 1 5
【样例输出】7 3 5 16
11 12 22 23
【样例说明】最后得到的2行4列的矩阵如上图所示。
*/
#include<stdio.h>

int main() {
	int m, n, p, i, j, k, sum;
	int A[10][10], B[10][10], C[10][10];
	scanf("%d%d%d", &m, &n, &p);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < p; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < p; j++) {
			sum = 0;
			for (k = 0; k < n; k++) {
				sum = A[i][k] * B[k][j] + sum;
			}
			C[i][j] = sum;
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
	return 0;
}
