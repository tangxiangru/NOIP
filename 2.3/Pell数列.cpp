#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
long long b[1000010];
long long zjf(int n){
	if(n<3)			     //设置边界
		return n;
	if(b[n]==0)					//记忆化递归调用
		b[n]=(2*zjf(n-1)+zjf(n-2))%100000;	//取mod，不让long long数组爆掉，但是为了避免统计错误，就取100000的mod
	return (b[n]%32767);
}
int main()
{
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		cout<<zjf(x)<<endl;
	}
}
