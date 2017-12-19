/*
【问题描述】The digital root of a positive integer is found by summing the digits of the integer. If the resulting value is 
                        a single digit then that digit is the digital root, If the resulting value contains two or more digits,those digits 
                        are summed and the process is repeated.This is continued as long as necessary to obtain a single digit.
                             For example, consider the positive integer 24.  Adding the 2 and the 4 yields a value of 6.  Since 6 is a 
                        single digit, 6 is the digital root of 24. Now consider the positive integer 39.  Adding the 3 and the 9 yields 
                        12, since 12 is not a single digit, the process must be repeated. Adding the 1 and the 2 yeilds 3, a single 
                        digit and also the digital root of 39.
【输入形式】The input file will contain a list of positive integers,one per line.The end of the input will be indicated by an 
                        integer value of zero.
【输出形式】For each integer in the input, output its digital root on a separate line of the output.
【样例输入】24
                        39
                        0
【样例输出】6
                        3
【样例说明】样例如上。
*/
#include<stdio.h>

int Summed(int data){
	int sum = 0, temp;
	temp = data;
	while(temp > 0){
		sum += temp % 10;
		temp = temp / 10;
	}
	if(data % sum == 0){
		return sum;
	}else{
		return Summed(sum); //递归调用，返回最终的值 
	}
} 

int main(){
	int data[10], i = 0, n;
	scanf("%d", &data[0]);
	while(data[i] != 0){
		i++;
		scanf("%d", &data[i]);
	}
	n = i; //数的个数
	for(i = 0; i < n; i++){
		
		printf("%d\n", Summed(data[i])); //函数 
	}
	
	return 0;
}
