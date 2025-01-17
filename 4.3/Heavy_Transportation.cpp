#include <iostream>
#include <cstdio>
#define MAXV 1010
#define min(a,b) (a<b?a:b)
using namespace std;

int map[MAXV][MAXV],n,m;

int dijkstra(){
int vis[MAXV],d[MAXV],i,j,v;
for(i=1;i<=n;i++){
vis[i]=0;
d[i]=map[1][i]; //这个时候d不代表从1到n的最短路径，而是最大承载量
}
for(i=1;i<=n;i++){
int f=-1;
for(j=1;j<=n;j++)
if(!vis[j] && d[j]>f){
f=d[j];
v=j;
}
vis[v]=1;

for(j=1;j<=n;j++)
if(!vis[j] && d[j]<min(d[v],map[v][j])){
d[j]=min(d[v],map[v][j]);
}
}
return d[n];
}

int main(){
int t,i,j,sum,a,b,c;
scanf("%d",&sum);
for(t=1;t<=sum;t++){
scanf("%d%d",&n,&m);
for(i=0;i<=n;i++)
for(j=0;j<=n;j++)
map[i][j]=0;
for(i=1;i<=m;i++){
scanf("%d%d%d",&a,&b,&c);
map[a][b]=map[b][a]=c;
}
printf("Scenario #%d:\n",t);
printf("%d\n\n",dijkstra());
}
return 0;
}
