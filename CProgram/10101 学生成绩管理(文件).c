/*
������������ѧ���ɼ�����ÿ��ѧ�������ݰ���ѧ�š�������3�ſεĳɼ������ݱ������ļ���(�ڴ���ֻ����һ��ѧ������Ϣ�������д���ļ�)���ֱ������ɸ�����ʵ�����¸�����������ѡ��ִ����Ӧ���ܡ�
                       1) ����ѧ���ɼ���
                       2) ����ѧ�Ż��������ҵ���ѧ������Ϣ��
                       3) ����ѧ�Ż��������޸�ĳѧ������Ϣ��
                       4) �ҳ�ĳ�ſγ̲������ѧ�����������ѧ�źͲ�����γ̵ĳɼ����������ڣ����ӡno��
                       5) ��������ѧ���ĸ���ƽ���ɼ�����ƽ���ɼ���
��������ʽ����һ��Ϊһ������N����ʾѧ��������������N����ÿ�а���5�����ݣ�ѧ��(�ַ���)������(�ַ���)�� 3�ſεĳɼ�(�ɼ�Ϊ����)����N+2��Ϊһ���ַ�������ʾҪ���ҵ�ѧ��ѧ�ţ���N+3��Ϊ6������(������ѧ�š�������3�ſεĳɼ�)����ʾҪ�޸���Ϣ��ѧ�������Լ����޸ĵĸ�ѧ����Ϣ����N+4��Ϊ����(1��2��3)����ʾҪ���ҵ��ǵڼ��ſγ̡�
�������ʽ����1��Ϊ����ѧ�ŵ�ѧ����Ϣ����2��Ϊ�����������Ѿ��޸ĵ�ѧ����Ϣ����3��Ϊָ���γ��в�����ѧ����ѧ���Լ�������γ̵ĳɼ�(����֮���ɿո�ָ�)����4��Ϊ����ѧ���ĸ���ƽ���ɼ�����ƽ���ɼ�(����֮���ɿո�ָ���������λ��Ч����)��
���������롿3
                    070001 ZhangLi   90 80 85
                    070002 WangHua 86 55 90
                    070003 ChenHai   58 42 84
                    070002
                    ChenHai 070003 ChenHai 58 42 90
                    2
�����������070002 WangHua  86  55  90
                    070003 ChenHai 58  42  90
                    070002 55 070003 42
                    78.00 59.00 88.33 75.11
������˵�����������е��������������Ϊ�������ݣ�����Լ��ĳ�����ȷ���
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Student{
	char num[10];
	char name[10];
	int score[3];
}; 
 
int main(){
	FILE *out, *in;
	struct Student std[10], changestd;
	char searchstd[10], updatestd[10];
	int N[2], i, j;
	float sum = 0, per[3] = {0};
	scanf("%d", &N[0]);
	
	if((in = fopen("students.dat", "wb")) == NULL){
		printf("can't open file!\n");
		exit(0);
	}
	
	for(i = 0; i < N[0]; i++){
		scanf("%s%s%d%d%d", std[i].num, std[i].name, &std[i].score[0], &std[i].score[1], &std[i].score[2]);
		if(fwrite(&std[i], sizeof(struct Student), 1, in) != 1){ //fwrite(buffer, size, count, fp)
			printf("file write error \n"); 
		}
	}
	fclose(in); //ָ���������ص� ����ֹ��λ 
	scanf("%s", searchstd);
	scanf("%s%s%s%d%d%d", updatestd, changestd.num, changestd.name, &changestd.score[0], &changestd.score[1], &changestd.score[2]);
	scanf("%d", &N[1]);
	
	if((out = fopen("students.dat", "rb")) == NULL){
		printf("can't open file!\n");
		exit(0);
	}
	for(i = 0; i < N[0]; i++){
		fread(&std[i], sizeof(struct Student), 1, out); //fread(buffer, size, count, fp)
		
		if(strcmp(std[i].num,searchstd) == 0 || strcmp(std[i].name,searchstd) == 0){ //������Ϣ 
			printf("%s %s %d %d %d\n", std[i].num, std[i].name, std[i].score[0], std[i].score[1], std[i].score[2]);
		}	
	}
	if((in = fopen("students.dat", "wb")) == NULL){
		printf("can't open file!\n");
		exit(0);
	}
	rewind(out); //outָ���ļ���ͷ 
	for(i = 0; i < N[0]; i++){
		fread(&std[i], sizeof(struct Student), 1, out); 
		if(strcmp(std[i].num,updatestd) == 0 || strcmp(std[i].name,updatestd) == 0){ //������Ϣ 
			std[i] =  changestd; 
			printf("%s %s %d %d %d\n", std[i].num, std[i].name, std[i].score[0], std[i].score[1], std[i].score[2]);
		}
		fwrite(&std[i], sizeof(struct Student), 1, in);
			
	}
	fclose(in);
	fclose(out);
	
	if((out = fopen("students.dat", "rb")) == NULL){
		printf("can't open file!\n");
		exit(0);
	}
	for(i = 0; i < N[0]; i++){
		fread(&std[i], sizeof(struct Student), 1, out); //fread(buffer, size, count, fp)
		for(j = 0; j < 3; j++){
			sum += std[i].score[j]; //�ܳɼ� 
			per[j] += std[i].score[j]; //ÿ���ܳɼ� 
		}
		if(std[i].score[N[1] - 1] < 60){
			printf("%s %d ", std[i].num, std[i].score[N[1] - 1]);
		}	
	}
	printf("\n");
	fclose(out);
	
	for(j = 0; j < 3; j++){
		per[j] /= N[0];
		printf("%.2f ", per[j]);
	}
	sum /= N[0] * 3;
	printf("%.2f\n", sum);
	return 0;
} 
