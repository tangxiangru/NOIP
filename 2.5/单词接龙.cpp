#include<iostream>
#include<cstring>
using namespace std;
char a[30][30];
int n,l,max1,b[30],c;
void dfs(char d[])
{
int ld=strlen(d),l1,s,j;
for(int i=1;i<=n;i++)
if(b[i])
{
l1=strlen(a[i]);
bool f=1;
for(j=1;j<=ld&&j<l1;j++)
{
f=1;
for(s=0;s<=j-1;s++)
if(d[ld-j+s]!=a[i][s])
f=0;
if(f)
{
b[i]--;
break;
}

}
if(f)
{
char e[30];
memset(e,0,sizeof(e));
for(int t=j;t<l1;t++)
e[t-j]=a[i][t];
c+=l1-j;
if(max1<c)max1=c;
dfs(e);
b[i]++;
c-=l1-j;
}
}
}
int main()
{
cin>>n;
for(int i=1;i<=n;i++)
{
scanf("%s",a[i]);
b[i]=2;
}
c=1;
char e[30];
cin>>e[0];
dfs(e);
cout<<max1;
return 0;
}
