#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 610;
int a[maxn];

int gcd(int m, int n)
{
if(n == 0)
return m;
else
return gcd(n,m % n);
}

int main()
{
int n;
cin >> n;

for(int i = 0; i < n; i++)
cin >> a[i];
sort(a,a+n);
int cnt = 0;
for(int i = 0; i < n - 1; i++) //枚举分子
for(int j = i + 1; j < n; j++) //枚举分母
{
if(gcd(a[i],a[j]) == 1) //不能错写成gcd(i,j)==1
{
//cout << i << " " << j << endl;
cnt++;
}
}
cout << cnt << endl;

return 0;
}
