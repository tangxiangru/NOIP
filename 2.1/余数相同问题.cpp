#include <cstdio>
int main()
{
int a, b, c;
scanf("%d%d%d", &a, &b, &c);
for (int i = 2; i <= a; i++)
if (a % i == b % i && a % i == c % i && b % i == c % i)
{
printf("%d", i);
break;
}
return 0;
}
