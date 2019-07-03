#include<bits/stdc++.h>
using namespace std;
int n,k;
int f[55][2],g[55][55],h[55];

void dfs(int s,int t,int m)
{
f[s][m-1]++;if(s==50)return;
for(int i=t;s+i<=50;i+=m)dfs(s+i,i+2-m,m);
}

void DFS(int s,int t,int num)
{
g[s][num]++;
if(num==50||s==50)return;
for(int i=t;i+s<=50;i++)DFS(s+i,i,num+1);
}

int main()
{
dfs(0,1,1);DFS(0,1,0);dfs(0,1,2);
while(cin>>n>>k)cout<<g[n][k]<<"\n"<<f[n][0]<<"\n"<<f[n][1]<<"\n";
return 0;
}
