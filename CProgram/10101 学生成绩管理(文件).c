/*
【问题描述】学生成绩管理，每个学生的数据包括学号、姓名、3门课的成绩，数据保存在文件中(内存中只保留一个学生的信息，处理后写回文件)。分别用若干个函数实现如下各操作，根据选择执行相应功能。
                       1) 输入学生成绩；
                       2) 给出学号或姓名，找到该学生的信息。
                       3) 给出学号或姓名，修改某学生的信息。
                       4) 找出某门课程不及格的学生，并输出其学号和不及格课程的成绩；若不存在，则打印no。
                       5) 给出所有学生的各科平均成绩和总平均成绩。
【输入形式】第一行为一个整数N，表示学生数；接下来的N行中每行包含5个数据：学号(字符串)、姓名(字符串)、 3门课的成绩(成绩为整数)；第N+2行为一个字符串，表示要查找的学生学号；第N+3行为6个数据(姓名、学号、姓名、3门课的成绩)，表示要修改信息的学生姓名以及欲修改的该学生信息；第N+4行为数字(1、2或3)，表示要查找的是第几门课程。
【输出形式】第1行为给定学号的学生信息；第2行为给定姓名的已经修改的学生信息；第3行为指定课程中不及格学生的学号以及不及格课程的成绩(各数之间由空格分隔)；第4行为所有学生的各科平均成绩和总平均成绩(各数之间由空格分隔，保留两位有效数字)。
【样例输入】3
                    070001 ZhangLi   90 80 85
                    070002 WangHua 86 55 90
                    070003 ChenHai   58 42 84
                    070002
                    ChenHai 070003 ChenHai 58 42 90
                    2
【样例输出】070002 WangHua  86  55  90
                    070003 ChenHai 58  42  90
                    070002 55 070003 42
                    78.00 59.00 88.33 75.11
【样例说明】以样例中的输入输出数据作为测试数据，检查自己的程序正确与否。
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Student{
	char num[10];
	char name[10];
	int score[3];
}; 
 
int main(){
	FILE *out, *in;
	struct Student std[10], changestd;
	char searchstd[10], updatestd[10];
	int N[2], i, j;
	float sum = 0, per[3] = {0};
	scanf("%d", &N[0]);
	
	if((in = fopen("students.dat", "wb")) == NULL){
		printf("can't open file!\n");
		exit(0);
	}
	
	for(i = 0; i < N[0]; i++){
		scanf("%s%s%d%d%d", std[i].num, std[i].name, &std[i].score[0], &std[i].score[1], &std[i].score[2]);
		if(fwrite(&std[i], sizeof(struct Student), 1, in) != 1){ //fwrite(buffer, size, count, fp)
			printf("file write error \n"); 
		}
	}
	fclose(in); //指针用完必须关掉 ，防止篡位 
	scanf("%s", searchstd);
	scanf("%s%s%s%d%d%d", updatestd, changestd.num, changestd.name, &changestd.score[0], &changestd.score[1], &changestd.score[2]);
	scanf("%d", &N[1]);
	
	if((out = fopen("students.dat", "rb")) == NULL){
		printf("can't open file!\n");
		exit(0);
	}
	for(i = 0; i < N[0]; i++){
		fread(&std[i], sizeof(struct Student), 1, out); //fread(buffer, size, count, fp)
		
		if(strcmp(std[i].num,searchstd) == 0 || strcmp(std[i].name,searchstd) == 0){ //查找信息 
			printf("%s %s %d %d %d\n", std[i].num, std[i].name, std[i].score[0], std[i].score[1], std[i].score[2]);
		}	
	}
	if((in = fopen("students.dat", "wb")) == NULL){
		printf("can't open file!\n");
		exit(0);
	}
	rewind(out); //out指向文件开头 
	for(i = 0; i < N[0]; i++){
		fread(&std[i], sizeof(struct Student), 1, out); 
		if(strcmp(std[i].num,updatestd) == 0 || strcmp(std[i].name,updatestd) == 0){ //查找信息 
			std[i] =  changestd; 
			printf("%s %s %d %d %d\n", std[i].num, std[i].name, std[i].score[0], std[i].score[1], std[i].score[2]);
		}
		fwrite(&std[i], sizeof(struct Student), 1, in);
			
	}
	fclose(in);
	fclose(out);
	
	if((out = fopen("students.dat", "rb")) == NULL){
		printf("can't open file!\n");
		exit(0);
	}
	for(i = 0; i < N[0]; i++){
		fread(&std[i], sizeof(struct Student), 1, out); //fread(buffer, size, count, fp)
		for(j = 0; j < 3; j++){
			sum += std[i].score[j]; //总成绩 
			per[j] += std[i].score[j]; //每课总成绩 
		}
		if(std[i].score[N[1] - 1] < 60){
			printf("%s %d ", std[i].num, std[i].score[N[1] - 1]);
		}	
	}
	printf("\n");
	fclose(out);
	
	for(j = 0; j < 3; j++){
		per[j] /= N[0];
		printf("%.2f ", per[j]);
	}
	sum /= N[0] * 3;
	printf("%.2f\n", sum);
	return 0;
} 
