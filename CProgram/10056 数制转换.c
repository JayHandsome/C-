/*
����������������������ͬ���ƷǸ�������ת����2����~16���ƣ�������������long���ܱ��ķ�Χ֮�ڡ�
��ͬ���Ƶı�ʾ����Ϊ(0��1��....��9��A��B��C��D��E��F)��
ע�⣺��ͬ���ƿ��ܲ���ֱ��ת������˽�����ʮ�����ơ�
���Կ��ǲ�ͬ������ʮ���Ƶ�ת������������ʮ����ʵ������������ͬ���Ƶ�ת����
��������ʽ������ֻ��һ�У�������������a��n��b��a��ʾ����n��a����������
b��ʾ����a��������nת����b����������a��b��ʮ������������2=<a��b<=16��
�������ʽ���������һ�У�Ϊת�����b�������������ʱ�ַ���ȫ���ô�д��ʾ��
����0 ��1��...��9��A��B��C��D��E��F����
���������롿15 AAB3 7
�����������210305
������˵����15���Ƶ���AAB3��ת��Ϊ7���ƺ����Ϊ210306��
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	int a, b;
	char in_data[20], out_data[20];
	int length, i, sum = 0;
	int k, remainder; //�������� 
	scanf("%d%s%d", &a, in_data, &b);
	
	length = strlen(in_data);
	for(i = length - 1; i >= 0; i--){ //ת��Ϊ10������ 
		if (in_data[i] >= 'A' && in_data[i] <= 'F') {
			sum = sum + ((in_data[i] - 'A') + 10) * pow(a, length - 1 - i);

		}
		else {
			sum = sum + (in_data[i] - '0') * pow(a, length - 1 - i);

		}
	}
	k = 0;
	for(i = 0; sum != 0; i++){
		remainder = sum % b; //������
		sum = sum / b; //���� 
		if(remainder >= 10){
			out_data[k] = (remainder - 10) + 'A';
		}
		else{
			out_data[k] = remainder + '0';
		}
		k++;
	} 
	for(i = k-1; i >= 0; i--){
		printf("%c", out_data[i]);
	}
	return 0;
}
