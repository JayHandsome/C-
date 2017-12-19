/*
【问题描述】按字符串比较过程对给定的两个字符串进行比较，若相等则结果为0，若不等则结果为对应不等字符的差。按要求实现对给定字符串的比较。要求程序中用函数实现两个字符串的比较。int stringcmp(char *str1 ,char *str2 )
【输入形式】第一行为一个整数N，表示测试数据的组数，接下来的N行中每行包含两个字符串，字符串之间由空格分隔。
【输出形式】输出共N行，每行为对应输入一行的两个字符串的比较结果。
【样例输入】3
                    Happy Help
                    Help Help
                    Help Happy
【样例输出】- 4
                    0
                    4
【样例说明】测试3组字符串。第1组为&ldquo;Happy&rdquo;和"Help",第2组为&ldquo;Help&rdquo;和&ldquo;Help&rdquo;，第3组为&ldquo;Help&rdquo;和&ldquo;Happy&rdquo;，比较结果分别为-4、0和4。
*/
#include<stdio.h>
#include<string.h>
int stringcmp(char *str1, char *str2){
	int len_s1, len_s2;
	len_s1 = strlen(str1);
	len_s2 = strlen(str2);
	for(; *str1 != '\0' || *str2 != '\0'; str1++, str2++){
		if(*str1 != *str2){
			return (*str1 - *str2);
		}
	}
	return 0;
}
int main(){
	int N, i;
	char str1[30], str2[30];
	int result;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%s%s", str1, str2);
		result = stringcmp(str1, str2);
		printf("%d\n", result);
	} 
	return 0;
} 
