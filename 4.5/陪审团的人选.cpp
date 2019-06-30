#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;
 
int n,m;
const int DMAX = 805;
const int BIAS = 400;
const int NMAX = 205;
const int MMAX = 25;
int dp[DMAX][MMAX] = {};// dp[i][j]: 取j个候选人使控辩差为i的方案中使控辩和最大的方案的控辩和,-1表示j个人控辩差不可能达到i
int path[DMAX][MMAX] = {};	// path[i][j] = k: 回溯,dp[i+dif[k]][j]的情况是由于选了第j-1步时选了第path[i][j-1](k)个候选人造成的
int add[NMAX] = {};										// 控辩双方分数之和
int	dif[NMAX] = {};										// 控辩双方分数之差
int sol[MMAX] = {};
 
bool is_valid(int i, int j, int k)					// 当前的dp[i][j+b[k]]是否有效,无效的原因有1. 不是最大值; 2. 使用了已使用过的候选人
{
	if (dp[i][j-1]+add[k] <= dp[i+dif[k]][j])		// dp[i+dif[k]][j]已达到且更大
	{
		return 0;
	}
	while (--j)										// 用path回溯，看k是不是已经使用过
	{
		if (k == path[i][j])						// 如果k在第j步使用过
		{
			return 0;
		}
		i -= dif[path[i][j]];
	}
	return 1;
}
 
 
int main()
{
#ifndef ONLINE_JUDGE
	ifstream fin ("0405_1980.txt");
	int i,a,b,j,k,mysum,mydif,sum1,sum2,cnt=1;
	while (fin >> n >> m)
	{
		if (n==0)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			fin >> a >> b;
			add[i] = a + b;
			dif[i] = a - b;
		}
		memset(dp, 0, sizeof(dp));
		memset(path, 0, sizeof(path));
		for (j=0; j<MMAX; j++)
		{
			for (i=0; i<DMAX; i++)
			{
				dp[i][j] = -1;
			}
		}
		dp[BIAS][0] = 0;
		for (j=1; j<=m; j++)
		{
			for (i=BIAS-20*(j-1); i<=BIAS+20*(j-1); i++)
			{
				if (dp[i][j-1]!=-1)
				{
					for (k=0; k<n; k++)
					{
						if (is_valid(i,j,k))
						{
							dp[i+dif[k]][j] = dp[i][j-1] + add[k];
							path[i+dif[k]][j] = k;
						}
					}
				}
			}
		}
		for (i=0; i<=m*20; i++)				// 从0开始遍历寻找绝对值最小的控辩差
		{
			if (dp[BIAS-i][m]!=-1 && dp[BIAS+i][m]==-1)		// 如果-i是绝对值最小的控辩差
			{
				mydif = -i;									// 总控辩差
				mysum = dp[BIAS-i][m];						// 总控辩和
				break;
			}
			else if (dp[BIAS-i][m]==-1 && dp[BIAS+i][m]!=-1)// 如果+i是绝对值最小的控辩差
			{
				mydif = i;
				mysum = dp[BIAS+i][m];
				break;
			}
			else if (dp[BIAS-i][m]!=-1 && dp[BIAS+i][m]!=-1)// 如果+i/-i都是合理的值
			{
				if (dp[BIAS-i][m]>dp[BIAS+i][m])			// 取控辩和的大者
				{
					mydif = -i;
					mysum = dp[BIAS-i][m];
				}
				else
				{
					mydif = i;
					mysum = dp[BIAS+i][m];
				}
				break;
			}
		}
		j = m;
		i = BIAS+mydif;
		while (j--)
		{
			sol[j] = path[i][j+1];
			i -= dif[path[i][j+1]];
		}
		sort(sol, sol+m);
		sum1 = (mysum + mydif) / 2;							// 控方和
		sum2 = (mysum - mydif) / 2;							// 辩方和
		cout << "Jury #" << (cnt++) << endl;
		cout << "Best jury has value " << sum1 << " for prosecution and value " << sum2 << " for defence: " << endl;
		for (j=0; j<m; j++)
		{
			cout << " " << (sol[j]+1);						// 候选人编号从1开始
		}
		cout << endl << endl;
	}
	fin.close();
#endif
#ifdef ONLINE_JUDGE
	int i,a,b,j,k,mysum,mydif,sum1,sum2,cnt=1;
	while (cin >> n >> m)
	{
		if (n==0)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			cin >> a >> b;
			add[i] = a + b;
			dif[i] = a - b;
		}
		memset(dp, 0, sizeof(dp));
		memset(path, 0, sizeof(path));
		for (j=0; j<MMAX; j++)
		{
			for (i=0; i<DMAX; i++)
			{
				dp[i][j] = -1;
			}
		}
		dp[BIAS][0] = 0;
		for (j=1; j<=m; j++)
		{
			for (i=BIAS-20*(j-1); i<=BIAS+20*(j-1); i++)
			{
				if (dp[i][j-1]!=-1)
				{
					for (k=0; k<n; k++)
					{
						if (is_valid(i,j,k))
						{
							dp[i+dif[k]][j] = dp[i][j-1] + add[k];
							path[i+dif[k]][j] = k;
						}
					}
				}
			}
		}
		for (i=0; i<=m*20; i++)				// 从0开始遍历寻找绝对值最小的控辩差
		{
			if (dp[BIAS-i][m]!=-1 && dp[BIAS+i][m]==-1)		// 如果-i是绝对值最小的控辩差
			{
				mydif = -i;									// 总控辩差
				mysum = dp[BIAS-i][m];						// 总控辩和
				break;
			}
			else if (dp[BIAS-i][m]==-1 && dp[BIAS+i][m]!=-1)// 如果+i是绝对值最小的控辩差
			{
				mydif = i;
				mysum = dp[BIAS+i][m];
				break;
			}
			else if (dp[BIAS-i][m]!=-1 && dp[BIAS+i][m]!=-1)// 如果+i/-i都是合理的值
			{
				if (dp[BIAS-i][m]>dp[BIAS+i][m])			// 取控辩和的大者
				{
					mydif = -i;
					mysum = dp[BIAS-i][m];
				}
				else
				{
					mydif = i;
					mysum = dp[BIAS+i][m];
				}
				break;
			}
		}
		j = m;
		i = BIAS+mydif;
		while (j--)
		{
			sol[j] = path[i][j+1];
			i -= dif[path[i][j+1]];
		}
		sort(sol, sol+m);
		sum1 = (mysum + mydif) / 2;							// 控方和
		sum2 = (mysum - mydif) / 2;							// 辩方和
		cout << "Jury #" << (cnt++) << endl;
		cout << "Best jury has value " << sum1 << " for prosecution and value " << sum2 << " for defence: " << endl;
		for (j=0; j<m; j++)
		{
			cout << " " << (sol[j]+1);						// 候选人编号从1开始
		}
		cout << endl << endl;
	}
#endif
}
