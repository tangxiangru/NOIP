#include<iostream>
#include<cstdio>
#define MAX 100003
using namespace std;
int n,k;
bool flag[100006];
struct node
{
    int s,w;
}cow[200006];
int abs(int a)
{
    if (a>0) return a;
    else return -a;
}

void bfs()
{
    int head=0,tail=1,i;
    cow[0].s=1;
    cow[1].w=n;
    while (head<tail)
    {
        head++;
        if (cow[head].w*2<=MAX&&!flag[cow[head].w*2]) cow[++tail].w=cow[head].w*2,cow[tail].s=cow[head].s+1,flag[cow[tail].w]=true;
        if (cow[tail].w==k) {printf("%d",cow[tail].s);return;}
        if (cow[head].w+2<=MAX&&!flag[cow[head].w+1]) cow[++tail].w=cow[head].w+1,cow[tail].s=cow[head].s+1,flag[cow[tail].w]=true;
        if (cow[tail].w==k) {printf("%d",cow[tail].s);return;}
        if (cow[head].w-2<=MAX&&!flag[cow[head].w-1]) cow[++tail].w=cow[head].w-1,cow[tail].s=cow[head].s+1,flag[cow[tail].w]=true;
        if (cow[tail].w==k) {printf("%d",cow[tail].s);return;}

    }
}
int main()
{
    int m=0;
    scanf("%d%d",&n,&k);
    if (n==k) {printf("0");return 0;}
    if (n<0&&k<0) {n=abs(n);k=abs(k);}
    else if (n>0&&k<0) {m+=abs(n);k=abs(k);n=0;}
    else if (n<0&&k>0) {m+=abs(n);n=0;}
    bfs(); 
}
