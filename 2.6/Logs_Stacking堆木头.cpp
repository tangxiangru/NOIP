#include <cstdio>
using namespace std;
#define MOD 100000

int T, f[200000 + 5];

int main()
{
scanf("%d", &T);
int a = 1, b = 1, n;
for(int i = 1; i <= 200000; i++)
f[i] = a, a = (a + b)%MOD, b = (a + b)%MOD;
while(T--){
scanf("%d", &n);
printf("%d\n", f[n]);
}
return 0;
}
