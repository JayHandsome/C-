/*
��������������һ��Ӣ���������ַ����ø������ַ����滻��
��������ʽ������������У�ÿһ��Ϊһ��Ӣ�����£����Ȳ�����80����
�Ժ�ÿ�а���2���ַ��������Ȳ�����20����֮���ɿո�ָ�����һ����Ϊԭ�����ڶ�����Ϊ�滻����
������0 0������ʱ��ʾ������������Ҵ��в��账��
ע�⣺������Ҫ����ԭ�����滻���ĳ��Ȳ�ͬ�����������
���1��ԭ���ĳ��ȴ����滻������ԭ��Ϊare ���滻��Ϊis��
���2��ԭ���ĳ��ȵ����滻������ԭ��Ϊh ���滻��ΪH��
���3��ԭ���ĳ���С�滻������ԭ��Ϊyes ���滻��Ϊyour��
�������ʽ������滻������¡�
���������롿hello how are yes.
                        h H
                        es ou
                        0 0
�����������Hello How are you.
*/
#include<stdio.h>
#include<string.h>

void Exchange(char str[], char ch1[], char ch2[]);

int main() {
	char str[80];
	char ch1[20], ch2[20];
	gets(str);
	scanf("%s%s", ch1, ch2);
	while (strcmp(ch1, "0") != 0 && strcmp(ch2, "0") != 0) {
		Exchange(str, ch1, ch2);
		scanf("%s%s", ch1, ch2);
	}
	puts(str);
	return 0;
}

void Exchange(char str[], char ch1[], char ch2[]) {
	int i, j, k, t;
	int S, C1, C2;
	char new_str[80];
	S = strlen(str);
	C1 = strlen(ch1);
	C2 = strlen(ch2);
	t = 0;
	for (i = 0; i < S; i++) {
		if (str[i] == ch1[0]) {
			k = i;
			for (j = 0; j < C1; j++) {
				if (str[k] != ch1[j]){
					new_str[t] = str[i]; //��str���Ƹ�new_str
					t++;
					break;
				}	
				k++; //����str����һ�� 
			}
			if (j == C1) { //ch1�����ҵ�
				for (j = 0; j < C2; j++) {
					new_str[t] = ch2[j]; //��ch2����new_str����
					t++;
				}
				i = k - 1;  //��str��ƥ������ĵط���ʼ 
			}
		}
		else {
			new_str[t] = str[i]; //��str���Ƹ�new_str
			t++;
		}

	}
	new_str[t] = '\0'; //������־ 
	strcpy(str, new_str);
}

