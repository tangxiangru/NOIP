#include<stdio.h>

int N;

int main()
{
while(scanf("%d",&N)==1&&N)
{
if(N&1) printf("%d\n",N-1);
else printf("No Solution!\n");
}
return 0;
}

