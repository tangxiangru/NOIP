#include <iostream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 210;
int testCase, N;
int color[MAXN];
int len[MAXN];
int block[MAXN];
int dp[MAXN][MAXN][MAXN];

int solve_dp(int l, int r, int k) {
if(dp[l][r][k])
return dp[l][r][k];
if(l == r)
return dp[l][r][k] =(k+len[r])*(k+len[r]);
// 直接消除
//cout << solve_dp(l, r-1, 0) + (k+len[r])*(k+len[r]) << endl;
dp[l][r][k] = solve_dp(l, r-1, 0) + (k+len[r])*(k+len[r]);
// 先消除中间的, 合并 color[r], 在消除颜色为 r 的
for(int i = l; i < r; i++) {
if(color[i] == color[r])
dp[l][r][k] = max(dp[l][r][k], solve_dp(l, i, k+len[r]) + solve_dp(i+1, r-1, 0));
}
return dp[l][r][k];
}
int main() {

cin >> testCase;
int caseTh = 0;
while(testCase--) {
caseTh++;
cin >> N;
for(int i = 0; i < N ; i ++) {
cin >> block[i];
}
color[0] = block[0];
len[0] = 1;
int cursor = 0;
for(int i = 1; i < N; i ++) {
if(block[i] == block[i-1]) {
len[cursor]++;
}else{
cursor ++;
color[cursor] = block[i];
len[cursor] = 1;
}
}
memset(dp, 0, sizeof(dp));
printf("Case %d: %d\n", caseTh, solve_dp(0, cursor, 0));
}
return 0;
}
