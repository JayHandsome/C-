/*
【问题描述】有N只猴子，从1~N进行编号。它们按照编号的顺时针方向排成一个圆圈，然后从第一只猴子开始报数。第一只猴子报的第一个数字为1，以后每只猴子报的数字都是它们前面猴子所报数字加 1。如果一个猴子报的数字是M，则该猴子出列，下一个猴子重新从1开始报数，直到所有猴子都出列为止，最后一个出列的猴子胜出。 你的任务是对于给定猴子数量和报数上限值M，确定出能够被选作大王的猴子的编号。
【输入形式】第一行为一个整数N，表示测试数据的组数，接下来的N行中每行包含两个整数，第一个数是猴子的个数，第二个数是报数上限值M（M>1）,两数之间由空格分隔。
【输出形式】输出共N行，每行为对应输入行获胜猴子的编号。
【样例输入】2 
                       8 5
                       5 8
【样例输出】3 
                       1
【样例说明】有2组测试数据。
                       第1组有8个猴子，报数上限是5，被选作大王的猴子编号为3；
                       第2组有5个猴子，报数上限是8，被选作大王的猴子编号为1。
*/
#include<stdio.h>
#include<stdlib.h>
#define len sizeof(struct Monkey)
struct Monkey{
	int num;
	struct Monkey *next;
};

void King(int amount, int M){
	struct Monkey *head, *p1, *p2, *previous;
	int sum = 0, i;
	previous = p1 = p2 = (struct Monkey *) malloc(len);
	head = p1;
	for(i = 0; i < amount; i++){
		p1 -> num = i + 1;
		p1 = (struct Monkey *) malloc(len); //为p1开辟新的空间 
		p2 -> next = p1; //p2 -> p1 链接起来 
		previous = p2; //记录最后一个结点 
		p2 = p1; 
	}
	previous -> next = head; //首尾相连 
	
	p2 = head; //让p2重新指向头结点 

/*	while(p2 -> next != head){
		printf("%d\n", p2 -> num);
		p2 = p2 -> next;
	}*/ 
	while(1){
		sum ++;
		if(amount == 1){
			printf("%d\n", p2 -> num);
			break;
		}
		if(sum == M){
			sum = 0;
			//printf("%d\n", p2 -> num);
			previous -> next = p2 -> next; //淘汰当前位置 
			p2 = previous -> next; 
			amount --;
		}
		else{
			previous = p2; //记住当前的位置 
			//printf("%d %d\n", p2 -> num, sum);
			//printf("%d\n", p2 -> num);
			p2 = p2 -> next;
		}
		
	}
	close(head);
	close(p1);
	close(p2);
	close(previous);
}
int main(){
	int n, amount[20], M[20], i;
	scanf("%d", &n); 
	for(i = 0; i < n; i++){
		scanf("%d%d", &amount[i], &M[i]);
		King(amount[i], M[i]);
	}
	return 0;
} 
