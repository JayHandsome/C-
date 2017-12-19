/*
【问题描述】在我们现在使用的日历中, 闰年被定义为能被4整除的年份，但是能被100整除而不能被400整除的年是例外，它们不是闰年。例如：1700, 1800, 1900 和 2100 不是闰年，而 1600, 2000和2400是闰年。 给定从公元2000年1月1日开始逝去的天数（2000.1.1. 是星期六），你的任务是给出这一天是哪年哪月哪日星期几。
【输入形式】输入包含若干行，每行包含一个正整数，表示从2000年1月1日开始逝去的天数。输入最后一行是&minus;1, 不必处理。可以假设结果的年份不会超过9999。
【输出形式】对每个测试样例，输出一行，该行包含对应的日期和星期几。格式为&ldquo;YYYY-MM-DD Day OfWeek&rdquo;, 其中 &ldquo;DayOfWeek&rdquo; 必须是下面中的一个： "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" 或 "Saturday&ldquo;。
【样例输入】1730 
                          1740 
                          1750
                          1751 
                          -1 
【样例输出】2004-09-26 Sunday 
                       2004-10-06 Wednesday 
                       2004-10-16 Saturday 
                       2004-10-17 Sunday
【样例说明】若逝去的天数是1730,则对应的日期是2004-09-26,为Sunday。其它天数与日期依次对应。
*/
#include<stdio.h>
struct Year{
	int year;
	int month;
	int day;
	int week;
};
int Leap(int year); //判断是否为闰年 
void Calculator(int Days); //计算日期

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
	Days --; //除去当天 
	while(Days >= 0){
		if(Leap(ye.year)){
			days[1] = 29; 
		}else{
			days[1] = 28;
		}
		//星期 
		ye.week ++;
		if(ye.week > 7){
			ye.week = 1;
		}
		//天数 
		ye.day ++;
		if(ye.day > days[ye.month - 1]){
			ye.month ++;
			ye.day = 1;
		}
		//月数，年数 
		if(ye.month > 12){
			ye.month = 1;
			ye.year ++; //年份累加 
		}
		//printf("%d-%02d-%02d %s\n", ye.year, ye.month, ye.day, Weekname[ye.week - 1]);
		Days --; //天数减少 
	}
	printf("%d-%02d-%02d %s\n", ye.year, ye.month, ye.day, Weekname[ye.week - 1]);
}

int Leap(int year){
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
		return 1; //闰年 
	}
	return 0; //非闰年 
}

