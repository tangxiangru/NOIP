#include<iostream>
using namespace std;
#define MAXN 20+5
int n,t,a[MAXN],cnt;
void dfs(int pos,int sum)
{
if(pos==n+1)
{
if(sum==t)
cnt++;
return;
}
dfs(pos+1,sum+a[pos]);
dfs(pos+1,sum);
}
int main()
{
cin>>n>>t;
for(int i=1;i<=n;i++)
cin>>a[i];
dfs(1,0);
cout<<cnt;
return 0;
}
