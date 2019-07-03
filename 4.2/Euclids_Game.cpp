#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
int a,b;
while(scanf("%d%d",&a,&b) == 2)
{
if( a == 0 && b == 0)break;
if( a < b)swap(a,b);
int win = 0;
while(b)
{
if( a%b == 0 || a/b >= 2)break;
a = a-b;
swap(a,b);
win ^= 1;
}
if(win == 0)printf("Stan wins\n");
else printf("Ollie wins\n");
}
return 0;
}
