#include<iostream>
#include<vector>
using namespace std;
 
long long dp[16] = {};					// 只有偶数有解，奇数直接无解(30->16)
 
int main()
{
	int n,mymax = 0,i,j;
	vector<int> in;
	while (cin >> n)
	{
		if (n==-1)
		{
			break;
		}
		if (n%2==0)
		{
			n /= 2;
		}
		else
		{
			n = -1;
		}
		in.push_back(n);
		mymax = max(mymax,n);
	}
	dp[0] = 1;
	dp[1] = 3;
	for (i=2; i<=mymax; i++)
	{
		dp[i] = 3*dp[i-1] + 2;
		if (i>2)
		{
			for (j=2; j<i; j++)
			{
				dp[i] += 2*dp[i-j];
			}
		}
	}
	vector<int>::iterator it;
	for (it=in.begin(); it!=in.end(); it++)
	{
		if (*it==-1)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << dp[*it] << endl;
		}
	}
	return 0;
}
