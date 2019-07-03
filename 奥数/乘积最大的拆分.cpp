#include<iostream>
#include<cstdio>
using namespace std;
int a[10000],n,temp,ans=1;
int main()
{
// freopen("data.in","r",stdin);
// freopen("bl.out","w",stdout);
scanf("%d",&n);
a[0]=1;
if(n==1){printf("1");return 0;}
while(n){
a[++temp]=a[temp-1]+1;
if(n-a[temp]>=0) n-=a[temp];
else if(n-a[temp]<0) break;
}
int x=n,y=2;
if(n)temp--;
while(n){
if(a[1]==y&&n-1>=0)
a[temp-(x-(n--))]++;
else x=n,y=a[1];
}
for(int i=1;i<=temp-1;i++)
cout<<a[i]<<" ";
cout<<a[temp];
}
