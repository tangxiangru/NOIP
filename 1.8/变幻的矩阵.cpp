#include<iostream>
#include<cstdlib>
using namespace std;
int n;
char a[11][11],b[11][11],c[11][11];
void case1()
{
    int x=0,y=0;
    for(int i=1;i<=n;i++)
     {
         x++;y=0;
         for(int j=n;j>=1;j--)
           c[x][++y]=a[j][i];
        for(int k=1;k<=n;k++)
         if(c[x][k]!=b[x][k])
           return;
     }
    cout<<'1';
    exit(0);
}
void case2()
{
    int x=0,y=0;
    for(int i=n;i>=1;i--)
     {
         x++;y=0;
         for(int j=1;j<=n;j++)
          c[x][++y]=a[j][i];
         for(int k=1;k<=n;k++)
          if(c[x][k]!=b[x][k])
           return ;
     }
    cout<<'2';
    exit(0);
}
void case3()
{
    int x=0,y=0;
    for(int i=n;i>=1;i--)
     {
         x++;y=0;
         for(int j=n;j>=1;j--)
          c[x][++y]=a[i][j];
         for(int k=1;k<=n;k++)
          if(c[x][k]!=b[x][k])
           return;
     }
    cout<<'3';
    exit(0);
}
void case4()
{
    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
      if(a[i][j]!=b[i][j])
       return;
    cout<<'4';
    exit(0);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
      cin>>a[i][j];
    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
      cin>>b[i][j];
    case1();
    case2();
    case3();
    case4();
    cout<<'5';
    return 0;
}
