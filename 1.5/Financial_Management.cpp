#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int i;
	float a,sum=0;
	for (i=1;i<=12;++i){cin>>a;sum+=a;}
	printf("$%0.2f\n",sum/12);
	return 0;
}
