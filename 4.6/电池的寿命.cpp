#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int maxn;
int a[2000];
int sum;
int max(int x,int y) {
return x > y ? x : y;
}
int main()
{
while (cin >> n)
{
sum = 0;
maxn = 0;
for (int i = 0; i < n; i++)
{
cin >> a[i];
maxn = max(maxn,a[i]);
sum += a[i];
}
sum -= maxn;
if (maxn >= sum) printf("%.1f\n",(double)sum);
else printf("%.1f\n",(double)(sum+maxn)/2);
}
return 0;
}
