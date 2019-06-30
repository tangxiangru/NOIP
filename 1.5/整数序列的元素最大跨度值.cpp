#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,maxv=-1,minv=100000000;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(maxv<a)maxv=a;
		if(minv>a)minv=a;
	}
	cout<<maxv-minv;
	return 0;
}
