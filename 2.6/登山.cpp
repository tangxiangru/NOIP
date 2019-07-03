#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[1001],p[1001],x[1001],i,maxi=-99999,j;
    cin>>n;
    for(i=1;i<=n;i++)
      cin>>a[i],p[i]=1,x[i]=1;
      for(i=2;i<=n;i++)
         for(j=1;j<i;j++)
           if(a[i]>a[j])
            p[i]=max(p[j]+1,p[i]);
            for(i=n ;i>=1 ;i--)
         for(j=n ;j>i;j--)
         if(a[i]>a[j]&&x[i]<x[j]+1) x[i]=x[j]+1;
      for(i=1;i<=n;i++)
        if(x[i]+p[i]>maxi)
          maxi=p[i]+x[i];
          cout<<maxi-1;
      return 0;
}

