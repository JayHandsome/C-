/*
【问题描述】一般我们用strcmp可比较两个字符串的大小，比较方法为对两个字符串从前往后逐个字符比较（按
                        ASCII码值大小比较），直到出现不同的字符或遇到;
						为止。如果全部字符都相同，则认为相同；
                        如果出现不相同的字符，则以第一个不相同的字符的比较结果为准。但在有些时候，我们比较字符串
                        的大小时，希望忽略字母的大小，例如"Hello"和"hello"在忽略字母大小写时是相等的。请写一个程序，
                        实现对两个字符串进行忽略字母大小写的大小比较。
【输入形式】输入为两行，每行一个字符串，共两个字符串。(用gets录入每行字符串，每个字符串长度都小于80。)
【输出形式】如果第一个字符串比第二个字符串小，输出一个字符'<'；
                        如果第一个字符串比第二个字符串大，输出一个字符'>'；
                        如果两个字符串相等，输出一个字符'='。
【样例输入】Hello
                        hello
【样例输出】=
【样例说明】样例的两个字符串相等。
*/
#include<stdio.h>
#include<string.h>
int main(){
	char str1[80], str2[80];
	int length_str1, length_str2, i;
	gets(str1);
	gets(str2);
	length_str1 = strlen(str1);
	length_str2 = strlen(str2);
	for(i = 0; str1[i] != '\0' || str2[i] != '\0'; i++){
		if(str1[i] >= 'A' && str1[i] <= 'Z'){
			str1[i] = str1[i] - 'A' + 'a'; 
		}
		if(str2[i] >= 'A' && str2[i] <= 'Z'){
			str2[i] = str2[i] - 'A' + 'a'; 
		}
		if(str1[i] > str2[i]){
			printf(">");
			return 0;
		}
		if(str1[i] < str2[i]){
			printf("<");
			return 0;
		}
	}
	if(length_str1 == length_str2){
		printf("=");
	}
	else if(length_str1 > length_str2){
		printf(">");
	}
	else{
		printf("<");
	}
	return 0;
} 
