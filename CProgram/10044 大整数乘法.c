/*
【问题描述】求两个不超过200位的非负整数的积。
【输入形式】有两行，每行是一个不超过200位的非负整数，没有多余的前导。
【输出形式】一行，即相乘后的结果。结果不能有多余的前导0，即如果结果是342，那么就不能输出为0342。
【样例输入】12345678900
98765432100
【样例输出】1219326311126352690000
【样例说明】这两个大整数相乘所得的结果是1219326311126352690000。
*/
#include<stdio.h>
#include<string.h> //使用函数strlen 
int main() {
	char str1[200], str2[200];
	int Mut[400] = { 0 };
	int n, m, i, j, k, t;
	int temp;
	scanf("%s%s", &str1, &str2);
	n = strlen(str1);
	m = strlen(str2);
	k = 0;
	for (i = n - 1; i >= 0; i--) {
		for (j = m - 1, t = 0; j >= 0; j--, t++) {
			temp = (str1[i] - '0') * (str2[j] - '0');
			//    printf("str1[%d] = %c str2[%d] = %c temp = %d \n", i, str1[i], j, str2[j], temp);
			Mut[t + k] += temp;
			Mut[t + 1 + k] += (Mut[t + k] / 10);
			Mut[t + k] = Mut[t + k] % 10;
			//    printf("Mut[%d + %d] = %d Mut[%d + %d + 1] = %d \n\n", t, k, Mut[t + k], t, k, Mut[t + k +1 ]);
		}
		k++;
	}
	for (i = 399; Mut[i] == 0 && i >= 0; i--) {

	}
	temp = i;
	for (i = temp; i >= 0; i--) {
		printf("%d", Mut[i]);
	}
	printf("\n");
	return 0;
}
