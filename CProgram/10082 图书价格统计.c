/*
�������������ýṹ���鱣�������Ϣ������N��N<50����ͼ�飬ÿ��ͼ���������������С��30���ַ���)�������磨����С��15���ַ������������������������ۣ�����������Ϣ�������� ����Ϣ�����������ٵ����˳����������������Ϣ��Ȼ�����������Щ����ܷ��á�
��������ʽ����һ��Ϊһ������N����ʾͼ����������������N����ÿ�а���һ�������Ϣ���ݣ�����
 ��֮���ɿո�ָ���
�������ʽ�����ǰN�У�Ϊ��������������������Ϣ����N+1��Ϊ������Щ����ܷ��ã�������С�������λ����
���������롿3
                   C-Programming       qinghu                50    25.50
                   DataStruct              jixiegongye         30    31.55
                   OpratingSystem      gaodengjiaoyu     60    18.30

�����������OpratingSystem      gaodengjiaoyu    60     18.30
                   C-Programming        qinghu               50     25.50
                   DataStruct               jixiegongye        30      31.55
                   3319.50
������˵����(1)��������������Ϣ��Ӣ���Լ�����(�����Ǻ���)��ʾ��
                   (2)���ǰN�еĸ�ʽ�趨Ϊ��"%-30s%-20s%-10d%-.2f\n"��
*/
#include<stdio.h>

struct Books{
	char name[30];
	char publish[15];
	int count;
	float price;
}books[50];

int main(){
	int N, i, j;
	struct Books temp;
	float sum = 0.0;
	scanf("%d", &N); 
	for(i = 0; i < N; i++){
		scanf("%s%s%d%f", books[i].name, books[i].publish, &books[i].count, &books[i].price);
		sum += books[i].count * 1.0 * books[i].price ;
	}
	for(i = 0; i < N; i++){
		for(j = 0; j < N - i - 1; j++){
			if(books[j].price > books[j + 1].price){
				temp = books[j];
				books[j] = books[j + 1];
				books[j + 1] = temp;
			}
		}
		
	}
	
	for(i = 0; i < N; i++){
		printf("%-30s%-20s%-10d%-.2f\n", books[i].name, books[i].publish, books[i].count, books[i].price);
	}
	printf("%.2f\n", sum);
	return 0;
} 
