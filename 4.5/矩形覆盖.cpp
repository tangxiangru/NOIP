#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

const int INF = 1000000000;

int n;
int x[16], y[16];
int dp[1 << 16];
int in[2048][2048];
int area[16][16];

void Add(int x, int y, int p[], int & cnt, int state)
{
int tmp = in[x + 1000][y + 1000];
if(tmp == -1 || ((state >> tmp) & 1) == 0)
return;
p[cnt++] = tmp;
}

int solve(int);

int Test(int p[], int cnt, int state)
{
int best = INF;
for(int i = 1; i < 1 << cnt; ++i)
{
int mask = state;
for(int j = 0; j < cnt; j++)
if((i >> j) & 1)
mask ^= 1 << p[j];
int cur = solve(mask);
if(cur < best)
best = cur;
}
return best;
}

int solve(int state)
{
if(state == 0)
return 0;
if(dp[state] != -1)
return dp[state];
int i, j, k;
int p[4], cnt = 0;
for(i = 0; i < n; i++)
if((state >> i) & 1)
break;
p[0] = i;

int best = INF;
for(j = 0; j < n; j++)
{
cnt = 1;
if(i != j && ((state >> j) & 1))
{
p[cnt++] = j;
if(x[i] == x[j])
{
Add(x[i] + 1, y[i], p, cnt, state);
Add(x[j] + 1, y[j], p, cnt, state);
}
else if(y[i] == y[j])
{
Add(x[i], y[i] + 1, p, cnt, state);
Add(x[j], y[j] + 1, p, cnt, state);
}
else
{
Add(x[i], y[j], p, cnt, state);
Add(x[j] ,y[i], p, cnt, state);
}
int cur = area[i][j] + Test(p, cnt, state);
if(cur < best) best = cur;
}
}

return dp[state] = best;
}

int main()
{
int i, j;
while(scanf("%d", &n) && n)
{
memset(in, -1, sizeof(in));
memset(area, 0, sizeof(area));
memset(dp, -1, sizeof(dp));
for(i = 0; i < n; i++)
{
scanf("%d%d", x + i, y + i);
in[x[i] + 1000][y[i] + 1000] = i;
}
for(i = 0; i < n; i++)
for(j = 0; j < n; j++)
{
if(i == j)
continue;
int dx = x[i] - x[j];
int dy = y[i] - y[j];
if(dx && dy)
area[i][j] = abs(dx * dy);
else if(dx)
area[i][j] = abs(dx);
else
area[i][j] = abs(dy);
}

for(i = 0; i < n; i++)
dp[1 << i] = INF;
for(i = 0; i < n; i++)
for(j = i + 1; j < n; j++)
dp[(1 << i) | (1 << j)] = area[i][j];


printf("%d\n", solve((1 << n) - 1));
}

return 0;
}


