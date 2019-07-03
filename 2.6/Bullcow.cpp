#include <iostream>
using namespace std;
const int M = 100000 + 5;
const int MOD = 5000011;

int f[M][2];

int main()
{
int n, k;
cin>>n>>k;
f[1][1] = f[1][0] = 1;
for(int i = 2; i <= n; i++){
if(i-k-1 >= 1) f[i][1] = (f[i-k-1][0] + f[i-k-1][1]) % MOD;
else f[i][1] = 1;
f[i][0] = (f[i-1][1] + f[i-1][0]) % MOD;
}
cout<<(f[n][1] + f[n][0]) % MOD;
return 0;
}
