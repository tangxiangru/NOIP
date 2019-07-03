#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 1000 + 10;

int n;

struct Point{
int x, y;
bool operator < (const Point& a) const{
if(x == a.x) return y < a.y;
return x < a.x;
}
}p[MAXN];

int main()
{
while(scanf("%d", &n) && n){
int ans = 0;
for(int i=1; i<=n; i++)
scanf("%d%d", &p[i].x, &p[i].y);
sort(p+1, p+1+n);
for(int i=1; i<=n; i++)
for(int j=i+1; j<=n; j++){
Point now;
now.x = p[i].x + p[i].y - p[j].y;
now.y = p[i].y + p[j].x - p[i].x;
if(!binary_search(&p[1], &p[1]+n, now)) continue;
now.x = p[j].x + p[i].y - p[j].y;
now.y = p[j].y + p[j].x - p[i].x;
if(!binary_search(&p[1], &p[1]+n, now)) continue;
ans++;
}
printf("%d\n", ans/2);
}
return 0;
}
