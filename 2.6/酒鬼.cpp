#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<sstream>
#include<map>
#include<stack>
#include<queue>
using namespace std;
int w[701],n,dp[5][1000];
//考虑到一维数组表示状态无法显现当前是第几个连续，于是考虑用二维数组来表示状态
//dp[i][j]表示酒瓶j为连续的第i个时，前j个酒的最大体积
/*
	于是
	dp[3][j] = dp[2][j-1]
	dp[2][j] = w[j] + dp[1][j-1];
	dp[1][j] = w[j] + max(dp[3][j-1],dp[2][j-2],d[1][j-2],dp[3][j-2])
*/
int main(){
    memset(dp, 0, sizeof(dp));
    cin>>n;
    for(int i = 1;i<=n;i++) scanf("%d",&w[i]);
    dp[1][1] = w[1];
    dp[1][2] = w[2];dp[2][2] = w[1]+w[2];
    for(int i = 3;i<=n;i++){
        dp[3][i] = dp[2][i-1];
        dp[2][i] = dp[1][i-1] + w[i];
        int maxnum = max(dp[3][i-1],dp[2][i-2]);
        maxnum = max(dp[3][i-2],maxnum);
        maxnum = max(dp[1][i-2],maxnum);
        dp[1][i] = w[i] + maxnum;
    }
    int ans = -1;
    for(int i = n-2;i<=n;i++)
        for(int j = 1;j<=3;j++) if(dp[j][i]>ans) ans = dp[j][i];
    cout<<ans;
    return 0;
}
 
 
