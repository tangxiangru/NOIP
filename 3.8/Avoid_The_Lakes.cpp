#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

bool graph[105][105];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n, m;

int dfs(int x, int y){
int nx, ny, ans=1;
graph[x][y]=false;
for(int i=0;i<4;i++){
nx=x+dx[i];
ny=y+dy[i];
if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&graph[nx][ny])
ans+=dfs(nx, ny);
}
return ans;
}

int main(){
int k, x, y;
while(scanf("%d%d%d", &n, &m, &k)!=EOF){
memset(graph, false, sizeof(graph));
for(int i=0;i<k;i++){
scanf("%d%d", &x, &y);
graph[x][y]=true;
}
int ans=0;
for(int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
if(graph[i][j])
ans=max(ans, dfs(i, j));
printf("%d\n", ans);
}
return 0;
}
