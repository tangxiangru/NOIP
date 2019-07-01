#include<iostream>
#include<cmath>
using namespace std;
int n,m,a[101][101],b[101][101];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
      cin>>a[i][j];
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
      {
            if(i==1||i==n||j==1||j==m)
             b[i][j]=a[i][j];
            else
             {
               double r=((double)a[i][j]+a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1])/5;
             b[i][j]=round(r);
           }
      }
     for(int i=1;i<=n;i++)
      {
           for(int j=1;j<=m;j++)
          cout<<b[i][j]<<' ';
         cout<<endl;
      }
}
