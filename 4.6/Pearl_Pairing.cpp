#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 101000
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
struct KSD
{
int id,x;
bool operator < (const KSD &a)const{return x<a.x;}
KSD(int _id=0,int _x=0):id(_id),x(_x){}
}A,B;
priority_queue<KSD>pq;
int main()
{
// freopen("test.in","r",stdin);
int i,j;
scanf("%d%d",&n,&m);
for(i=1;i<=m;i++)
{
scanf("%d",&j);
pq.push(KSD(i,j));
}
n>>=1;
for(i=1;i<=n;i++)
{
A=pq.top(),pq.pop();
B=pq.top(),pq.pop();
printf("%d %d\n",A.id,B.id);
if(--A.x)pq.push(A);
if(--B.x)pq.push(B);
}
}
