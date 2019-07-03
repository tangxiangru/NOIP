#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int min(int i,int j)
{
if(i>j)
{
return j;
}
else
{
return i;
}
}
int main()
{
//freopen("chris.in","r",stdin);
//freopen("chris.out","w",stdout);
int n;
int a[100][100];
int f[100][100];
cin>>n;
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
cin>>a[i][j];
}
}
for(int i=1;i<=n;i++)
{
f[1][i]=a[1][i]+f[1][i-1];
f[i][1]=a[i][1]+f[i-1][1];

}
for(int i=2;i<=n;i++)
{
for(int j=2;j<=n;j++)
{
f[i][j]=min(f[i-1][j],f[i][j-1])+a[i][j];
}
}
cout<<f[n][n]<<endl;
//fclose(stdin);
//fclose(stdout);
return 0;
}
