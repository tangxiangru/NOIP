#include<iostream>
using namespace std;
int a[101][101];
int h[101],l[101];
int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j]; 
    int s=n;    
    for(int k=1;k<=s;k++)
    {
      cout<<a[2][2]<<endl;
      for(int i=1;i<=n;i++) h[i]=a[i][1];
      for(int i=1;i<=n;i++) for(int j=2;j<=n;j++) h[i]=min(h[i],a[i][j]); 
      for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]-=h[i];
      for(int i=1;i<=n;i++) l[i]=a[1][i];
      for(int i=2;i<=n;i++) for(int j=1;j<=n;j++) l[j]=min(l[j],a[i][j]);
      for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]-=l[j];
      if(n>2)
      {
           for(int i=1;i<=n;i++) for(int j=2;j<n;j++)  a[i][j]=a[i][j+1];
         for(int i=2;i<n;i++)  for(int j=1;j<=n;j++) a[i][j]=a[i+1][j];
         n--;
      }
    }
}
