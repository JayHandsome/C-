/*
���������������ֵ�˳�����ĳ�������˵�������
��������ʽ��һ��������ݣ���һ��Ϊһ������N����ʾ������N����(N<=30)����������N����ÿ��һ������ (��������Сд��ĸ��ɣ��������ֳ���С��20)��
�������ʽ�����ֵ�˳�����е���Ա������ÿ������ռһ�С�
���������롿5
                    zhangsan
                    liyang
                    wangxiao
                    liqing
                    wuhui
�����������liqing
                    liyang
                    wangxiao
                    wuhui
                    zhangsan
������˵����ĳ����5����,����Ϊzhangsan��liyang��wangxiao��liqing��wuhui,  
                   ���ֵ������˳��Ϊ��liqing��liyang��wangxiao��wuhui��zhangsan��
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
