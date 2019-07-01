#include<iostream>
using namespace std;
int n,m;
int a[101][101];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
      cin>>a[i][j];
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
      {
           int x;
           cin>>x;
           a[i][j]+=x;
      }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
         cout<<a[i][j]<<' ';
        cout<<endl;
    }
}
