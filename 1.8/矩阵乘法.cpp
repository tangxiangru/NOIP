#include<iostream>
using namespace std;
int n,m,k;
int a[101][101],b[101][101],c[101][101];
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
      cin>>a[i][j];
    for(int i=1;i<=m;i++)
     for(int j=1;j<=k;j++)
      cin>>b[i][j];
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
      for(int l=1;l<=k;l++)
    c[i][l]+=a[i][j]*b[j][l];
    for(int i=1;i<=n;i++)
     {
          for(int j=1;j<=k;j++)
           cout<<c[i][j]<<' ';
         cout<<endl;
     }
}
