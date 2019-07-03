#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int M = 105;
#define check bx<1||by<1||bx>n||by>n

char s[M], map[M][M];
int ans1 = 0, ans2 = 0, flag, n;
int d1[5] = {0, 0, 1, -1};
int d2[5] = {1, -1, 0, 0};
bool vis[M][M];

void dfs(int x, int y, int& tep){
for(int i = 0; i <= 3; i++){
int bx = x + d1[i];
int by = y + d2[i];
if(map[bx][by] == 'B') flag = 1;
else if(map[bx][by] == 'W') flag = 0;
if(vis[bx][by] || check || map[bx][by] != '.') continue;
vis[bx][by] = 1;
dfs(bx, by, ++tep);
}
}

int main()
{
scanf("%d", &n);
for(int i =1; i <= n; i++){
scanf("%s", s);
for(int j = 1; j <= n; j++){
map[i][j] = s[j-1];
if(s[j-1] == 'B') ans1++;
else if(s[j-1] == 'W') ans2++;
}
}
for(int i = 1; i <= n; i++)
for(int j = 1; j <= n; j++)
if(!vis[i][j] && map[i][j] == '.'){
int tep = 0;
dfs(i, j, tep);
if(flag) ans1 += tep; //ans1 is black
else ans2 += tep; //ans2 is white
}
printf("%d %d", ans1, ans2);
return 0;
}
