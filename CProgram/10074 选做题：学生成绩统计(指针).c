/*
【问题描述】某班有N(N<=30)个学生，共开设5门课程，分别用三个函数实现如下功能：

                    （1）求第一门课程的平均分；
                    （2）找出有2门及2门以上不及格的学生，并输出其学号；
                    （3）找出平均成绩在90分以上的学生，输出他们的学号。
【输入形式】第一行为一个整数N，表示本班共N个人，接下来的N行中每行包含一个学生的信息，包括学号(长度小于10的字符串)、课程1成绩、课程2成绩、课程3成绩、课程4成绩、课程5成绩。成绩均为整数。
【输出形式】输出共三行：

 第一行为本班第一门课程的平均成绩。(保留小数点后两位)

 第二行为有2门及2门以上不及格的学生的学号，各学号之间用一个空格分隔。若不存在，则打印"no"。

 第三行为平均成绩在90分及以上的学生的学号, 各学号之间用一个空格分隔。若不存在，则打印"no"。
【样例输入】3
                        070001 90 80 85 50 42
                        070002 93 95 90 88 92
                        070003 98 92 84 90 91
【样例输出】93.67
                        070001
                        070002 070003
【样例说明】本班有3个学生。

  第1个学生学号为: 070001, 5门课程的成绩分别为: 90、80、85、50、42;

  第2个学生学号为: 070002, 5门课程的成绩分别为: 93、95、90、88、92;

  第3个学生学号为: 070003, 5门课程的成绩分别为: 98、92、84、90、91。

  本班第1门课程的平均成绩为: 93.67; 有2门及2门以上不及格的学生的学号为: 070001; 平均成绩在90分以上的学生的学号为: 070002、070003。
*/
#include<stdio.h>
//结构体 
struct Score{
	char num[10]; 
	int grade[5];
}score[30];

//平均数 
void Avg(struct Score *pscore, int n){
	int i;
	float avg = 0.0;
	for(i = 0; i < n; i++, pscore++){
		avg += (*pscore).grade[0]; 
	}
	printf("%.2f\n", avg / n);
}

//不及格
void NotPass(struct Score *pscore, int n){
	int i, j, sum;
	int flag = 0;
	for(i = 0; i < n; i++, pscore++){
		sum = 0;
		for(j = 0; j < 5; j++){
			if((*pscore).grade[j] < 60){
				sum ++;
			}
		}
		if(sum >= 2){
			flag = 1;
			printf("%s ", (*pscore).num);
		}
	}
	if(flag == 0){
		printf("no");
	}
	printf("\n");
} 

//90分
void Over90(struct Score *pscore, int n){
	int i, j;
	float sum;
	int flag = 0;
	for(i = 0; i < n; i++, pscore++){
		sum = 0.0;
		for(j = 0; j < 5; j++){
			sum += (*pscore).grade[j];
		}
		sum /= 5;
		if(sum >= 90){
			flag = 1;
			printf("%s ", (*pscore).num);
		}
	}
	if(flag == 0){
		printf("no");
	}
	printf("\n");
} 


int main(){
	int N, i, j;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%s", score[i].num);
		for(j = 0; j < 5; j++){
			scanf("%d", &score[i].grade[j]);
		}
	}
	Avg(score, N);
	NotPass(score, N);
	Over90(score, N);
	return 0;
}
