#include<iostream>
using namespace std;
int n,m;
int a[6][6];
int main()
{
    for(int i=1;i<=5;i++) 
      for(int j=1;j<=5;j++) cin>>a[i][j];
    cin>>m>>n;
    for(int i=1;i<=5;i++)
     if(i==m)
      {
          for(int j=1;j<=5;j++) cout<<a[n][j]<<' ';
          cout<<endl;
      }
     else if(i==n) 
      {
           for(int j=1;j<=5;j++) cout<<a[m][j]<<' ';
           cout<<endl;
      }
     else 
      {
           for(int j=1;j<=5;j++) cout<<a[i][j]<<' ';
           cout<<endl;
      }
      
}
