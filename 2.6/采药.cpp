#include<iostream>
#include<fstream>
using namespace std;
 
int dp[1005] = {};
 
int main()
{
#ifndef ONLINE_JUDGE
	ifstream fin("0206_1775.txt");
	int t,m,w,d,i,j;
	fin >> t >> m;
	for (i=1; i<=m; i++)
	{
		fin >> w >> d;
		for (j=t; j>=w; j--)					// 一维优化的时候要倒着遍历，这样不会造成覆盖问题
		{
			dp[j] = max(dp[j], dp[j-w]+d);
		}
	}
	fin.close();
	cout << dp[t];
	return 0;
#endif
#ifdef ONLINE_JUDGE
	int t,m,w,d,i,j;
	cin >> t >> m;
	for (i=1; i<=m; i++)
	{
		cin >> w >> d;
		for (j=t; j>=w; j--)					// 一维优化的时候要倒着遍历，这样不会造成覆盖问题
		{
			dp[j] = max(dp[j], dp[j-w]+d);
		}
	}
	cout << dp[t];
#endif
}
