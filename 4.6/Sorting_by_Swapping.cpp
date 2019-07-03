#include<iostream>
#include<cstring>
using namespace std;
int ans,n,a[10001];//a数组存放数据，ans为步骤数
int main()
{
int t;
cin>>t;
for(int i=1;i<=t;i++)
{
memset(a,0,sizeof(a));ans=0;
cin>>n;
for(int j=1;j<=n;j++)
{
cin>>a[j];
}
for(int j=1;j<=n;j++)
{
if(a[j]!=j)
{
swap(a[j],a[a[j]]);//将位置不对的数放到正确的位置
ans++;
j--;//可能换过来的数位置也不对，重复操作！！
}
}
cout<<ans<<endl;
}
return 0;
}
