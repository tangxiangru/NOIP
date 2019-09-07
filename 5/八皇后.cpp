#include <stdio.h>

#define N 8

int column[N];//同栏是否有皇后
int rup[2*N];//右上至左下是否有皇后
int lup[2*N];//左上至右下是否有皇后
int queen[N] = {0};
int num = 0;//解答编号

void backtrack(int i);//递回求解
void print();
int main()
{
    int i;
	for(i = 0; i < N; i++)
		column[i] = 1;

	for(i = 0; i < 2*N; i++)
		rup[i] = lup[i] = 1;
	backtrack(0);
	printf("\n共%d种解答!\n",num);
}

void print()
{
	int x,y;
	printf("\n");
	printf("==========================");
	printf("\n第%d种解答：\n",++num);
	for (y = 0; y < N; y++)
	{
		for (x = 0; x < N; x++)
		{
			if(queen[y] == x)
				printf(" 1 ");
			else
				printf(" 0 ");
		}
		printf("\n");
	}
	printf("==========================");
	printf("\n");
}

void backtrack(int i)
{
    int j;
	if(i == N)
		print();
	else
		for (j=0;j<N;j++)
		{
			if(column[j] == 1 && rup[i+j] == 1 &&lup[i-j+N] == 1)
			{
				queen[i] = j;
                //设定为占用
				column[j] = rup[i+j] = lup[i-j+N] = 0;
				backtrack(i+1);
				column[j] = rup[i+j] = lup[i-j+N] = 1; //在左下角递归完后进行下一个位置的递归运算
			}
		}
}
