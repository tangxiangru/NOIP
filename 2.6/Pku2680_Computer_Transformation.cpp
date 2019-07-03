#include <stdio.h>
#include <stdlib.h>
typedef int NUM;
typedef struct tagDATA
{
NUM ZO;// 0 1 的组数
NUM ZZ;// 0 0 的组数
NUM OO;// 1 1 的组数
NUM OZ;// 1 0 的组数
}DATA;
DATA data[1200];
/*
每组 1 0 产生 1组 0 1 ，产生 1组 1 1 ，产生 1组 1 0
每组 0 0 产生 2组 1 1 , 产生 1组 0 1
每组 1 1 产生 2组 0 1 ，产生 1组 1 0
每组 0 1 产生 1组 1 0 ，产生 1组 0 0 ，产生 1组 0 1
*/
int FindAns(void)
{
data[1].ZO = 1;
for(int i=2;i<1100;i++)
{
data[i].OO = data[i-1].ZO;
data[i].OZ = data[i-1].OZ + data[i-1].OO + data[i-1].ZO;
data[i].ZO = data[i-1].OZ + data[i-1].ZZ + data[i-1].OO + data[i-1].ZO;
data[i].ZZ = data[i-1].ZZ;
}
}
int main()
{
FindAns();
for(int n;scanf("%d",&n)!=EOF;)
{
printf("%d\n",data[n].OO);
}
}
