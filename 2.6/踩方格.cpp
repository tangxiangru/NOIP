/*
* 定义：dp[i][0]为第i步向前的方案数，
dp[i][1]为第i步向左或向右的方案数。
* 可以得出状态转移方程：dp[i][0] = dp[i-1][0] + dp[i-1][1];
dp[i][1] = dp[i-1][1] + dp[i-1][0]*2;
* 观察上面的方程可以看出第i步的取值只与第i-1步有关
* 所以我们可以利用滚动数组压缩空间
* 优化后的方程：dp[0] = dp[0] + dp[1];
dp[1] = dp[1] + (原来的dp[0])*2;
* 而此时(原来的dp[0]) == (新的dp[0]) - dp[1];
* 综上，第二个方程应为 dp[1] = dp[0]*2 - dp[1]; //自行体会一下
* 下面是代码^ω^
*/
#include <iostream>
using namespace std;
int dp[2];
int main()
{
int n;
cin >> n;
dp[0] = 1; //可以看成第0步时向前走
dp[1] = 0;
for(int i=1;i<=n;i++)
{
dp[0] = dp[0] + dp[1];
dp[1] = dp[0]*2 - dp[1];
}
cout << dp[0] + dp[1] << endl;
return 0;
}

