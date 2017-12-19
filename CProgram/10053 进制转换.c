/*
【问题描述】对输入的两个十六进制数(两个字符串)，将其转换成十进制后再求和。要求十六进制到十进制的转换功能由函数完成。例如：输入3a1转换为十进制后为929，80转换为十进制后为128，所以和为1057。
【输入形式】输入包括两行，每行为一个十六进制数。注意：本题中的十六进制数中的英文字符以小写字母表示。
【输出形式】输出包括一行，为两数之和的十进制表示。
【样例输入】3a1
						80
【样例输出】1057
【样例说明】16进制数3a1和80转换为10进制数之后的和为1057(输出该数时后面不加换行符)。
*/
#include<stdio.h>
#include<math.h>

int main() {
	char ch1[10], ch2[10];
	int sum = 0, length1, length2;
	int i;
	scanf("%s%s", ch1, ch2);

	i = 0;
	while (ch1[i] != '\0') {
		i++;

	}
	length1 = i; //获取ch1的长度

	i = 0;
	while (ch2[i] != '\0') {
		i++;

	}
	length2 = i; //获取ch2的长度

	for (i = length1 - 1; i >= 0; i--) {
		if (ch1[i] >= 'a' && ch1[i] <= 'f') {
			sum = sum + ((ch1[i] - 'a') + 10) * pow(16, length1 - 1 - i);

		}
		else {
			sum = sum + (ch1[i] - '0') * pow(16, length1 - 1 - i);

		}

	}

	for (i = length2 - 1; i >= 0; i--) {
		if (ch2[i] >= 'a' && ch2[i] <= 'f') {
			sum = sum + ((ch2[i] - 'a') + 10) * pow(16, length2 - 1 - i);

		}
		else {
			sum = sum + (ch2[i] - '0') * pow(16, length2 - 1 - i);

		}

	}
	printf("%d", sum);
	return 0;

}