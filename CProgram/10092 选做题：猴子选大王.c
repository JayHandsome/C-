/*
��������������Nֻ���ӣ���1~N���б�š����ǰ��ձ�ŵ�˳ʱ�뷽���ų�һ��ԲȦ��Ȼ��ӵ�һֻ���ӿ�ʼ��������һֻ���ӱ��ĵ�һ������Ϊ1���Ժ�ÿֻ���ӱ������ֶ�������ǰ������������ּ� 1�����һ�����ӱ���������M����ú��ӳ��У���һ���������´�1��ʼ������ֱ�����к��Ӷ�����Ϊֹ�����һ�����еĺ���ʤ���� ��������Ƕ��ڸ������������ͱ�������ֵM��ȷ�����ܹ���ѡ�������ĺ��ӵı�š�
��������ʽ����һ��Ϊһ������N����ʾ�������ݵ���������������N����ÿ�а���������������һ�����Ǻ��ӵĸ������ڶ������Ǳ�������ֵM��M>1��,����֮���ɿո�ָ���
�������ʽ�������N�У�ÿ��Ϊ��Ӧ�����л�ʤ���ӵı�š�
���������롿2 
                       8 5
                       5 8
�����������3 
                       1
������˵������2��������ݡ�
                       ��1����8�����ӣ�����������5����ѡ�������ĺ��ӱ��Ϊ3��
                       ��2����5�����ӣ�����������8����ѡ�������ĺ��ӱ��Ϊ1��
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
		p1 = (struct Monkey *) malloc(len); //Ϊp1�����µĿռ� 
		p2 -> next = p1; //p2 -> p1 �������� 
		previous = p2; //��¼���һ����� 
		p2 = p1; 
	}
	previous -> next = head; //��β���� 
	
	p2 = head; //��p2����ָ��ͷ��� 

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
			previous -> next = p2 -> next; //��̭��ǰλ�� 
			p2 = previous -> next; 
			amount --;
		}
		else{
			previous = p2; //��ס��ǰ��λ�� 
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
