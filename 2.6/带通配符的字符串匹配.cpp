/*
My convictions will not falter.--Poppy
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int la,lb,s[30][30],i,j,k;
int a[30],b[30];
int s_read(int x[])
{
int t=0;char c=getchar();
while(c==' '||c=='\n') c=getchar();
while(c!=' '&&c!='\n'&&c!=-1) x[++t]=c,c=getchar();
return t;
}
int main()
{
la=s_read(a);
lb=s_read(b);
s[0][0]=1;
for(i=1;i<=la;i++)
{
if(a[i]=='?')
for(j=1;j<=lb;j++)
s[i][j]=max(s[i-1][j-1],s[i][j]);
else if(a[i]=='*')
for(j=0;j<=lb;j++)
//应该是j=0，不然八分，，例如*a* a j=1则输出not matched
for(k=0;k<=j;k++)
s[i][j]=max(s[i-1][k],s[i][j]);
else
for(j=1;j<=lb;j++)
if(a[i]==b[j])
s[i][j]=s[i-1][j-1];
}
if(s[la][lb]) printf("matched\n");
else printf("not matched\n");
}
