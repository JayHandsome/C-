/*
【问题描述】判断一个由a-z 这26个字符组成的字符串中哪个字符出现的次数最多。
【输入形式】第1行是测试数据的组数n,每组测试数据占1行，是一个由a-z这26个字符组成的字符串，每行数据不超过
                        1000个字符且非空。
【输出形式】输出n行，每行输出对应一个输入。一行输出包括出现次数最多的字符和该字符出现的次数，中间是一个
                        空格。如果有多个字符出现的次数相同且最多，那么输出ASCII码最小的那一个字符。
【样例输入】2
           abbccc
           adfadffasdf
【样例输出】c 3
            f 4
【样例说明】输出样例如上。
*/
#include<stdio.h>
int main(){
	int n, i, j;
	char str[20][1000];
	int sum_s[20][26] = {0}, max[20][2] = {0};
	scanf("%d", &n);
	getchar(); //吃回车 
	for(i = 0; i < n; i++){
		gets(str[i]);
	}
	
	for(i = 0; i < n; i++){
		for(j = 0;str[i][j] != '\0'; j++){
			sum_s[i][str[i][j] - 'a'] ++; //对应字母累加
		}
	}
	
	for(i = 0; i < n; i++){
		for(j = 0; j < 26; j++){
			if(sum_s[i][j] > max[i][1]){
				max[i][0] = j; //传字母 
				max[i][1] = sum_s[i][j]; //传个数 
			}
		}
	}
	
	for(i = 0; i < n; i++){
		printf("%c %d\n", max[i][0] + 'a', max[i][1]);
	}
	return 0;
}
