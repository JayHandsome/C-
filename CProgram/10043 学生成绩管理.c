/*
������������ѧ����Ϣ������ѧ�š���������ѧ�ɼ���Ӣ��ɼ���������ɼ�������N����(N<=10�����ڳ����ڲ����壬
����#define  N 3) ����Ϣ��Ҫ�����ÿ�˵��ܳɼ��������ܳɼ��ɸߵ��͵�˳����������˵���Ϣ�����
������ſγ�ƽ���ɼ�(����2λС��)��������ֻ����3��ѧ�����ǣ�
��������ʽ�������N�У�ÿ��Ϊһ��ѧ����ѧ�š���������ѧ�ɼ���Ӣ��ɼ���������ɼ���Ϣ��
�������ʽ�����ΪN+4�С���һ��Ϊ�̶��ַ�������2~N+1��Ϊ���ܳɼ��ɸߵ���˳���������������Ϣ�����3����
�����ſγ̵�ƽ���ɼ���
Ҫ��1������ĵ�һ�У�ÿ��Ԫ�صĺ����3���ո�&ldquo;Total&rdquo;�󲻼ӿո�
2������ĵڶ��е���N+1�У�ÿ��Ԫ�غ����4���ո����һ��Ԫ�أ���&ldquo;258&rdquo;���治�ӿո�
��ÿ���Իس���������
3��������������û�пո�ÿ�н��Իس���������
���ѣ����ڱ����ʽ�Ƚ��鷳����ͬѧ��ذ��չ涨�������Ȼ��ĳ��򽫻ᱻ�д�
���������롿1001   zhang    90    80    88
1002   huang    78     80    82
1003   xiong    88     85    80
�����������NO   Name   Maths   English   Computer   Total
1001    zhang    90    80    88    258
1003    xiong    88     85    80    253
1002    huang    78    80    82    240
average of Maths:85.33
average of English:81.67
average of Computer:83.33
������˵����ʵ����������Ӧ������������ӣ�
NO��3���ո�Name��3���ո� Maths��3���ո�English��3���ո�Computer��3���ո�Total
1001��4���ո�zhang��4���ո�90��4���ո�80��4���ո�88��4���ո�258
1003��4���ո�xiong��4���ո�88��4���ո�85��4���ո�80��4���ո�253
1002��4���ո�huang��4���ո�78��4���ո�80��4���ո�82��4���ո�240
average of Maths:85.33
average of English:81.67
average of Computer:83.33
*/
#include<stdio.h>
#define N 3
struct Student {
	char No[10];
	char Name[20];
	int Maths;
	int English;
	int Computer;
	int Total;
}stu[20], temp;
int main() {
	int i, j;
	float ave_Math = 0, ave_Eng = 0, ave_Com = 0;
	for (i = 0; i < N; i++) {
		scanf("%s%s%d%d%d", &stu[i].No, &stu[i].Name, &stu[i].Maths, &stu[i].English, &stu[i].Computer);
		stu[i].Total = stu[i].Maths + stu[i].English + stu[i].Computer;
	}
	for (i = 0; i < N; i++) {
		ave_Math = ave_Math + stu[i].Maths;
		ave_Eng = ave_Eng + stu[i].English;
		ave_Com = ave_Com + stu[i].Computer;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < i; j++) {
			if (stu[i].Total > stu[j].Total) {
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}
	ave_Math = ave_Math / N;
	ave_Eng = ave_Eng / N;
	ave_Com = ave_Com / N;
	printf("NO   Name   Maths   English   Computer   Total   \n");
	for (i = 0; i < N; i++) {
		printf("%s    %s    %d    %d    %d    %d\n", stu[i].No, stu[i].Name, stu[i].Maths,
			stu[i].English, stu[i].Computer, stu[i].Total);
	}
	printf("average of Maths:%.2f\n", ave_Math);
	printf("average of English:%.2f\n", ave_Eng);
	printf("average of Computer:%.2f", ave_Com);
	return 0;
}
