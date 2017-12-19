/*
������������NֻС����(1 < N < 100)��ÿֻ��ͷ�ϴ���һ������ɫ��ñ�Ӳ�����һ����š����ڳƳ�ÿֻ�����������Ҫ���հ��������Ӵ�С��˳��������ǵı�ź�ͷ��ñ�ӵ���ɫ������ǳ���Ϊ5���ַ������磺&ldquo;W-101&rdquo;,&ldquo;T-002&rdquo;�ȣ�ñ�ӵ���ɫ��&ldquo;red&rdquo;,&ldquo;blue&rdquo;���ַ�������ʾ����ͬ��С������Դ���ͬ��ɫ��ñ�ӡ������������������ʾ��
��������ʽ�������������ı��ļ�IN.TXT�У����ݸ�ʽ�ǣ���һ��Ϊһ������N����ʾС�������Ŀ����������N�У�ÿ����һֻ�������Ϣ����һ��Ϊ��ţ��ڶ���Ϊ������100������������ʾ�����������������Ϊ��ʾ�����ñ����ɫ���ַ������䳤�Ȳ�����10���ַ���
�������ʽ�����հ��������ĴӴ�С˳���������ı�ź�ñ����ɫ���ı��ļ�OUT.TXT�С�
���������롿IN.TXT�ļ�
                   3
                   T-001 30 red
                   W-001 50 blue
                   T-101 40 green                      
�����������OUT.TXT�ļ�
                   W-001 blue
                   T-101 green
                   T-001 red                     
������˵�������������������д�뵽&ldquo;IN.TXT�ļ�&rdquo;�У���ȡ&ldquo;IN.TXT�ļ�&rdquo;�е����ݣ������д��&ldquo;OUT.TXT�ļ�&rdquo;���ٶ�ȡ&ldquo;OUT.TXT�ļ�&rdquo;���ݣ�����ʾ������ʾ�� 
*/
#include<stdio.h>
#include<stdlib.h>

struct Mouse{
		char num[5];
		int quality;
		char color[10];
	};
int main(){
	FILE *in, *out;
	struct Mouse mou[100], temp;
	int N, i, j;
	scanf("%d", &N);
	//д��in.txt�ļ� 
	if((in = fopen("in.txt", "wb")) == NULL){
		printf("can't open file!\n");
		exit(0);
	}
	for(i = 0; i < N; i++){
		scanf("%s%d%s", mou[i].num, &mou[i].quality, mou[i].color);
		fwrite(&mou[i], sizeof(struct Mouse), 1, in);		
	}
	fclose(in);
	//��in.txt����
	if((out = fopen("in.txt", "rb")) == NULL){
		printf("can't open file!\n");
		exit(0);
	}
	for(i = 0; i < N; i++){
		fread(&mou[i], sizeof(struct Mouse), 1, out);
	}
	fclose(out);
	//����д��out.txt�ļ�
	if((in = fopen("out.txt", "wb")) == NULL){
		printf("can't open file!\n");
		exit(0);
	}
	for(i = 0; i < N; i++){
		for(j = 0; j < N - i - 1; j++){
			if(mou[j].quality < mou[j + 1].quality){
				temp = mou[j];
				mou[j] = mou[j + 1];
				mou[j + 1] = temp;
			}
		}
		fwrite(&mou[i], sizeof(struct Mouse), 1, in);		
	}
	fclose(in);
	//��in.txt���� 
	if((out = fopen("out.txt", "rb")) == NULL){
		printf("can't open file!\n");
		exit(0);
	}
	for(i = 0; i < N; i++){
		fread(&mou[i], sizeof(struct Mouse), 1, out);
		printf("%s %s\n", mou[i].num, mou[i].color);		
	}
	fclose(out);
	return 0;
} 
