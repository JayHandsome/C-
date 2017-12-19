/*
【问题描述】N只小白鼠(1 < N < 100)，每只鼠头上戴着一顶有颜色的帽子并且有一个编号。现在称出每只白鼠的重量，要求按照白鼠重量从大到小的顺序输出它们的编号和头上帽子的颜色。编号是长度为5的字符串，如：&ldquo;W-101&rdquo;,&ldquo;T-002&rdquo;等，帽子的颜色用&ldquo;red&rdquo;,&ldquo;blue&rdquo;等字符串来表示。不同的小白鼠可以戴相同颜色的帽子。白鼠的重量用整数表示。
【输入形式】输入数据在文本文件IN.TXT中，数据格式是：第一行为一个整数N，表示小白鼠的数目。接下来的N行，每行是一只白鼠的信息。第一个为编号；第二个为不大于100的正整数，表示白鼠的重量；第三个为表示白鼠的帽子颜色的字符串，其长度不超过10个字符。
【输出形式】按照白鼠重量的从大到小顺序输出白鼠的编号和帽子颜色到文本文件OUT.TXT中。
【样例输入】IN.TXT文件
                   3
                   T-001 30 red
                   W-001 50 blue
                   T-101 40 green                      
【样例输出】OUT.TXT文件
                   W-001 blue
                   T-101 green
                   T-001 red                     
【样例说明】将键盘输入的数据写入到&ldquo;IN.TXT文件&rdquo;中，读取&ldquo;IN.TXT文件&rdquo;中的数据，排序后写入&ldquo;OUT.TXT文件&rdquo;，再读取&ldquo;OUT.TXT文件&rdquo;内容，在显示器上显示。 
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
	//写进in.txt文件 
	if((in = fopen("in.txt", "wb")) == NULL){
		printf("can't open file!\n");
		exit(0);
	}
	for(i = 0; i < N; i++){
		scanf("%s%d%s", mou[i].num, &mou[i].quality, mou[i].color);
		fwrite(&mou[i], sizeof(struct Mouse), 1, in);		
	}
	fclose(in);
	//从in.txt读出
	if((out = fopen("in.txt", "rb")) == NULL){
		printf("can't open file!\n");
		exit(0);
	}
	for(i = 0; i < N; i++){
		fread(&mou[i], sizeof(struct Mouse), 1, out);
	}
	fclose(out);
	//排序，写进out.txt文件
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
	//从in.txt读出 
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
