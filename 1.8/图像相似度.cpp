#include<iostream>
#include<cstdio>
using namespace std;
int m,n,a[101][101],s;
int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
     for(int j=1;j<=n;j++)
      cin>>a[i][j];
    for(int i=1;i<=m;i++)
     for(int j=1;j<=n;j++)
      {
             int x;
             cin>>x;
             if(x==a[i][j]) s++;
      }
     double k=(double)s/(n*m);
     k*=100;
     printf("%.2lf",k);
}
