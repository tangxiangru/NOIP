#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long lol;
lol tot;
int n,b,sz[21000];
int main()
{
scanf("%d%d",&n,&b);
for (int i = 1;i <= n;i++) scanf("%d",&sz[i]);
sort (sz + 1,sz + n + 1);
for (int i = n;i >= 1;i--)
{
tot += sz[i];
if (tot >= b)
{
printf("%d\n",n - i + 1);
return 0;
}
}
}
