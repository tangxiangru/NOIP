#include<iostream>
using namespace std;
int n,m,a[101][101];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
      cin>>a[i][j];
    for(int i=1;i<=m;i++)
     {
          for(int j=1;j<=n;j++)
          cout<<a[j][i]<<' ';
         cout<<endl; 
     }
}
