#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100000]={0};
int main()
{
    int n,m;
    cin>>n;
    for (int i=1;i<=n;i++)
     scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    cin>>m;
    for (int i=n;i>=n-m+1;i--)
     cout<<a[i]<<endl;
     //printf("%d ",&a[i]);
  return 0;
} 
