#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define now i&1^1
#define last (i-1)&1^1
#define mod &1^1
const int MOD = 2005;

int f[2][5];

int main()
{
int n = 0, cnt = 0;
while(scanf("%d", &n) != EOF){
f[0][0] = f[0][1] = 1;
for(int i = 0; i <= 3; i++)
f[1][i] = 1;
for(int i = 3; i <= n; i++){
f[now][0] = (f[last][0] + f[last][2]) % MOD;
f[now][1] = f[last][0];
f[now][2] = (f[last][1] + f[last][3]) % MOD;
f[now][3] = f[last][1];
}
printf("%d", (f[n mod][0] + f[n mod][1] + f[n mod][2] + f[n mod][3]) % MOD);
}
return 0;
}
