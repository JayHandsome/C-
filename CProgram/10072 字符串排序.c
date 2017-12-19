/*
【问题描述】按字典顺序输出某班所有人的名单。
【输入形式】一组测试数据，第一行为一个整数N，表示本班有N个人(N<=30)，接下来的N行中每行一个人名 (人名均由小写字母组成，并且名字长度小于20)。
【输出形式】按字典顺序排列的人员名单。每个人名占一行。
【样例输入】5
                    zhangsan
                    liyang
                    wangxiao
                    liqing
                    wuhui
【样例输出】liqing
                    liyang
                    wangxiao
                    wuhui
                    zhangsan
【样例说明】某班有5个人,名字为zhangsan、liyang、wangxiao、liqing、wuhui,  
                   按字典的排列顺序为：liqing、liyang、wangxiao、wuhui、zhangsan。
*/
#include<stdio.h>
#include<string.h>
void Insert(char *name[], int n){
	int i, j;
	char *temp;
	for(i = 0; i < n; i++){
		for(j = 0; j < n - i - 1; j++){
			if(strcmp(name[j], name[j + 1]) > 0){
				temp = name[j];
				name[j] = name[j + 1];
				name[j + 1] = temp;
			}
		}
	}
}
int main(){
	int N, i;
	char name[30][20];
	char *pname[30];
	scanf("%d", &N);
	getchar();
	for(i = 0; i < N; i++){
		gets(name[i]);
		pname[i] = name[i];
	} 
	
	Insert(pname, N);
	for(i = 0; i < N; i++){
		printf("%s\n", pname[i]);
	}  
	return 0;
}
