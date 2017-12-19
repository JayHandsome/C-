/*
����������������������ʹ�õ�������, ���걻����Ϊ�ܱ�4��������ݣ������ܱ�100���������ܱ�400�������������⣬���ǲ������ꡣ���磺1700, 1800, 1900 �� 2100 �������꣬�� 1600, 2000��2400�����ꡣ �����ӹ�Ԫ2000��1��1�տ�ʼ��ȥ��������2000.1.1. ��������������������Ǹ�����һ�������������������ڼ���
��������ʽ��������������У�ÿ�а���һ������������ʾ��2000��1��1�տ�ʼ��ȥ���������������һ����&minus;1, ���ش������Լ���������ݲ��ᳬ��9999��
�������ʽ����ÿ���������������һ�У����а�����Ӧ�����ں����ڼ�����ʽΪ&ldquo;YYYY-MM-DD Day OfWeek&rdquo;, ���� &ldquo;DayOfWeek&rdquo; �����������е�һ���� "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" �� "Saturday&ldquo;��
���������롿1730 
                          1740 
                          1750
                          1751 
                          -1 
�����������2004-09-26 Sunday 
                       2004-10-06 Wednesday 
                       2004-10-16 Saturday 
                       2004-10-17 Sunday
������˵��������ȥ��������1730,���Ӧ��������2004-09-26,ΪSunday�������������������ζ�Ӧ��
*/
#include<stdio.h>
struct Year{
	int year;
	int month;
	int day;
	int week;
};
int Leap(int year); //�ж��Ƿ�Ϊ���� 
void Calculator(int Days); //��������

int main(){
	int Days;
	scanf("%d", &Days);
	while(Days != -1){
		 Calculator(Days);
		 scanf("%d", &Days);
		 
	}
	return 0;
}
void Calculator(int Days){
	struct Year ye;
	char Weekname[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	ye.year = 2000;
	ye.month = 1;
	ye.day = 1;
	ye.week = 6;
	Days --; //��ȥ���� 
	while(Days >= 0){
		if(Leap(ye.year)){
			days[1] = 29; 
		}else{
			days[1] = 28;
		}
		//���� 
		ye.week ++;
		if(ye.week > 7){
			ye.week = 1;
		}
		//���� 
		ye.day ++;
		if(ye.day > days[ye.month - 1]){
			ye.month ++;
			ye.day = 1;
		}
		//���������� 
		if(ye.month > 12){
			ye.month = 1;
			ye.year ++; //����ۼ� 
		}
		//printf("%d-%02d-%02d %s\n", ye.year, ye.month, ye.day, Weekname[ye.week - 1]);
		Days --; //�������� 
	}
	printf("%d-%02d-%02d %s\n", ye.year, ye.month, ye.day, Weekname[ye.week - 1]);
}

int Leap(int year){
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
		return 1; //���� 
	}
	return 0; //������ 
}

