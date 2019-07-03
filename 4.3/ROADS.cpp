#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int m,i,n,j,k;
int r,b1,b2,b3,b4,sum;
typedef struct{
int v,len,value,next;
}p;
p a[10005];
int frist[1000];
struct t{
int minlu,value1,num;
friend bool operator <(t p1,t p2)
{
return p1.minlu>p2.minlu;
}
};
int dij(){
int flag=0,e;
priority_queue<t>q;
t pi,pii;
pi.minlu=0;
pi.value1=0;
pi.num=1;
q.push(pi);
while(!q.empty())
{
pi=q.top();
q.pop();
if(pi.num==n)
{
sum=pi.minlu;
flag=1;
return flag;
}
for(e=frist[pi.num];e!=-1;e=a[e].next)
{
if(pi.value1+a[e].value<=r)
{
pii.minlu=pi.minlu+a[e].len;
pii.value1=pi.value1+a[e].value;
pii.num=a[e].v;
q.push(pii);
}
}
}
return flag;
}
int main(){
scanf("%d",&r);
scanf("%d %d",&n,&m);
for(i=1;i<=n;i++)
frist[i]=-1;
for(i=1;i<=m;i++)
{
scanf("%d %d %d %d",&b1,&b2,&b3,&b4);
a[i].v=b2;
a[i].len=b3;
a[i].value=b4;
a[i].next=frist[b1];
frist[b1]=i;
}
if(dij()==1)
printf("%d\n",sum);
else
printf("-1\n");
return 0;
}

