#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
 
long long dp[2005][2005] = {};						// 从宿舍跳到第i棵树的第j层一共吃到的柿子数
int mat[2005][2005] = {};							// 每棵树每层的柿子个数
long long hmax[2005] = {};							// max(dp[i][h]), i=1,2,...,n
 
// 动态规划 dp[i][j] = max(dp[i][j+1], hmax[j+d])
//			hmax[h] = max(dp[i][h])
 
int main()
{
#ifndef ONLINE_JUDGE
	ifstream fin ("0405_2454.txt");
	int n,h,d,i,j,hn,tmph;
	long long mymax = 0;
	fin >> n >> h >> d;
	for (i=1; i<=n; i++)
	{
		fin >> hn;
		for (j=1; j<=hn; j++)
		{
			fin >> tmph;
			mat[i][tmph]++;
		}
	}
	fin.close();
	mymax = 0;
	for (i=1; i<=n; i++)								// 初始化树顶
	{
		dp[i][h] = mat[i][h];
		mymax = max(mymax, dp[i][h]);
	}
	hmax[h] = mymax;
	for (j=h-1; j>=0; j--)								// dp[i][j] = max(dp[i][j+1], hmax[j+d]);
	{
		mymax = 0;
		for (i=1; i<=n; i++)
		{
			if (j+d<=h)
			{
				dp[i][j] = mat[i][j] + max(dp[i][j+1], hmax[j+d]);
			}
			else
			{
				dp[i][j] = mat[i][j] + dp[i][j+1];
			}
			mymax = max(mymax, dp[i][j]);
		}
		hmax[j] = mymax;
	}
	mymax = 0;
	for (i=1; i<=n; i++)
	{
		mymax = max(mymax, dp[i][0]);
	}
	cout << mymax;
	return 0;
#endif
#ifdef ONLINE_JUDGE
	int n,h,d,i,j,hn,tmph;
	long long mymax = 0;
	cin >> n >> h >> d;
	for (i=1; i<=n; i++)
	{
		cin >> hn;
		for (j=1; j<=hn; j++)
		{
			cin >> tmph;
			mat[i][tmph]++;
		}
	}
	mymax = 0;
	for (i=1; i<=n; i++)								// 初始化树顶
	{
		dp[i][h] = mat[i][h];
		mymax = max(mymax, dp[i][h]);
	}
	hmax[h] = mymax;
	for (j=h-1; j>=0; j--)								// dp[i][j] = max(dp[i][j+1], hmax[j+d]);
	{
		mymax = 0;
		for (i=1; i<=n; i++)
		{
			if (j+d<=h)
			{
				dp[i][j] = mat[i][j] + max(dp[i][j+1], hmax[j+d]);
			}
			else
			{
				dp[i][j] = mat[i][j] + dp[i][j+1];
			}
			mymax = max(mymax, dp[i][j]);
		}
		hmax[j] = mymax;
	}
	mymax = 0;
	for (i=1; i<=n; i++)
	{
		mymax = max(mymax, dp[i][0]);
	}
	cout << mymax;
	return 0;
#endif
}
