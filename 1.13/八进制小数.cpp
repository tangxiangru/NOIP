#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

char a[1000];
double s=0;

int main()
{
long long len;

scanf("%s",a);

len=strlen(a);

for(int i=len-1; i>=2; i--)
{
s+=a[i]-'0';
s/=8;
}

printf("%s [8] = %.45g [10]",a,s);

return 0;
}
