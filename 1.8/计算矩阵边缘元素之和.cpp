#include<iostream>
using namespace std;
int s;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)  
     for(int j=1;j<=m;j++) 
      {
           int x;
           cin>>x;
           if(i==1||i==n||j==1||j==m) s+=x;
      }
    cout<<s;
}
