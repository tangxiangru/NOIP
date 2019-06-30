#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
 
const int INF = 1000000000;
int dp[25][25][25] = {};						// 长为i，宽为j的矩形切k刀最大块的面积下界
 
int main()
{
	int w,h,m,i1,i2,i3,i4,i5;
	// 预先把所有可能(1~20)的情况都计算出来
	memset(dp,0x3f,sizeof(dp));
	for (i1=1; i1<=20; i1++)
	{
		for (i2=1; i2<=20; i2++)
		{
			dp[i1][i2][1] = i1*i2;
		}
	}
	for (i1=1; i1<=20; i1++)
	{
		for (i2=1; i2<=20; i2++)
		{
			for (i3=2; i3<=min(20, i1*i2); i3++)
			{
				for (i4=1; i4<i1; i4++)
				{
					for (i5=1; i5<i3; i5++)
					{
						dp[i1][i2][i3] = min(dp[i1][i2][i3], max(dp[i4][i2][i5], dp[i1-i4][i2][i3-i5]));	// 竖着切
					}
				}
				for (i4=1;  i4<i2; i4++)
				{
					for (i5=1; i5<i3; i5++)
					{
						dp[i1][i2][i3] = min(dp[i1][i2][i3], max(dp[i1][i4][i5], dp[i1][i2-i4][i3-i5]));	// 横着切
					}
				}
			}
		}
	}
	// 输入了只要直接O(1)访问输出就行了
	while (cin >> w >> h >> m)
	{
		if (w==0)
		{
			break;
		}
		cout << dp[w][h][m] << endl;
	}
	return 0;
}
