#include<iostream>
#include<cstdio>
using namespace std;
int a[301][501];
int max(int x,int y){return x>y?x:y;}
int main()
{
	a[1][0]=1;
	a[1][1]=1;
	a[2][0]=1;
	a[2][1]=3;
	for(int i=3;i<=300;i++){
		for(int j=1;j<=max(a[i-2][0],a[i-1][0]);j++)
			a[i][j]=a[i-1][j]+a[i-2][j]*2;
		a[i][0]=max(a[i-2][0],a[i-1][0]);
		for(int j=1;j<=a[i][0];j++){			//高精度
			a[i][j+1]+=a[i][j]/10;
			a[i][j]%=10;
		}
		while(a[i][a[i][0]+1]){
			a[i][0]++;
			a[i][a[i][0]+1]+=a[i][a[i][0]]/10;
		}
	}
	int n;
	while(cin>>n){
		if(n==0)
			cout<<1<<endl;
		else{
			for(int i=a[n][0];i>=1;i--)
				cout<<a[n][i];
			cout<<endl;
		}
	}
}
