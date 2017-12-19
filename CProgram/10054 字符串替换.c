/*
【问题描述】将一段英文文章中字符串用给定的字符串替换。
【输入形式】输入包括多行，每一行为一段英文文章（长度不超过80）。
以后每行包括2个字符串（长度不超过20），之间由空格分隔，第一个串为原串，第二个串为替换串，
当遇到0 0两个串时表示输入结束，并且此行不需处理。
注意：本题需要考虑原串和替换串的长度不同的三种情况。
情况1：原串的长度大于替换串，如原串为are ，替换串为is。
情况2：原串的长度等于替换串，如原串为h ，替换串为H。
情况3：原串的长度小替换串，如原串为yes ，替换串为your。
【输出形式】输出替换后的文章。
【样例输入】hello how are yes.
                        h H
                        es ou
                        0 0
【样例输出】Hello How are you.
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
					new_str[t] = str[i]; //将str复制给new_str
					t++;
					break;
				}	
				k++; //查找str的下一个 
			}
			if (j == C1) { //ch1完整找到
				for (j = 0; j < C2; j++) {
					new_str[t] = ch2[j]; //将ch2接在new_str后面
					t++;
				}
				i = k - 1;  //让str从匹配结束的地方开始 
			}
		}
		else {
			new_str[t] = str[i]; //将str复制给new_str
			t++;
		}

	}
	new_str[t] = '\0'; //结束标志 
	strcpy(str, new_str);
}

