#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int X[] = {0,-1,0,1};
const int Y[] = {-1,0,1,0};
bool a[51][51][4],vis[51][51];
int n,m,ans = 0,Max = -999999;
struct Queue {
int x,y;
};
queue<Queue> Q;
inline void bfs(int x,int y) {
bool cnt[51][51];
memset(cnt,false,sizeof(cnt));
Q.push((Queue){x,y});
vis[x][y] = true;
cnt[x][y] = true;
while (!Q.empty()) {
Queue now = Q.front(); Q.pop();
for (int i = 0;i < 4;i++)
if (a[now.x][now.y][i]) {
Queue next;
next.x = now.x+X[i];
next.y = now.y+Y[i];
if (next.x <= 0 || next.x > n || next.y <= 0 || next.x > m || vis[next.x][next.y]) continue;
Q.push(next);
vis[next.x][next.y] = true;
cnt[next.x][next.y] = true;
}
}
int sum = 0;
for (int i = 1;i <= n;i++)
for (int j = 1;j <= m;j++)
if (cnt[i][j]) sum++;
Max = max(Max,sum);
}
int main() {
memset(a,true,sizeof(a));
scanf("%d%d",&n,&m);
for (int i = 1;i <= n;i++)
for (int j = 1,x;j <= m;j++) {
scanf("%d",&x);
int t = 0;
while (x) {
a[i][j][t++] = !(x%2);
x /= 2;
}
}
for (int i = 1;i <= n;i++)
for (int j = 1;j <= m;j++)
if (!vis[i][j]) {
bfs(i,j);
ans++;
}
printf("%d\n%d",ans,Max);
return 0;
}
