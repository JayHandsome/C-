/*
���������������ַ����ȽϹ��̶Ը����������ַ������бȽϣ����������Ϊ0������������Ϊ��Ӧ�����ַ��Ĳ��Ҫ��ʵ�ֶԸ����ַ����ıȽϡ�Ҫ��������ú���ʵ�������ַ����ıȽϡ�int stringcmp(char *str1 ,char *str2 )
��������ʽ����һ��Ϊһ������N����ʾ�������ݵ���������������N����ÿ�а��������ַ������ַ���֮���ɿո�ָ���
�������ʽ�������N�У�ÿ��Ϊ��Ӧ����һ�е������ַ����ıȽϽ����
���������롿3
                    Happy Help
                    Help Help
                    Help Happy
�����������- 4
                    0
                    4
������˵��������3���ַ�������1��Ϊ&ldquo;Happy&rdquo;��"Help",��2��Ϊ&ldquo;Help&rdquo;��&ldquo;Help&rdquo;����3��Ϊ&ldquo;Help&rdquo;��&ldquo;Happy&rdquo;���ȽϽ���ֱ�Ϊ-4��0��4��
*/
#include<stdio.h>
#include<string.h>
int stringcmp(char *str1, char *str2){
	int len_s1, len_s2;
	len_s1 = strlen(str1);
	len_s2 = strlen(str2);
	for(; *str1 != '\0' || *str2 != '\0'; str1++, str2++){
		if(*str1 != *str2){
			return (*str1 - *str2);
		}
	}
	return 0;
}
int main(){
	int N, i;
	char str1[30], str2[30];
	int result;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%s%s", str1, str2);
		result = stringcmp(str1, str2);
		printf("%d\n", result);
	} 
	return 0;
} 
