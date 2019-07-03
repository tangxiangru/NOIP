#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int d;
	cin>>d;
	for(int i=1;i<=d;i++){
		long long a=1,b=1,c;
		int n;
		cin>>n;
		if(n<3){                //边界
			cout<<1<<endl;
			continue;
		}
		for(int i=1;i<=n-2;i++){//大于等于3的主要处理程序
			c=a+b;
			a=b;
			b=c;
			a=a%100000;
			b=b%100000;
		}
		cout<<(c%1000)<<endl;
	}
}
