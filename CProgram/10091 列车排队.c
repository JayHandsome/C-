/*
【问题描述】有若干节列车车厢，每节车厢都有固定的编号，车厢逐个进入站台编组成一列列车(车厢进入站台顺序与车厢编号无关)，请你用链表模拟组成的列车，并分别完成以下功能。
1）在主函数中读入数据并创建列车链表。
2）用函数实现，按输入顺序打印出所有的车厢号（各号之间有一位空格分隔）。
3）用函数实现，统计出组成列车中共有多少节车厢。
4）用函数实现，按输入顺序的逆序打印出所有车厢号。
【输入形式】输入为一行整数，表示车厢编号（编号为大于0的整数），最后一个整数为0，表示输入数据结束，并且0不是车厢编号不处理。
【输出形式】输出为3 行整数，第一行为按输入顺序输出的各节车厢的编号，第二行为列车长度，第三行为按输入顺序的逆序输出的各节车厢的编号。
【样例输入】5 3 8 1 7 10 15 2 0
【样例输出】

5 3 8 1 7 10 15 2 
8
2 15 10 7 1 8 3 5
【样例说明】依次进站的车厢编号为：5 3 8 1 7 10 15 2，共8节车厢；其逆序为：2 15 10 7 1 8 3 5。
*/
#include<stdio.h>
#include<stdlib.h>
#define len sizeof(struct Train)

struct Train{
	int num;
	struct Train *next;
};

void Display(struct Train *head){
	struct Train *p;
	p = head;
	while(p != NULL){ 
		printf("%d ", p -> num);
		p = p -> next;
	}
	printf("\n");
	close(p);
}

void Length(struct Train *head){
	struct Train *p;
	int N = 0;
	p = head;
	while(p != NULL){ 
		N += 1;
		p = p -> next;
	}
	printf("%d\n", N);
	close(p);
}

void ReverseDisplay(struct Train *head){
	struct Train *p, *w1, *w2;
	w1 = (struct Train *) malloc(len);
	w1 -> next = NULL;
	p = head;
	while(p != NULL){ 
		w2 = (struct Train *) malloc(len);
		w1 -> num = p -> num;
		w2 -> next = w1;
		w1 = w2;
		p = p -> next;
	}
	w1 = w1 -> next;
	while(w1 != NULL){ 
		printf("%d ", w1 -> num);
		w1 = w1 -> next;
	}
	printf("\n");
	close(p);
	close(w1);
	close(w2);
}
int main(){
	struct Train *head, *p1, *p2;
	p1 = p2 = (struct Train *) malloc(len);
	scanf("%d", &p1 -> num);
	head = p1;
	
	while(p1 -> num != 0){
		p2 -> next = p1;
		p2 = p1;
		p1 = (struct Train *) malloc(len); //放在此位置，0不会被存储起来 
		scanf("%d", &p1 -> num);
	}
	p2 -> next = NULL; //结束标志 
	
	Display(head); //顺序打印
	Length(head); //长度 
	ReverseDisplay(head);//逆序打印 
	close(head);
	close(p1);
	close(p2);
	return 0;
}
