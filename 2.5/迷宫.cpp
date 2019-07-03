#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdio>
#include <iomanip>
#include<queue>
#include<cstring>
using namespace std;

int dir[4][2] = {0,1,0,-1,1,0,-1,0};
int c,n,sx,sy,ex,ey;
bool f[105][105],flag;
string g[105];

void dfs(int x,int y)
{
if(x == ex && y == ey)
{
flag = 1;
return;
}
for( int i = 0; i < 4; ++i)
{
int tx = x + dir[i][0];
int ty = y + dir[i][1];
if(tx < 0 || tx >= n || ty < 0 || ty >= n || g[tx][ty] == '#' || f[tx][ty] == 1) continue;
f[tx][ty] = 1;
dfs(tx,ty);
}
}

int main()
{
cin >> c;
while(c--)
{
cin >> n;
flag = 0;
memset(f,0,sizeof(f));
for( int i = 0; i < n; ++i)
cin >> g[i];
cin >> sx >> sy >> ex >> ey;
dfs(sx,sy);
if(g[sx][sy] == '#') flag = 0;
if(flag == 1) cout << "YES" << endl;
else cout << "NO" << endl;
}
return 0;
}
