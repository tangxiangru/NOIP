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
using namespace std;
int n,m,dist[501][501]={0},x[500],dp[501][501],s[501][501];
int len(int left,int right){
    int x = 0;
    int mid = (left+right)/2;
    for(int i = left;i<=right;i++) x+=dist[i][mid];
    return x;
}
int main(){
    cin>>m>>n;
    memset(dist, 0, sizeof(dist));
    memset(dp, 8, sizeof(dp));
    x[1] = 0;
    for(int i = 1;i<=m-1;i++){
        int t;
        scanf("%d",&t);
        x[i+1] = x[i] + t;//建立坐标轴，第一个节点为原点
    }
    for(int i = 1;i<=m-1;i++)
        for(int j = i+1;j<=m;j++)
            dist[j][i] = dist[i][j] = fabs(x[j] - x[i]); //结点i、j间的距离
    for(int i = 1;i<=m;i++){
        dp[i][1] = s[1][i];
        dp[i][i] = 0;
        for(int j = 1;j<=m;j++) s[i][j] = len(i,j);
    }
    for(int i = 2;i<=m;i++)
        for(int j = 2;j<=n;j++)
            for(int k = 1;k<i;k++)
                dp[i][j] = min(dp[i][j],dp[k][j-1]+s[k+1][i]);
    printf("%d",dp[m][n]);
    return 0;
}
