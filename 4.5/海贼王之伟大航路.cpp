#include<iostream>
#include<fstream>
#include<climits>
#include<cstring>
using namespace std;
 
int n,mymin = INT_MAX;
int mat[17][17] = {};
int vis[17] = {};
int mint[17] = {};								// 过i的最短时间，预测性剪枝用
 
void dfs(int t, int now, int num)				// t: 当前已用时间, now: 当前选择的节点, num: 已选择的节点
{
	int i;
	if (now==n-1 && num!=n)
	{
		return;
	}
	else if (now==n-1 && num==n)
	{
		mymin = min(mymin, t);
		return;
	}
	if (t>=mymin)
	{
		return;
	}
	int mymint = t;
	for (i=1; i<n; i++)
	{
		if (!vis[i])
		{
			mymint += mint[i];
		}
	}
	if (mymint >= mymin)
	{
		return;
	}
	for (i=1; i<n; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			dfs(t+mat[now][i], i, num+1);
			vis[i] = 0;
		}
	}
}
 
 
int main()
{
#ifndef ONLINE_JUDGE
	ifstream fin ("0405_4979.txt");
	int i,j;
	fin >> n;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			fin >> mat[i][j];
		}
	}
	memset(mint, 10000, sizeof(mint));
	for (j=1; j<n; j++)
	{
		for (i=0; i<n; i++)
		{
			if (i!=j)
			{
				mint[j] = min(mint[j], mat[i][j]);
			}
		}
	}
	fin.close();
	vis[0] = 1;
	dfs(0,0,1);
	cout << mymin;
	return 0;
#endif
#ifdef ONLINE_JUDGE
	int i,j;
	cin >> n;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			cin >> mat[i][j];
		}
	}
	memset(mint, 10000, sizeof(mint));
	for (j=1; j<n; j++)
	{
		for (i=0; i<n; i++)
		{
			if (i!=j)
			{
				mint[j] = min(mint[j], mat[i][j]);
			}
		}
	}
	vis[0] = 1;
	dfs(0,0,1);
	cout << mymin;
	return 0;
#endif
}
