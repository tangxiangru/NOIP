#include <stdio.h>
#include <math.h>
int chess[9][9],ans[93],sum;
bool u[9],f1[30],f2[30];

void print()
{
int n,i,j,x;
scanf("%d",&n);
for(i=1;i<=n;i++)
{
scanf("%d",&x);
printf("%d\n",ans[x]);
}
}

void calc()
{
int i,j,k=7;
for(i=1;i<=8;i++)
{
for(j=1;j<=8;j++)
if(chess[i][j]) {ans[sum]+=j*pow(10,k);k--;}
}
}

void dfs(int dep)
{
int i;
if(dep>8)
{
sum++;
calc();
}
else
{
for(i=1;i<=8;i++)
{
if((u[i]==false)&&(f1[dep+i]==false)&&(f2[dep-i+8]==false))
{
chess[dep][i]=1;
u[i]=true;
f1[dep+i]=true;
f2[dep-i+8]=true;
dfs(dep+1);
chess[dep][i]=0;
u[i]=false;
f1[dep+i]=false;
f2[dep-i+8]=false;
}
}
}
}

int main()
{
dfs(1);
print();
return 0;
}
