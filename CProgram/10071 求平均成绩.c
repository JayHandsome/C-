/*
【问题描述】某班期末考试后要统计本班某门课程的平均成绩、最高成绩和最低成绩，你的任务是编程序实现这一功能。 一个班的人数不超过30人，要求实现求最高成绩，最低成绩和平均成绩的功能用一个count函数完成，并用参数返回最高成绩，最低成绩和平均成绩。提示：count函数的声明为：void count(int a[],int n,int *pmax,int *pmin,float *pave) ;
【输入形式】一组测试数据，第一行为一个整数N，表示本班有N个人（N<=30），接下来的N行中每行一个整数，表示一个人的成绩。
【输出形式】输出一行。该行包含三个数，分别是：最高成绩、最低成绩和平均成绩。成绩之间由空格分隔，其中平均成绩为实数，并精确到小数点后两位。
【样例输入】5
                   90 
                   83
                   76
                   85
                   62
【样例输出】90 62 79.20
【样例说明】某班有5个学生，他们的成绩分别是90、83、76、85、62。该班的最高成绩、最低成绩和平均成绩分别为90、62以及79.20。
*/ 
#include<stdio.h>
void count(int a[],int n,int *pmax,int *pmin,float *pave){
	int i;
	*pmax = a[0];
	*pmin = a[0];
	*pave = 0;
	for(i = 0; i < n; i++){
		if(*pmax < a[i]){
			*pmax = a[i];
		}
		if(*pmin > a[i]){
			*pmin = a[i];
		}
		*pave += a[i];
	}
	*pave /= n;
}
int main(){
	int N, score[30], max, min;
	float ave;
	int i;
	scanf("%d", &N); 
	for(i = 0; i < N; i++){
		scanf("%d", &score[i]);
	}
	count(score, N, &max, &min, &ave);
	printf("%d %d %.2f\n", max, min, ave);
	return 0;
} 
