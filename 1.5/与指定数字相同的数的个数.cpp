#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,s=0,f;
	cin>>n>>f;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a==f)s++;
	}
	cout<<s;
	return 0;
}
