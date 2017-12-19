/*
【问题描述】用结构数组保存书的信息。现有N（N<50）本图书，每本图书包括书名（长度小于30的字符串)、出版社（长度小于15的字符串）、数量（整数）、单价（浮点数）信息，读入书 的信息并按单价由少到多的顺序输出各书的所有信息，然后输出购买这些书的总费用。
【输入形式】第一行为一个整数N，表示图书数量，接下来的N行中每行包含一本书的信息数据，各数
 据之间由空格分隔。
【输出形式】输出前N行，为按单价排序的所有书的信息，第N+1行为购买这些书的总费用（保留到小数点后两位）。
【样例输入】3
                   C-Programming       qinghu                50    25.50
                   DataStruct              jixiegongye         30    31.55
                   OpratingSystem      gaodengjiaoyu     60    18.30

【样例输出】OpratingSystem      gaodengjiaoyu    60     18.30
                   C-Programming        qinghu               50     25.50
                   DataStruct               jixiegongye        30      31.55
                   3319.50
【样例说明】(1)输入的所有书的信息用英文以及数字(不能是汉字)表示。
                   (2)输出前N行的格式设定为："%-30s%-20s%-10d%-.2f\n"。
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
