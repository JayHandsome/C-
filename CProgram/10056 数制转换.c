/*
问题描述】求任意两个不同进制非负整数的转换（2进制~16进制），所给整数在long所能表达的范围之内。
不同进制的表示符号为(0，1，....，9，A，B，C，D，E，F)。
注意：不同进制可能不能直接转换，如八进制与十六进制。
可以考虑不同进制与十进制的转换，即借助于十进制实现任意两个不同进制的转换。
【输入形式】输入只有一行，包含三个整数a，n，b。a表示其后的n是a进制整数，
b表示欲将a进制整数n转换成b进制整数。a，b是十进制整数，且2=<a，b<=16。
【输出形式】输出包含一行，为转换后的b进制整数。输出时字符号全部用大写表示，
即（0 ，1，...，9，A，B，C，D，E，F）。
【样例输入】15 AAB3 7
【样例输出】210305
【样例说明】15进制的数AAB3，转换为7进制后的数为210306。
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	int a, b;
	char in_data[20], out_data[20];
	int length, i, sum = 0;
	int k, remainder; //定义余数 
	scanf("%d%s%d", &a, in_data, &b);
	
	length = strlen(in_data);
	for(i = length - 1; i >= 0; i--){ //转换为10进制数 
		if (in_data[i] >= 'A' && in_data[i] <= 'F') {
			sum = sum + ((in_data[i] - 'A') + 10) * pow(a, length - 1 - i);

		}
		else {
			sum = sum + (in_data[i] - '0') * pow(a, length - 1 - i);

		}
	}
	k = 0;
	for(i = 0; sum != 0; i++){
		remainder = sum % b; //求余数
		sum = sum / b; //求商 
		if(remainder >= 10){
			out_data[k] = (remainder - 10) + 'A';
		}
		else{
			out_data[k] = remainder + '0';
		}
		k++;
	} 
	for(i = k-1; i >= 0; i--){
		printf("%c", out_data[i]);
	}
	return 0;
}
