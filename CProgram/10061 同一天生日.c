/*
【问题描述】在一个有200人的大班级中，存在两个人生日相同的概率非常大，现给出每个学生的学号，出生月日，试找出所有生日相同的学生。
【输入形式】第一行为整数n，表示有n个学生，n<=200。此后每行包含一个字符串和两个整数，分别表示学生的学号(字符串长度为11位)和出生月(1<=m<=12)日(1<=d<=31)，学号、月、日之间用一个空格分隔。
【输出形式】对每组生日相同的学生，输出一行，其中前两个数字表示月和日，后面跟着所有在当天出生的学生的学号，数字、学号之间都用一个空格分隔。对所有的输出，要求按日期从前到后的顺序输出。对生日相同的学号，按输入的顺序输出。
【样例输入】6
                   07101020105 3 15
                   07101020115 4 5
                   07101020118 3 15
                   07101020108 4 5
                   07101020111 4 5
                   07101020121 8 10
【样例输出】3 15 07101020105 07101020118
                    4 5 07101020115 07101020108 07101020111

                    8 10 07101020121
【样例说明】输出样例如上。
*/
#include<stdio.h>
#include<string.h>
int main(){
	int n, i, j, temp;
	int month[200], day[200], sum[200], temp_month, temp_day;
	char number[200][20], temp_char[20];
	
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%s%d%d", number[i], &month[i], &day[i]);
		sum[i] = month[i] * 100 + day[i];
	}
	for(i = 0; i < n; i++){
		 
		for(j = 0; j < n - i - 1; j++){
			if(sum[j] > sum[j + 1]){
				strcpy(temp_char, number[j]); 
				strcpy(number[j], number[j+1]); 
				strcpy(number[j+1], temp_char); 
				
				temp_month = month[j];
				month[j] = month[j+1];
				month[j+1] = temp_month;
				
				temp_day = day[j];
				day[j] = day[j+1];
				day[j+1] = temp_day;
				
				temp = sum[j];
				sum[j] = sum[j+1];
				sum[j+1] = temp;
			}
		}
	}
	printf("%d %d %s ", month[0], day[0], number[0]);
	for(i = 1; i < n; i++){
		if(sum[i] == sum[i-1]){
			printf("%s ", number[i]);
		}
		else{
			
			printf("\n%d %d %s ", month[i], day[i], number[i]);
		}
	}
	return 0;
} 
