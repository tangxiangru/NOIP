#include <cstdio>
#include <map>

using namespace std;

map<int, int> V;

int main()
{
int casen = 1;
while (true)
{
int a, b;
scanf("%d%d", &a, &b);
if (a == -1 && b == -1)
{
break;
}
if (a == 0 && b == 0)
{
printf("Case %d is a tree.\n", casen);
casen++;
continue;
}
V.clear();
if (V[a] == 0)
{
V[a] = 1;
}
if (V[b] == 0)
{
V[b] = 2;
}
else
{
V[b]++;
}
while (true)
{
scanf("%d%d", &a, &b);
if (a == 0 && b == 0)
{
break;
}
if (V[a] == 0)
{
V[a] = 1;
}
if (V[b] == 0)
{
V[b] = 2;
}
else
{
V[b]++;
}
}
int ideg0 = 0, ideg1 = 0, cnt = 0;
map<int, int>::iterator it: %d %d\n", it->first, it->second);
if (it->second == 1)
{
ideg0++;
}
else if (it->second == 2)
{
ideg1++;
}
cnt++;
}
if (ideg0 == 1 && ideg1 == cnt - 1)
{
printf("Case %d is a tree.\n", casen);
}
else
{
printf("Case %d is not a tree.\n", casen);
}
casen++;
}
return 0;
}
