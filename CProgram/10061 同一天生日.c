/*
��������������һ����200�˵Ĵ�༶�У�����������������ͬ�ĸ��ʷǳ����ָ���ÿ��ѧ����ѧ�ţ��������գ����ҳ�����������ͬ��ѧ����
��������ʽ����һ��Ϊ����n����ʾ��n��ѧ����n<=200���˺�ÿ�а���һ���ַ����������������ֱ��ʾѧ����ѧ��(�ַ�������Ϊ11λ)�ͳ�����(1<=m<=12)��(1<=d<=31)��ѧ�š��¡���֮����һ���ո�ָ���
�������ʽ����ÿ��������ͬ��ѧ�������һ�У�����ǰ�������ֱ�ʾ�º��գ�������������ڵ��������ѧ����ѧ�ţ����֡�ѧ��֮�䶼��һ���ո�ָ��������е������Ҫ�����ڴ�ǰ�����˳���������������ͬ��ѧ�ţ��������˳�������
���������롿6
                   07101020105 3 15
                   07101020115 4 5
                   07101020118 3 15
                   07101020108 4 5
                   07101020111 4 5
                   07101020121 8 10
�����������3 15 07101020105 07101020118
                    4 5 07101020115 07101020108 07101020111

                    8 10 07101020121
������˵��������������ϡ�
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
