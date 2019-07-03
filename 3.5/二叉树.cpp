#include <stdio.h>
int main(int argc, char *argv[])
{
    int x,y;
    scanf("%d%d",&x,&y);
    while(x!=y)
    {
        if(x>y) x=x/2;
        else y=y/2;
    }
    printf("%d\n",x);
    return 0;
}



#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int a,b,f[2000][30],bj,deep[2000];
int init()
{
bj = log2(1000);
int jz = 1,sy = 1,cs = 1;
for (int i = 1;i <= 1000;i++)
{
f[i][0] = i >> 1;
deep[i] = cs;
sy--;
if (!sy)
{
jz *= 2;
sy = jz;
cs++;
}
}
for (int i = 1;i <= bj;i++)
{
for (int j = 1;j <= 1000;j++)
{
f[j][i] = f[f[j][i - 1]][i - 1];
}
}
}

int lca(int x,int y)
{
if (deep[x] < deep[y]) swap(x,y);
for (int j = bj;j >= 0;j--)
if (deep[x] - (1 << j) >= deep[y]) x = f[x][j];
if (x == y) return y;
for (int j = bj;j >= 0;j--)
if (f[x][j] != f[y][j])
{
x = f[x][j];
y = f[y][j];
}
return f[x][0];
}
int main()
{
scanf("%d%d",&a,&b);
init();
printf("%d\n",lca(a,b));
return 0;
}
