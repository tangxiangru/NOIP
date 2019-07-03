#include "iostream"
#include "algorithm"
using namespace std;
int main()
{
	int n;
	int a[1001];
	int dp[1001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i] = a[i];
	}
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[i] > a[j] && dp[j] + a[i] > dp[i])
				dp[i] = dp[j] + a[i];
	int Max = -1;
	for (int i = 0; i < n; i++) {
		if (dp[i] > Max)
			Max = dp[i];
	}
	cout << Max << endl;
	return 0;
}

