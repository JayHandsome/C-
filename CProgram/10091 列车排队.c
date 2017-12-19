/*
�����������������ɽ��г����ᣬÿ�ڳ��ᶼ�й̶��ı�ţ������������վ̨�����һ���г�(�������վ̨˳���복�����޹�)������������ģ����ɵ��г������ֱ�������¹��ܡ�
1�����������ж������ݲ������г�����
2���ú���ʵ�֣�������˳���ӡ�����еĳ���ţ�����֮����һλ�ո�ָ�����
3���ú���ʵ�֣�ͳ�Ƴ�����г��й��ж��ٽڳ��ᡣ
4���ú���ʵ�֣�������˳��������ӡ�����г���š�
��������ʽ������Ϊһ����������ʾ�����ţ����Ϊ����0�������������һ������Ϊ0����ʾ�������ݽ���������0���ǳ����Ų�����
�������ʽ�����Ϊ3 ����������һ��Ϊ������˳������ĸ��ڳ���ı�ţ��ڶ���Ϊ�г����ȣ�������Ϊ������˳�����������ĸ��ڳ���ı�š�
���������롿5 3 8 1 7 10 15 2 0
�����������

5 3 8 1 7 10 15 2 
8
2 15 10 7 1 8 3 5
������˵�������ν�վ�ĳ�����Ϊ��5 3 8 1 7 10 15 2����8�ڳ��᣻������Ϊ��2 15 10 7 1 8 3 5��
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
		p1 = (struct Train *) malloc(len); //���ڴ�λ�ã�0���ᱻ�洢���� 
		scanf("%d", &p1 -> num);
	}
	p2 -> next = NULL; //������־ 
	
	Display(head); //˳���ӡ
	Length(head); //���� 
	ReverseDisplay(head);//�����ӡ 
	close(head);
	close(p1);
	close(p2);
	return 0;
}
